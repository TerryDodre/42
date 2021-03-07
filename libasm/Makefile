NAME		=		libasm.a
PATH_SRC	=		src/
PATH_OBJ	=		obj/
SRC			=		ft_strlen.s		ft_strcpy.s\
					ft_strcmp.s		ft_write.s\
					ft_read.s		ft_strdup.s
OBJ			=		$(addprefix $(PATH_OBJ), ${SRC:.s=.o})
HEADER		=		include/libasm.h
FLAGS		=		-Wall -Werror -Wextra
RM			=		rm -rf

all:				$(NAME)

$(PATH_OBJ)%.o:		$(PATH_SRC)%.s $(HEADER)
					@mkdir -p $(PATH_OBJ)
					@nasm -f elf64 -s $< -o $@

$(NAME):			$(OBJ) $(HEADER)
					@ar -rcs $(NAME) $(OBJ)

clean:
					@${RM} ${PATH_OBJ}

fclean:				clean
					@$(RM) $(NAME)

re:					fclean all

test:				re
					@clang $(FLAGS) main.c libasm.a -o a.test && ./a.test
					@$(RM) a.test

.PHONY:				all clean fclean re test