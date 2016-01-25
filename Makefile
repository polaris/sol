bin/sol: src/main.cpp
	@mkdir bin
	$(CC) -Wall -Wextra -pedantic -O3 -std=c++14 -lstdc++ src/main.cpp -o bin/sol

.PHONY: clean
clean:
	@rm -rf bin
	@rm -rf obj