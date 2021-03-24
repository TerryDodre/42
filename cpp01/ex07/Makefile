# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE= \x1b[37m

NAME		=		replace
PATH_SRC	=		srcs/
PATH_OBJ	=		objs/
SRC			=		main.cpp	replace.cpp
OBJ			=		$(addprefix $(PATH_OBJ), ${SRC:.cpp=.o})
CLANG		=		clang++
FLAGS		=		-Wall -Werror -Wextra
RM			=		rm -rf

all:				$(NAME)

$(PATH_OBJ)%.o:		$(PATH_SRC)%.cpp
					@mkdir -p $(PATH_OBJ)
					@echo "$(GREEN)[Compiling]:\t$(CYAN)"$<
					@$(CLANG) -c $< -o $@

$(NAME):			$(OBJ)
					@$(CLANG) $(FLAGS) -o $(NAME) $(OBJ)
					@echo "$(YELLOW)replace  \t:\t$(GREEN)[OK]$(WHITE)"

clean:
					@$(RM) $(PATH_OBJ)
					@echo "${RED}[CLEAN]:\t$(YELLOW)objs"

fclean:				clean
					@$(RM) $(NAME)
					@$(RM) *.replace
					@echo "${RED}[CLEAN]:\t$(YELLOW)replace"

re:					fclean all

.PHONY: 			all clean fclean re