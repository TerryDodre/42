# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 14:24:28 by tdodre            #+#    #+#              #
#    Updated: 2020/10/10 10:43:48 by tdodre           ###   ########lyon.fr    #
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
PATH_SRCS_LIB	=		libft/srcs/
PATH_OBJS_LIB	=		libft/objs/
OBJS_LIB		=		$(addprefix $(PATH_OBJS_LIB), ${SRCS_LIB:.c=.o})
HEAD_LIB		=		libft/include/libft.h
SRCS_LIB 		=		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
						ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
						ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
						ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
						ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c\
						ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
						ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
						ft_substr.c ft_tolower.c ft_toupper.c

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

all:				$(NAME)

$(PATH_OBJS_LIB)%.o:$(PATH_SRCS_LIB)%.c $(HEAD)
					@mkdir -p $(PATH_OBJS_LIB)
					@echo "$(YELLOW)Compiling\t:\t$(BLUE)"$<
					@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):			$(OBJS_LIB) $(HEAD_LIB)
					@ar rc $(LIBFT) $(OBJS_LIB)
					@echo "$(YELLOW)Libft\t\t:\t$(GREEN)[OK]"
					@ranlib $(LIBFT)

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c $(HEAD)
					@mkdir -p $(PATH_OBJS)
					@echo "$(YELLOW)Compiling\t:\t$(BLUE)"$<
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(LIBFT) $(OBJS) $(HEAD)
					@cp $(LIBFT) ./$(NAME)
					@ar rc $(NAME) $(OBJS)
					@echo "$(YELLOW)Printf\t\t:\t$(GREEN)[OK]"
					@ranlib $(NAME)

clean:
					@echo "$(YELLOW)Libft\t\t:\t$(RED)clean"$<
					@$(RM) $(PATH_OBJS_LIB)
					@echo "$(YELLOW)Printft\t\t:\t$(RED)clean"$<
					@$(RM) $(PATH_OBJS)

fclean:
					@echo "$(YELLOW)Libft\t\t:\t$(RED)fclean"$<
					@$(RM) $(PATH_OBJS_LIB)
					@$(RM) $(LIBFT)
					@echo "$(YELLOW)Printft\t\t:\t$(RED)fclean"$<
					@$(RM) $(PATH_OBJS)
					@$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re
