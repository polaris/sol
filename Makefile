CXX = clang

bin/sol: src/main.cpp
	@mkdir -p bin
	$(CXX) -Wall -Wextra -pedantic -O3 -std=c++14 -lstdc++ src/main.cpp -Ilib/eigen -o bin/sol

.PHONY: clean
clean:
	@rm -rf bin
	@rm -rf obj