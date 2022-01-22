# COMPILER INFO
CC_CPP := g++
FLG := -g -Wall

# PATHS AND FILES INFO

MAIN_SRC_PATH := src/		
MAIN_BIN_PATH := bin/
MAIN_SRC = $(wildcard $(MAIN_SRC_PATH)*.cpp)
MAIN_BIN = $(patsubst $(MAIN_SRC_PATH)%.cpp,$(MAIN_BIN_PATH)%,$(MAIN_SRC))

TST_SRC_PATH := t_src/
TST_BIN_PATH := t_bin/
TST_SRC = $(wildcard $(TST_SRC_PATH)*.cpp)
TST_BIN = $(patsubst $(TST_SRC_PATH)%.cpp,$(TST_BIN_PATH)%,$(TST_SRC))
	
LIB_PATH := lib/
OBJ_PATH := obj/
LIBS_SRC = $(wildcard $(LIB_PATH)*.cpp)
LIBS_OBJ = $(patsubst $(LIB_PATH)%.cpp,$(OBJ_PATH)%.o,$(LIBS_SRC))

# GENERATOR MAKE FUNCTIONS
all : all_msg bin libs
all_msg :
	clear
init : init_msg src_dirs
init_msg :
	@echo
	@echo Project init
	@echo Creating Source directories
	@echo $(LIB_PATH) $(TST_SRC_PATH) $(MAIN_SRC_PATH)
	@echo Add your library source files here eg: lib.cpp lib.h > $(LIB_PATH)/readme.ini
bin_dirs :
	@mkdir -p $(OBJ_PATH) $(TST_BIN_PATH) $(MAIN_BIN_PATH)
src_dirs :
	@mkdir -p $(LIB_PATH) $(TST_SRC_PATH) $(MAIN_SRC_PATH)


bin : bin_msg bin_dirs $(MAIN_BIN)
bin_msg :
	@echo [BINS]
	@echo - Src Path: $(MAIN_SRC_PATH)
	@echo - Bin Path: $(MAIN_BIN_PATH)
	@echo - Sources: $(MAIN_SRC)
	@echo - Files: $(MAIN_BIN)
	
libs : libs_msg bin_dirs $(LIBS_OBJ)
libs_msg :
	@echo [LIBS]
	@echo - Path: $(LIB_PATH)
	@echo - Files: $(LIBS_OBJ)

tests : tests_msg bin_dirs $(TST_BIN)
tests_msg :
	@echo [TESTS]
	@echo - Path: $(TST_BIN_PATH)
	@echo - Files: $(TST_BIN)

clean:
	rm -rf $(OBJ_PATH) $(TST_BIN_PATH) $(MAIN_BIN_PATH)

# GENERATOR RULES -COMPILING

# -libraries
$(OBJ_PATH)%.o : $(LIB_PATH)%.cpp
	$(CC_CPP) $(FLG) -c $< -o $@

# -tests
$(TST_BIN_PATH)% : $(TST_SRC_PATH)%.cpp $(LIBS_OBJ)
	$(CC_CPP) $(FLG) -o $@ $^ -I $(LIB_PATH)

# -main
$(MAIN_BIN_PATH)% : $(MAIN_SRC_PATH)%.cpp $(LIBS_OBJ)
	$(CC_CPP) $(FLG) -o $@ $^ -I $(LIB_PATH)
