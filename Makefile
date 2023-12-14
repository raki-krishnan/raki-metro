CC = g++
EXECUTABLE = metro
SRCS = $(shell find . -name "*.hpp")


.PHONY: all
all : $(EXECUTABLE)

.PHONY: clean
clean : 
	rm -f $(EXECUTABLE)

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE) : $(SRCS)
	$(CC) -o $@ $^