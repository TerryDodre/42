# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m

PATH_SRC	=		srcs/
PATH_OBJ	=		objs/

SRC			=		bonus.c					break_error.c\
					check_argument.c		check_error.c\
					convert_utils.c			convert_value.c\
					draw_sprite.c			draw_wall.c\
					ft_split.c				get_next_line_utils.c\
					get_next_line.c			ini_struct_ray.c\
					main.c					parse_utils.c\
					parse_map.c				parse_value.c\
					raycasting_function.c	raycasting_mouv.c\
					save_bmp.c
OBJ			=		$(addprefix $(PATH_OBJ), ${SRC:.c=.o})

HEADER		=		include/cube.h
NAME		=		Cub3D
MLX			=		minilibx_macos/libmlx.a

FLAGS		=		-Wall -Werror -Wextra
FW			=		-I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework Appkit
RM			=		rm -rf

all:				${MLX} ${NAME}

$(PATH_OBJ)%.o: 	$(PATH_SRC)%.c $(HEADER) $(LIBS) $(MINILIBXS)
		@mkdir -p $(PATH_OBJ)
		@echo "$(YELLOW)Compiling\t:\t$(BLUE)"$<
		@gcc $(FLAGS) -c $< -o $@

$(MLX):		
		@make -C minilibx_macos/

$(NAME):			$(OBJ) $(HEADER)
		@gcc ${FLAGS} ${FW} ${OBJ} -o ${NAME}
		@echo "\n$(YELLOW)Minilibx\t:\t$(GREEN)[OK]"
		@echo "$(YELLOW)Cube3D  \t:\t$(GREEN)[OK]"

clean:
		@make clean -C minilibx_macos/
		@${RM} ${PATH_OBJ}
		@${RM} save.bmp
		@echo "$(YELLOW)Minilibx\t:\t${RED}[CLEAN]"
		@echo "$(YELLOW)objs    \t:\t${RED}[CLEAN]"

fclean:				clean
		@${RM} ${NAME}
		@echo "\n$(YELLOW)Cube3D   \t:\t${RED}[CLEAN]"

re:					fclean all

.PHONY :			all clean fclean re