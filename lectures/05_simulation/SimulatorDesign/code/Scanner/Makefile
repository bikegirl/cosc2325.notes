FILES   = $(wildcard *.cpp)
OBJS    = $(FILES:.cpp=.o)
CXX     = g++
CFLAGS  = -c -std=c++11
BIN     = scanner

all:    $(BIN)

$(BIN): $(OBJS)
	    $(CXX) -o $(BIN) $(OBJS)

%.o:    %.cpp
		$(CXX) $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJS) $(BIN)
