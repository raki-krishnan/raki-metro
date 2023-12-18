CXX = g++
EXECUTABLE = metro
SOURCES = main.cpp
HEADERS = metro.hpp metrosolver.hpp
CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

.PHONY: all
all: $(EXECUTABLE)

.PHONY: clean
clean:
	rm -f $(EXECUTABLE)
	rm main.hpp.gch
	

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)
