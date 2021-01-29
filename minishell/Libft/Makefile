# Colors
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
SRCS		=	ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strjoin.c\
				ft_strncmp.c ft_substr.c ft_calloc.c ft_isdigit.c  ft_memcmp.c\
				ft_split.c  ft_strlcat.c ft_strnstr.c ft_tolower.c ft_isalnum.c\
				ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strrchr.c\
				ft_toupper.c ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c\
				ft_strdup.c ft_strlen.c ft_strtrim.c ft_strcpy.c ft_calloc.c\
				ft_strcat.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c ft_free_tab.c ft_strcmp.c\
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
				ft_lstiter.c ft_lstmap.c ft_strndup.c ft_lstfind.c\
				ft_printf.c ft_printf_add.c ft_printf_init.c ft_write_words.c\
				ft_write_nbr.c ft_flags.c ft_convert_c.c ft_convert_d.c\
				ft_convert_s.c ft_convert_uxp.c

CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(addprefix $(PATH_OBJS), ${SRCS:.c=.o})
HEAD		=	libft.h
CC			=	clang
RM			=	rm -rf


$(PATH_OBJS)%.o:$(PATH_SRCS)%.c		$(HEAD)
			@mkdir -p $(PATH_OBJS)
			@echo "$(GREEN)[Compiling]:\t$(CYAN)"$<
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(HEAD)
			@ar rc $(NAME) $(OBJS)
			@echo "$(YELLOW)Libft  \t\t:\t$(GREEN)[OK]"
			@ranlib $(NAME)

clean:
			@$(RM) $(PATH_OBJS)
			@$(RM) $(BOBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus