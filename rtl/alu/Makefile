SIM ?= verilator
TOPLEVEL_LANG ?= verilog
EXTRA_ARGS += --sv --trace

VERILOG_SOURCES = $(PWD)/adder32.sv
TOPLEVEL = adder32
MODULE  = tb_adder32

export PYTHONPATH := $(PWD):$(HOME)/hdl_ws/projects/mrisc32_core/sim:$(HOME)/hdl_ws/common_lib/py

# NEW: do not let PYTHONHOME leak
unexport PYTHONHOME
# NEW: use your conda interpreter for verilator_includer
PYTHON3 := env -u PYTHONHOME $(CONDA_PREFIX)/bin/python

include $(shell cocotb-config --makefiles)/Makefile.sim
