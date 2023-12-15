CXX = g++
EXECUTABLE = metro
SRCS = $(shell find . -name "*.hpp")
CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic


.PHONY: all
all : $(EXECUTABLE)

.PHONY: clean
clean : 
	rm -f $(EXECUTABLE)

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE) : $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^