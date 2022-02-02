# COMPILER INFO
CC_CPP := clang++
FLG := -g -Wall

# PATHS AND FILES INFO
MAIN_SRC_PATH = src/
MAIN_BIN_PATH = bin/
# main path
TST_SRC_PATH = t_src/
TST_BIN_PATH = t_bin/
# library path
LIB_PATH = lib/
OBJ_PATH = obj/
# external libraries
EXT_LIB_PATH = extlib/
# genarate file paths
MAIN_SRC = $(wildcard $(MAIN_SRC_PATH)*.cpp)
MAIN_BIN = $(patsubst $(MAIN_SRC_PATH)%.cpp,$(MAIN_BIN_PATH)%,$(MAIN_SRC))

TST_SRC = $(wildcard $(TST_SRC_PATH)*.cpp)
TST_BIN = $(patsubst $(TST_SRC_PATH)%.cpp,$(TST_BIN_PATH)%,$(TST_SRC))

LIBS_SRC = $(wildcard $(LIB_PATH)*.cpp)
LIBS_OBJ = $(patsubst $(LIB_PATH)%.cpp,$(OBJ_PATH)%.o,$(LIBS_SRC))
LIBS_HDR = $(wildcard $(LIB_PATH)*.h)

EXT_OBJ = $(wildcard $(EXT_LIB_PATH)*.o)

# GENERATOR MAKE FUNCTIONS
all : all_msg libs bins tests
all_no_msg : bin_dirs $(LIBS_OBJ) $(MAIN_BIN) $(TST_BIN)
all_msg :

init : init_msg src_dirs
init_msg :
	@echo
	@echo Project init
	@echo Creating Source directories
	@echo $(LIB_PATH) $(TST_SRC_PATH) $(MAIN_SRC_PATH)
	@echo "Add your library source files here eg: lib.cpp lib.h" > $(LIB_PATH)/readme.ini
	@echo "Add your test codes here" > $(TST_SRC_PATH)/readme.ini
	@echo "Add your source codes here" > $(TST_SRC_PATH)/readme.ini
	
bin_dirs :
	@mkdir -p $(OBJ_PATH) $(TST_BIN_PATH) $(MAIN_BIN_PATH)
src_dirs :
	@mkdir -p $(LIB_PATH) $(TST_SRC_PATH) $(MAIN_SRC_PATH)

readme : 
	@echo "sfsdfsdfs">readme

bins : bin_msg bin_dirs $(MAIN_BIN)
bin_msg :
	@echo
	@echo [ BINARIES ]
	@echo
	@echo - Src Path: $(MAIN_SRC_PATH)
	@echo - Bin Path: $(MAIN_BIN_PATH)
	@echo
	
libs : libs_msg bin_dirs $(LIBS_OBJ)
libs_msg :
	@echo
	@echo [ LIBRARIES ]
	@echo
	@echo - Path: $(LIB_PATH)
	@echo

tests : tests_msg bin_dirs $(TST_BIN)
tests_msg :
	@echo
	@echo [ TESTS ]
	@echo
	@echo - Path: $(TST_BIN_PATH)
	@echo

clean:
	@rm -rf $(OBJ_PATH) $(TST_BIN_PATH) $(MAIN_BIN_PATH)
clean_tests:
	@rm -rf $(TST_BIN_PATH)

# GENERATOR RULES -COMPILING

# LIBRARIES
$(OBJ_PATH)%.o : $(LIB_PATH)%.cpp $(LIBS_HDR)
	@echo " > "$<
	@$(CC_CPP) $(FLG) -c $< -o $@ -I $(EXT_LIB_PATH)

# TESTS
$(TST_BIN_PATH)% : $(TST_SRC_PATH)%.cpp $(LIBS_OBJ)
	@echo " > "$<
	@$(CC_CPP) $(FLG) -o $@ $^ $(EXT_OBJ) -I $(LIB_PATH) -I $(EXT_LIB_PATH)

# MAIN
$(MAIN_BIN_PATH)% : $(MAIN_SRC_PATH)%.cpp $(LIBS_OBJ)
	@echo " > "$<
	@$(CC_CPP) $(FLG) -o $@ $^ $(EXT_OBJ) -I $(LIB_PATH) -I $(EXT_LIB_PATH)
