COMPILER=g++
OPTIONS= -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -std=c++17
DEBUG= -O0 -ggdb
RELEASE= -O2 -DNDEBUG

SRC_DIR=source
HDR_DIR=include
OBJ_DIR=object
BIN_DIR=binary

SRC_EXT=.cpp
OBJ_EXT=.o

SOURCES=$(wildcard $(SRC_DIR)/*)
HEADERS=$(wildcard $(HDR_DIR)/*)
OBJECTS=$(patsubst %$(SRC_EXT), %$(OBJ_EXT), $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SOURCES)))

$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT) $(HEADERS)
	$(COMPILER) $(DEBUG) $(OPTIONS) -c $< -o $@

debug: $(OBJECTS)
	$(COMPILER) $(DEBUG) $(OBJECTS) -o $(BIN_DIR)/debug

release: $(OBJECTS)
	$(COMPILER) $(RELEASE) $(OBJECTS) -o $(BIN_DIR)/release

clear:
	rm $(BIN_DIR)/* -f
	rm $(OBJ_DIR)/* -f
