
DIRS  = $(shell ls -p | grep "/")

all:
	@$(foreach DIR, $(DIRS), cd $(DIR) && make all && cd ..;)

clean:
	@$(foreach DIR, $(DIRS), cd $(DIR) && make clean && cd ..;)
