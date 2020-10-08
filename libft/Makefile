# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:53:57 by tdodre            #+#    #+#              #
#    Updated: 2020/10/08 17:38:12 by tdodre           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE= \x1b[37m

PATH_SRCS	=	srcs/
PATH_OBJS	=	objs/
NAME		=	libft.a
SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
				ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
				ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c\
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
				ft_substr.c ft_tolower.c ft_toupper.c
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(addprefix $(PATH_OBJS), ${SRCS:.c=.o})
HEAD		=	include/libft.h
CC			=	gcc
RM			=	rm -rf

$(PATH_OBJS)%.o:$(PATH_SRCS)%.c		$(HEAD)
			@mkdir -p $(PATH_OBJS)
			@echo "$(YELLOW)Compiling\t:\t$(BLUE)"$<
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(HEAD)
			@ar rc $(NAME) $(OBJS)
			@echo "$(YELLOW)Libft  \t\t:\t$(GREEN)[OK]"
			@ranlib $(NAME)

clean:
			@$(RM) $(PATH_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re