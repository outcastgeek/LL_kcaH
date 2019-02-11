
DIRS  = $(shell ls -p | grep "/")

all:
	@$(foreach DIR, $(DIRS), cd $(DIR) && make build && cd ..;)

run-all:
	@$(foreach DIR, $(DIRS), cd $(DIR) && make run && cd ..;)

clean:
	@$(foreach DIR, $(DIRS), cd $(DIR) && make clean && cd ..;)
