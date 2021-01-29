# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE= \x1b[37m

NAME		=		minishell
PATH_SRC	=		srcs/
PATH_OBJ	=		objs/
SRC			=		exec_command.c			exec_pipe.c\
					exec_redir_utils.c		exec_redir.c\
					ft_builtin_utils.c		ft_node_utils.c\
					get_absolute_path.c		get_next_line.c\
					launch_builtin.c		launch_cd.c\
					launch_echo.c			launch_env.c\
					launch_exit.c			launch_export_sorting.c\
					launch_export_utils.c	launch_export.c\
					launch_pwd.c			launch_unset.c\
					main.c					par_error_pipe.c\
					par_error_redir.c		par_error_semicolon.c\
					par_free_tmp.c			par_get_cmd.c\
					par_get_value.c			par_jump_quote.c\
					par_parsing.c			par_size_cmd.c\
					par_split_cmd.c			par_without_quote.c\
					print_prompt.c			signal_control.c\
					exec_pipe_exit.c		par_error_quote.c\
					ft_node_utils2.c
OBJ			=		$(addprefix $(PATH_OBJ), ${SRC:.c=.o})
HEADER		=		includes/minishell.h
RM			=		rm -rf
CC			=		clang
LIBFT		=		Libft/libft.a
LIB			= 		libft.a
FLAGS		=		-Wall -Werror -Wextra

all:				$(LIB) $(NAME)

$(PATH_OBJ)%.o:		$(PATH_SRC)%.c $(HEADER) $(LIBS)
					@cp Libft/libft.a ./$(NAME)
					@mkdir -p $(PATH_OBJ)
					@echo "$(GREEN)[Compiling]:\t$(CYAN)"$<
					@$(CC) -c $< -o $@

$(LIB):
					@make -C Libft all

$(NAME):			$(OBJ) $(HEADER)
					@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "$(YELLOW)minishell  \t:\t$(GREEN)[OK]$(WHITE)"

clean:
					@make clean -C Libft/
					@echo "${RED}[CLEAN]:\t$(YELLOW)Libft/objs"
					@echo "${RED}[CLEAN]:\t$(YELLOW)minishell/objs"
					@$(RM) $(PATH_OBJ)

fclean:				clean
					@make fclean -C Libft/
					@echo "${RED}[CLEAN]:\t$(YELLOW)libft.a"
					@echo "${RED}[CLEAN]:\t$(YELLOW)minishell"
					@$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re