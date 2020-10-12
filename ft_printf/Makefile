# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 14:24:28 by tdodre            #+#    #+#              #
#    Updated: 2020/10/12 13:28:42 by terry            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE= \x1b[37m

LIBFT			=		libft/libft.a
LIB				=		libft.a

NAME			=		libftprintf.a
PATH_SRCS		=		srcs/
PATH_OBJS		=		objs/
OBJS			=		$(addprefix $(PATH_OBJS), ${SRCS:.c=.o})
HEAD			=		include/ft_printf.h
SRCS			=		ft_conversion_bighexa.c ft_conversion_char.c ft_conversion_int.c\
						ft_conversion_littlehexa.c ft_conversion_pointer.c ft_conversion_porcent.c\
						ft_conversion_string.c ft_conversion_unsint.c ft_flags.c ft_printf.c\
						ft_write.c

CC				=		gcc
FLAGS			=		-Wall -Werror -Wextra
RM				=		rm -rf

all:				$(LIB) $(NAME)

$(LIB):
					@make -C libft all
					

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c $(HEAD) $(LIBFT)
					@mkdir -p $(PATH_OBJS)
					@echo "$(YELLOW)Compiling\t:\t$(BLUE)"$<
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS) $(HEAD)
					@cp $(LIBFT) ./$(NAME)
					@ar rc $(NAME) $(OBJS)
					@echo "$(YELLOW)Printf\t\t:\t$(GREEN)[OK]"
					@ranlib $(NAME)

clean:
					@make -C libft clean
					@echo "$(YELLOW)Printft\t\t:\t$(RED)clean"$<
					@$(RM) $(PATH_OBJS)

fclean:
					@make -C libft fclean
					@echo "$(YELLOW)Printft\t\t:\t$(RED)fclean"$<
					@$(RM) $(PATH_OBJS)
					@$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re
