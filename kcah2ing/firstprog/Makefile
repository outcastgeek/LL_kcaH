CC=gcc
LIBS =#-lkernel32 -luser32 -lgdi32 -lopengl32
CFLAGS=-Wall -g
EXE=$(shell basename `pwd`)-exe
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

build: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS)

dump-att: build
	objdump -x86-asm-syntax=att -D $(EXE) > $(EXE).att.asm

dump-intel: build
	objdump -x86-asm-syntax=intel -D $(EXE) > $(EXE).intel.asm

clean:
	-$(RM) $(EXE) $(OBJS) *.o *.exe *.asm

run:
	./$(EXE)

profile:
	../valgrind.sh ./$(EXE)

