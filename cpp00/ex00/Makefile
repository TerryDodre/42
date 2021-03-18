# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE= \x1b[37m

NAME		=		megaphone
SRC			=		megaphone.cpp
OBJ			=		${SRC:.cpp=.o}
CLANG		=		clang++
FLAGS		=		-Wall -Werror -Wextra
RM			=		rm -rf

all:				$(NAME)

%.o:				%.cpp
					@echo "$(GREEN)[Compiling]:\t$(CYAN)"$<
					@$(CLANG) -c $< -o $@

$(NAME):			$(OBJ)
					@$(CLANG) $(FLAGS) $(OBJ) -o $(NAME)
					@echo "$(YELLOW)megaphone  \t:\t$(GREEN)[OK]$(WHITE)"

clean:
					@$(RM) $(OBJ)
					@echo "${RED}[CLEAN]:\t$(YELLOW)objs"

fclean:				clean
					@$(RM) $(NAME)
					@echo "${RED}[CLEAN]:\t$(YELLOW)megaphone"

re:					fclean all

.PHONY: 			all clean fclean re