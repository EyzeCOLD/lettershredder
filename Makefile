#		        _          _   _            
#		       | |        | | | |           
#		       | |     ___| |_| |_ ___ _ __ 
#		       | |    / _ \ __| __/ _ \ '__|
#		       | |___|  __/ |_| ||  __/ |   
#		       \_____/\___|\__|\__\___|_|   
#		  _____ _                  _     _           
#		 /  ___| |                | |   | |          
#		 \ `--.| |__  _ __ ___  __| | __| | ___ _ __ 
#		  `--. \ '_ \| '__/ _ \/ _` |/ _` |/ _ \ '__|
#		 /\__/ / | | | | |  __/ (_| | (_| |  __/ |   
#		 \____/|_| |_|_|  \___|\__,_|\__,_|\___|_|   
#		

### SOURCES ###
                                            
NAME		:= bin/lettershredder
SRC_DIR		:= src/
SRC			:= main.cpp Game.cpp Renderer.cpp Wordlist.cpp
SRC			:= $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR		:= obj/
OBJ			:= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

INC			:= -I./include/

DEP			:= $(OBJ:.o=.d)

# DEBUG #

DEBUG			:= debug/$(NAME)

DEBUG_OBJ_DIR	:= debug/obj/
DEBUG_OBJ		:= $(patsubst $(SRC_DIR)%.cpp, $(DEBUG_OBJ_DIR)%.o, $(SRC))

DEBUG_DEP		:= $(DEBUG_OBJ:.o=.d)

### FLAGS ###

CXX			:= c++
CXXSTD		:= -std=c++11
CXXFLAGS	:= $(CXXSTD) -Wall -Wextra -Werror -Wmissing-declarations \
			   -Wshadow
SPEED_FLAGS	:= -O2
DEBUG_FLAGS := -g -O0 -ggdb -gdwarf-4 -D DEBUG
DEP_FLAGS	:= -MMD -MP

### RULES ###

all: compile_flags.txt $(NAME)

compile_flags.txt:
	@printf "%s\n" $(INC) > $@

$(NAME): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(SPEED_FLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) $(DEP_FLAGS) -c $< -o $@

-include $(DEP)

debug: $(DEBUG)

$(DEBUG): $(DEBUG_OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(DEBUG_OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(INC) $(DEP_FLAGS) -c $< -o $@

-include $(DEBUG_DEP)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEBUG_OBJ_DIR)

fclean: clean
	rm -rf bin/
	rm -rf debug/
	rm -rf compile_flags.txt

re: fclean all

dere: fclean debug

.PHONY: all debug clean fclean re dere
