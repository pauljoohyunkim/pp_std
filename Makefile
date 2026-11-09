INCLUDE=include
CC=clang
CXX=clang++
AR=ar
CFLAGS=-g -Wall -O0 -I$(INCLUDE) -MMD -MP $(CFLAGS_EXTRA)
CXXFLAGS=$(CFLAGS)

SRC=src
OBJ=obj
BIN=bin
TESTS=tests
LIB=$(BIN)/pp_std.a

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
DEPS=$(SRCS:.c=.d)
UNITTEST_SRCS=$(wildcard $(TESTS)/*.cpp)
UNITTEST_OBJS=$(patsubst $(TESTS)/%.cpp,$(OBJ)/unittest_%.o,$(UNITTEST_SRCS))
UNITTEST_DEPS=$(UNITTEST_SRCS:.cpp=.d)
UNITTEST_LDLIBS=$(shell pkg-config --libs gtest 2>/dev/null)

pp_std: $(LIB)
unittest: $(BIN)/unittest

$(LIB): $(OBJS)
	$(AR) rcs $@ $^

$(BIN)/unittest: $(OBJS) $(UNITTEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(UNITTEST_LDLIBS)

$(OBJ)/unittest_%.o: $(TESTS)/%.cpp
	$(CXX) $(CXXFLAGS) -MF $(TESTS)/$*.d -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -MF $(SRC)/$*.d -c $< -o $@

-include $(DEPS) $(UNITTEST_DEPS)

clean:
	$(RM) -f $(OBJ)/*.o $(OBJ)/*.d $(BIN)/pp_std.a $(BIN)/unittest $(DEPS) $(UNITTEST_DEPS)

.PHONY: pp_std unittest clean
