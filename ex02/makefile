NAME = fixed
SRC = fixed.cpp main.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

$(OBJ_DIR)/%.o : %.cpp
		@mkdir -p $(OBJ_DIR)
		@$(CPP) $(FLAGS) -c $< -o $@

FUCHSIA = '\033[0;95m'
CYAN = '\033[0;36m'
NONE = '\033[0m'

$(NAME) : $(OBJ)
		@$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
				@ echo $(CYAN)          "   ___            "$(NONE)
				@ echo $(FUCHSIA)       "  / __\ _     _   "$(NONE)
				@ echo $(CYAN)          " / /  _| |_ _| |_ "$(NONE)
				@ echo $(FUCHSIA)       "/ /__|_   _|_   _|"$(NONE)
				@ echo $(CYAN)          "\____/ |_|   |_|  "$(NONE)
				@ echo $(FUCHSIA)       "                  "$(NONE)

all     : $(NAME)

clean :
		@rm -rf $(OBJ_DIR)

fclean : clean
		@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
