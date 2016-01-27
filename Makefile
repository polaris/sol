CXX = clang

CXXFLAGS = -Wall -Wextra -pedantic -std=c++14 -O3 `libpng-config --cflags`
LDFLAGS = -lstdc++ `libpng-config --ldflags`
INC = -Ilib/eigen

SOURCE = $(wildcard src/*.cpp)
OBJ = $(addprefix obj/,$(notdir $(SOURCE:.cpp=.o)))

GTEST_DIR = lib/googletest/googletest
GMOCK_DIR = lib/googletest/googlemock

all: bin/sol bin/libgmock.a

bin/sol: $(OBJ)
	@mkdir -p bin
	$(CXX) $(LDFLAGS) $^ -o $@

obj/main.o: src/main.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) $(INC) $^ -c -o $@

obj/%.o: src/%.cpp src/%.h
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) $(INC) $< -c -o $@

obj/gtest-all.o: ${GTEST_DIR}/src/gtest-all.cc
	$(CXX) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} -pthread -c $^ -o $@
obj/gmock-all.o: ${GMOCK_DIR}/src/gmock-all.cc
	$(CXX) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} -pthread -c $^ -o $@
bin/libgmock.a: obj/gtest-all.o obj/gmock-all.o
	ar -rc $@ $^

.PHONY: clean
clean:
	@rm -rf bin
	@rm -rf obj
