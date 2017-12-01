
DIRS  = $(shell ls -p | grep "/")

all:
	@$(foreach DIR, $(DIRS), cd $(DIR) && make build && cd ..;)

clean:
	@$(foreach DIR, $(DIRS), cd $(DIR) && make clean && cd ..;)
