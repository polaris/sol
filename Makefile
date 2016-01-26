CXX = clang

CXXFLAGS = -Wall -Wextra -pedantic -std=c++14 -O3 `libpng-config --cflags`
LDFLAGS = -lstdc++ `libpng-config --ldflags`
INC = -Ilib/eigen

all: bin/sol

bin/sol: obj/main.o obj/Image.o
	@mkdir -p bin
	$(CXX) $(LDFLAGS) $^ -o $@

obj/main.o: src/main.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) $(INC) $^ -c -o $@

obj/Image.o: src/Image.cpp src/Image.h
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) $(INC) $< -c -o $@

.PHONY: clean
clean:
	@rm -rf bin
	@rm -rf obj
