CC=gcc
LIBS =#-lkernel32 -luser32 -lgdi32 -lopengl32
CFLAGS=-Wall -g
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
EXEC=pointer addressof addressof2

.PHONY: build clean run profile

build: $(OBJS) $(EXEC)

dump-att: build
	@$(foreach EXE, $(EXEC), objdump -M att -D $(EXE) > $(EXE).att.asm;)
#	@$(foreach EXE, $(EXEC), objdump -x86-asm-syntax=att -D $(EXE) > $(EXE).att.asm;)

dump-intel: build
	@$(foreach EXE, $(EXEC), objdump -M intel -D $(EXE) > $(EXE).intel.asm;)
#	@$(foreach EXE, $(EXEC), objdump -x86-asm-syntax=intel -D $(EXE) > $(EXE).intel.asm;)

clean:
	-$(RM) $(EXEC) $(OBJS) *.o *.exe *.asm

run: build
	@$(foreach EXE, $(EXEC), ./$(EXE);)

profile: build
	@$(foreach EXE, $(EXEC), ../valgrind.sh ./$(EXE);)
