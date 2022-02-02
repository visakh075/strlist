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

init : src_dirs init_msg
init_msg :
	@echo
	@echo " Project init"
	@echo " Creating Source directories"
	@echo
	@echo "  "$(LIB_PATH)
	@echo "  "$(TST_SRC_PATH)
	@echo "  "$(MAIN_SRC_PATH)
	@echo "  "$(EXT_LIB_PATH)
	@echo
	@echo "put your library source files \nhere eg: libXXX.cpp libXXX.h\noutput files will be generated at "$(OBJ_PATH) > $(LIB_PATH)/read_me.txt
	@echo "put your test codes here\noutputs will be generated at "$(TST_BIN_PATH) > $(TST_SRC_PATH)/read_me.txt
	@echo "put your source codes here\noutputs will be generated at "$(MAIN_BIN_PATH) > $(MAIN_SRC_PATH)/read_me.txt
	
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
	@$(CC_CPP) $(FLG) -c $< -o $@ -I $(EXT_LIB_PATH) > build.log

# TESTS
$(TST_BIN_PATH)% : $(TST_SRC_PATH)%.cpp $(LIBS_OBJ)
	@echo " > "$<
	@$(CC_CPP) $(FLG) -o $@ $^ $(EXT_OBJ) -I $(LIB_PATH) -I $(EXT_LIB_PATH) >> build.log

# MAIN
$(MAIN_BIN_PATH)% : $(MAIN_SRC_PATH)%.cpp $(LIBS_OBJ)
	@echo " > "$<
	@$(CC_CPP) $(FLG) -o $@ $^ $(EXT_OBJ) -I $(LIB_PATH) -I $(EXT_LIB_PATH) >> build.log
