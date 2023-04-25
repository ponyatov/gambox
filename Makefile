# var
MODULE  = $(notdir $(CURDIR))
module  = $(shell echo $(MODULE) | tr A-Z a-z)
OS      = $(shell uname -o|tr / _)
NOW     = $(shell date +%d%m%y)
REL     = $(shell git rev-parse --short=4 HEAD)
BRANCH  = $(shell git rev-parse --abbrev-ref HEAD)
CORES  ?= $(shell grep processor /proc/cpuinfo | wc -l)

# version

# dirs
CWD = $(CURDIR)
BIN = $(CWD)/bin
DOC = $(CWD)/doc
SRC = $(CWD)/src
TMP = $(CWD)/tmp

# tool
CURL   = curl -L -o
CF     = clang-format

# src
C  += $(shell find src -type f -regex .+.c.*$$)
H  += $(shell find inc -type f -regex .+.h.*$$)
SS += src/$(MODULE).lex src/$(MODULE).yacc
SS += $(C) $(H) CMakeLists.txt
S  += $(SS)
CP += tmp/$(MODULE).parser.cpp tmp/$(MODULE).lexer.cpp
HP += tmp/$(MODULE).parser.hpp
F  += lib/$(MODULE).ini
S  += $(F)

# all
.PHONY: all
all: $(BIN)/$(MODULE) $(F)
	$^

# rule
$(BIN)/$(MODULE): $(S) $(TMP)/$(MODULE)/Makefile
	$(MAKE) -C $(TMP)/$(MODULE)

$(TMP)/$(MODULE)/Makefile: $(S)
	cmake -B $(TMP)/$(MODULE) -S $(CWD) \
		-DAPP=$(MODULE) -DEXECUTABLE_OUTPUT_PATH=$(BIN)

# doc

.PHONY: doxy
doxy: .doxygen
	rm -rf docs ; doxygen $< 1>/dev/null

.PHONY: doc
doc:

files:
	echo '#include "${MODULE}.hpp"' >> src/$(MODULE).cpp
	echo '#include "${MODULE}.hpp"' >> src/main.cpp
	echo '#include "${MODULE}.hpp"' >> src/skelex.cpp
	echo '#include "${MODULE}.hpp"' >> src/Object.cpp
	echo '#include "${MODULE}.hpp"' >> src/Primitive.cpp
	echo '#include "${MODULE}.hpp"' >> src/Container.cpp
	echo '#include "${MODULE}.hpp"' >> src/Active.cpp
	echo '#include "${MODULE}.hpp"' >> src/GUI.cpp
