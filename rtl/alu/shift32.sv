// shift32.sv — MRISC32 bit-field & shift unit with packed modes
// Ops supported: MKBF(LSL), EBFU(LSR), EBF(ASR), IBF (insert)
//
// Control field layout expected (per lane):
//  WORD (W=32):  O = ctrl[4:0],   M = ctrl[12:8]   (M=0 => W)
//  HALF (W=16):  O0=ctrl[3:0],    M0=ctrl[12:8];   O1=ctrl[19:16], M1=ctrl[28:24]
//  BYTE (W=8):   O0=ctrl[2:0],    M0=ctrl[7:4];    O1=ctrl[10:8],  M1=ctrl[15:12]
//                O2=ctrl[18:16],  M2=ctrl[23:20];  O3=ctrl[26:24], M3=ctrl[31:28]
//
// Notes:
//  - M==0 means "full lane width".
//  - M is clamped so O+M <= W.
//  - ASR (EBF) sign-fills outside the masked field when the extracted field's MSB is 1.
//  - IBF merges shifted source into DST within mask; other ops ignore DST.

module shift32 (
    input  logic [7:0]  i_op,         // opcode (set encodings below)
    input  logic [31:0] i_src,
    input  logic [31:0] i_ctrl,
    input  logic [31:0] i_dst,
    input  logic [1:0]  i_pack_mode,  // 00=word, 01=half, 10=byte
    output logic [31:0] o_result
);

    // --- Adjust these to match your alu_pkg.sv encodings ---
    localparam logic [7:0] ALU_LSL = 8'd21; // MKBF
    localparam logic [7:0] ALU_LSR = 8'd20; // EBFU
    localparam logic [7:0] ALU_ASR = 8'd19; // EBF
    localparam logic [7:0] ALU_IBF = 8'd99; // IBF (choose value used by your decoder)

    // Decode to internal controls
    logic is_right, is_arith, is_insert;
    always_comb begin
        is_right  = 1'b0;
        is_arith  = 1'b0;
        is_insert = 1'b0;
        unique case (i_op)
            ALU_LSL: begin /* MKBF */ end
            ALU_LSR: begin /* EBFU */ is_right = 1'b1; end
            ALU_ASR: begin /* EBF  */ is_right = 1'b1; is_arith = 1'b1; end
            ALU_IBF: begin /* IBF  */ is_insert = 1'b1; end
            default: ;
        endcase
    end

    // ---------------- Lane helpers (fixed widths) ----------------

    // 32-bit lane
    function automatic logic [31:0] bitfield_word (
        input logic [31:0] a, ctrl, dst,
        input logic is_right, is_arith, is_insert
    );
        int O; int M;
        logic [31:0] mask, shifted, res;
        logic        sign;
        begin
            O = ctrl[4:0];
            M = ctrl[12:8];
            if (M == 0) M = 32;
            if (O + M > 32) M = 32 - O;

            mask = (M == 32) ? 32'hFFFF_FFFF : (((32'h1 << M) - 1) << O);

            if (is_right) begin
                if (is_arith) shifted = $signed(a) >>> O;
                else          shifted = a >> O;
            end else begin
                shifted = a << O;
            end

            if (is_insert) begin
                res = (shifted & mask) | (dst & ~mask);
            end else if (is_right && is_arith) begin
                // sign bit of extracted field is at (O+M-1) within the lane
                sign = a[O+M-1];
                res  = (shifted & mask) | (sign ? ~mask : '0);
            end else begin
                res = shifted & mask;
            end

            return res;
        end
    endfunction

    // 16-bit lane
    function automatic logic [15:0] bitfield_half (
        input logic [15:0] a, ctrl, dst,
        input logic is_right, is_arith, is_insert
    );
        int O; int M;
        logic [15:0] mask, shifted, res;
        logic        sign;
        begin
            O = ctrl[3:0];
            M = ctrl[12:8];
            if (M == 0) M = 16;
            if (O + M > 16) M = 16 - O;

            mask = (M == 16) ? 16'hFFFF : (((16'h1 << M) - 1) << O);

            if (is_right) begin
                if (is_arith) shifted = $signed(a) >>> O;
                else          shifted = a >> O;
            end else begin
                shifted = a << O;
            end

            if (is_insert) begin
                res = (shifted & mask) | (dst & ~mask);
            end else if (is_right && is_arith) begin
                sign = a[O+M-1];
                res  = (shifted & mask) | (sign ? ~mask : '0);
            end else begin
                res = shifted & mask;
            end

            return res;
        end
    endfunction

    // 8-bit lane
    function automatic logic [7:0] bitfield_byte (
        input logic [7:0] a, ctrl, dst,
        input logic is_right, is_arith, is_insert
    );
        int O; int M;
        logic [7:0] mask, shifted, res;
        logic       sign;
        begin
            O = ctrl[2:0];
            M = ctrl[7:4];
            if (M == 0) M = 8;
            if (O + M > 8) M = 8 - O;

            mask = (M == 8) ? 8'hFF : (((8'h1 << M) - 1) << O);

            if (is_right) begin
                if (is_arith) shifted = $signed(a) >>> O;
                else          shifted = a >> O;
            end else begin
                shifted = a << O;
            end

            if (is_insert) begin
                res = (shifted & mask) | (dst & ~mask);
            end else if (is_right && is_arith) begin
                sign = a[O+M-1];
                res  = (shifted & mask) | (sign ? ~mask : '0);
            end else begin
                res = shifted & mask;
            end

            return res;
        end
    endfunction

    // ---------------- Pack-mode dispatch ----------------
    always_comb begin
        o_result = '0;
        unique case (i_pack_mode)
            2'b00: begin // WORD
                o_result = bitfield_word(i_src, i_ctrl, i_dst, is_right, is_arith, is_insert);
            end
            2'b01: begin // HALF (two lanes)
                o_result[15:0]  = bitfield_half(i_src[15:0],   i_ctrl[15:0],   i_dst[15:0],
                                                is_right, is_arith, is_insert);
                o_result[31:16] = bitfield_half(i_src[31:16],  i_ctrl[31:16],  i_dst[31:16],
                                                is_right, is_arith, is_insert);
            end
            2'b10: begin // BYTE (four lanes)
                o_result[7:0]    = bitfield_byte(i_src[7:0],    i_ctrl[7:0],    i_dst[7:0],
                                                 is_right, is_arith, is_insert);
                o_result[15:8]   = bitfield_byte(i_src[15:8],   i_ctrl[15:8],   i_dst[15:8],
                                                 is_right, is_arith, is_insert);
                o_result[23:16]  = bitfield_byte(i_src[23:16],  i_ctrl[23:16],  i_dst[23:16],
                                                 is_right, is_arith, is_insert);
                o_result[31:24]  = bitfield_byte(i_src[31:24],  i_ctrl[31:24],  i_dst[31:24],
                                                 is_right, is_arith, is_insert);
            end
            default: o_result = '0;
        endcase
    end

endmodule
