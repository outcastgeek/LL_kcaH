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
#	./$(EXE)
#	./$(EXE) db.dat c
#	./$(EXE) db.dat s 1 zed zed@zedshaw.com
#	./$(EXE) db.dat s 2 frank frank@zedshaw.com
#	./$(EXE) db.dat s 3 joe joe@zedshaw.com
#	./$(EXE) db.dat l
#	./$(EXE) db.dat d 3
#	./$(EXE) db.dat l
	./$(EXE) db.dat g 2
profile:
	../valgrind.sh ./$(EXE)
