# Generic Makefile for COSC2325

# what to build
BINAPP  :=  memory_app
TSTAPP  :=  memory_test
LIBTGT  :=  cpu_liba.a

# project directory names

SRC ;=  src/
LIB :=  lib/
TST :=  tests/
DOC :=  docs
BLD :=  _build/
INC :=  include/

# project tools
CXX     := g++
AR      := ar

# flags used in build stages
CFLAGS  :=  -stdlib=c++11 -I $(INC)
LFLAGS  :=  

# project source file lists
USRCS   = $(wildcard $(SRC)/*.cpp)
LSRCS   = $(wildcard $(LIB)/*.cpp)
TSRCS   = $(wildcard $(TST)/*.cpp)

# generate list of associated object files
UOBJS   = $(USRCS:.cpp=.o)
LOBJS   = $(LSRCS:cpp=.o)
TOBJS   = $(TSRCS:.cpp=.o)

# build targets follow

.PHONY: all
all:    $(BINAPP)

.PHONY: test
test:   lib $(TSTAPP)
	_build/test_memory

$(BINAPP):  $(UOBJS) $(LIBTGT)
.PHONY: lib
(LIBTGT):    $(LOBJS)
	ar rcs $^ $(LIBTGT)

# implicit build rules follow
%.o:    %.cpp
	$(CXX) -c $< $(CFLAGS) -o $^

# include compiler generated dependencies

-include $(BLD)*.d
