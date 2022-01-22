# COMPILER INFO
CC_CPP := g++
FLG := -g -Wall

SRC_PATH := src/

BIN_PATH := bin/
BIN := main.bin test_element.bin test_replace.bin
BINS:= $(patsubst %.bin,$(BIN_PATH)%.bin,$(BIN))

LIB_PATH := lib/
OBJ_PATH := obj/

LIBS_CPP := $(wildcard $(LIB_PATH)*.cpp)
LIBS_OBJ_CPP := $(patsubst $(LIB_PATH)%.cpp,$(OBJ_PATH)%.o,$(LIBS_CPP))

$(OBJ_PATH)%.o : $(LIB_PATH)%.cpp
	$(CC_CPP) $(FLG) -c $< -o $@

all : $(BINS) 

$(BIN_PATH)%.bin : $(SRC_PATH)%.cpp $(LIBS_OBJ_CPP)
	$(CC_CPP) $(FLG) -o $@ $^ -I $(LIB_PATH)

lib : $(LIBS_OBJ_CPP)
	@echo Building Libraries
clean:
	rm -rf bin/* obj/*
