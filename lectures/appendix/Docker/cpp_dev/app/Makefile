BIN		:= app
SRCS	:=	$(wildcard *.cpp)
OBJS	:=	$(SRCS:.cpp=.o)

.PHONY:	all
all:	$(BIN)

$(BIN):	$(OBJS)
	g++ -o $@ $^

%.o:	%.cpp
	g++ -c -o $@ $<

.PHONY: clean
clean:
	rm -d $(BIN) $(OBJS)
