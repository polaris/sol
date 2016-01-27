CXX = clang

CXXFLAGS = -Wall -Wextra -pedantic -std=c++14 -O3 `libpng-config --cflags`
LDFLAGS = -lstdc++ `libpng-config --ldflags`
INC = -Ilib/eigen

SOURCE = $(wildcard src/*.cpp)
OBJ = $(addprefix obj/,$(notdir $(SOURCE:.cpp=.o)))

all: bin/sol

bin/sol: $(OBJ)
	@mkdir -p bin
	$(CXX) $(LDFLAGS) $^ -o $@

obj/main.o: src/main.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) $(INC) $^ -c -o $@

obj/%.o: src/%.cpp src/%.h
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) $(INC) $< -c -o $@

.PHONY: clean
clean:
	@rm -rf bin
	@rm -rf obj
