CC=gcc
LIBS =#-lkernel32 -luser32 -lgdi32 -lopengl32
CFLAGS=-Wall -g
EXE=$(shell basename `pwd`)
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS)

clean:
	-$(RM) $(EXE) $(OBJS) *.o *.exe
run:
	./$(EXE)
	./$(EXE) hi this is cool
	./$(EXE) "I go 3 spaces"
profile:
	../valgrind.sh ./$(EXE)