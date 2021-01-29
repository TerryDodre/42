/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:44:21 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:44:23 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

/*
** FT_PRINTF
*/
typedef struct		s_struct
{
	int				width;
	int				align_left;
	int				zero;
	int				precision;
	int				option;
	int				neg;
	int				precision_neg;
	int				value;
	int				snull;
}					t_struct;

int					ft_printf(const char *format, ...)
					 __attribute__((format(printf,1,2)));
void				init_tab_index(char *tab_index);
void				init_box(t_struct *box);
void				apply_conversion(int index, va_list *ap, t_struct *flags);
char				*ft_utoa_base(unsigned long nb, char *base);
void				nb_is_neg(long *nb, t_struct *box);
int					find_index(char *tab_index, char element);
int					get_int(const char *str, int *pos);
int					get_percentage_index(const char *format);
void				convert_char(va_list *ap, t_struct *flags);
void				convert_str(va_list *ap, t_struct *flags);
void				convert_decimal(va_list *ap, t_struct *flags);
void				convert_unsigned_int(va_list *ap, t_struct *box);
void				convert_hexa(va_list *ap, t_struct *box);
void				convert_hexa_cap(va_list *ap, t_struct *box);
void				convert_address(va_list *ap, t_struct *box);
void				convert_percentage(t_struct *box);
void				write_words(const char *str, int i, t_struct *box);
void				write_spaces(int nb, t_struct *box);
void				write_zeros(int nb, t_struct *box);
void				write_nbr(char *str_nb, int len, int index_zero,
								t_struct *box);
void				do_str_align_right(char *str, int len, t_struct *box);
void				do_str_align_left(char *str, int len, t_struct *box);
void				do_nbr_align_right(char *str_nb, int len, t_struct *box);
void				do_nbr_align_left(char *str_nb, int len, t_struct *box);
void				add_spaces_n_init(int *len, t_struct *box);
void				add_spaces_or_zeros(char *str_nb, int len, t_struct *box);
int					str_null(t_struct *flags, char **str);
int					put_width(const char *format, int *pos, t_struct *flags);
int					put_align_left(const char *format, int *pos,
									t_struct *flags);
int					put_precision(const char *format, int *pos,
									t_struct *flags);
int					put_option(int *pos, va_list *ap, t_struct *box);
int					put_zero(const char *format, int *pos, t_struct *box);
/*
** LINKED LIST
*/
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list				*ft_lst_find(t_list *env_lst, int lst_index);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
int					ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);
/*
** LIBFT
*/
void				*ft_calloc(size_t count, size_t size);
void				ft_free_tab(char ***tab);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, int len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_itoa(int n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
#endif
