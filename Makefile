# COMPILER INFO
CC_CPP := g++
FLG := -g -Wall

MAIN_SRC_PATH := src/
MAIN_BIN_PATH := bin/
MAIN_SRC :=$(wildcard $(MAIN_SRC_PATH)*.cpp)
MAIN_BIN :=$(patsubst $(MAIN_SRC_PATH)%.cpp,$(MAIN_BIN_PATH)%,$(MAIN_SRC))

TST_SRC_PATH := t_src/
TST_BIN_PATH := t_bin/
TST_SRC := $(wildcard $(TST_SRC_PATH)*.cpp)
TST_BIN := $(patsubst $(TST_SRC_PATH)%.cpp,$(TST_BIN_PATH)%,$(TST_SRC))

LIB_PATH := lib/
OBJ_PATH := obj/
LIBS_SRC := $(wildcard $(LIB_PATH)*.cpp)
LIBS_OBJ := $(patsubst $(LIB_PATH)%.cpp,$(OBJ_PATH)%.o,$(LIBS_SRC))


bin : dirs $(MAIN_BIN)
	@echo $(MAIN_BIN)
libs : $(LIBS_OBJ)
	@echo $(LIBS_OBJ)
tests : dirs $(TST_BIN)
clean:
	clear
# rm -rf $(TST_BIN_PATH)*  !( *.cpp|*.h) 
# $(MAIN_BIN_PATH)* $(OBJ_PATH)*
init : 
		@echo Project init
bin_dirs :
		mkdir -p $(OBJ_PATH) $(TST_BIN_PATH) $(MAIN_BIN_PATH)
src_dirs :
		mkdir -p $(LIB_PATH) $(TST_SRC_PATH) $(MAIN_SRC_PATH)
# GENERATOR RULES

# libraries
$(OBJ_PATH)%.o : $(LIB_PATH)%.cpp
	$(CC_CPP) $(FLG) -c $< -o $@

# tests
$(TST_BIN_PATH)% : $(TST_SRC_PATH)%.cpp $(LIBS_OBJ)
	$(CC_CPP) $(FLG) -o $@ $^ -I $(LIB_PATH)

# main
$(MAIN_BIN_PATH)% : $(MAIN_SRC_PATH)%.cpp $(LIBS_OBJ)
	$(CC_CPP) $(FLG) -o $@ $^ -I $(LIB_PATH)