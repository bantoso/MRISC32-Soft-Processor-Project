// adder32.sv
module adder32 (
    input  logic [31:0] A,
    input  logic [31:0] B,
    input  logic [1:0]  pack_mode,   // 00=word, 01=half, 10=byte
    output logic [31:0] result
);

    // Lane results
    logic [31:0] word_sum;
    logic [15:0] half_sum_lo, half_sum_hi;
    logic [7:0]  byte_sum0, byte_sum1, byte_sum2, byte_sum3;

    // Word (32-bit)
    assign word_sum = A - B;

    // Half (two 16-bit lanes)
    assign half_sum_lo = A[15:0]  - B[15:0];
    assign half_sum_hi = A[31:16] - B[31:16];

    // Byte (four 8-bit lanes)
    assign byte_sum0 = A[7:0]    - B[7:0];
    assign byte_sum1 = A[15:8]   - B[15:8];
    assign byte_sum2 = A[23:16]  - B[23:16];
    assign byte_sum3 = A[31:24]  - B[31:24];

    // Mode select
    always_comb begin
        result = '0;
        unique case (pack_mode)
            2'b00: result = word_sum;
            2'b01: result = {half_sum_hi, half_sum_lo};
            2'b10: result = {byte_sum3, byte_sum2, byte_sum1, byte_sum0};
            default: result = '0;
        endcase
    end

endmodule
