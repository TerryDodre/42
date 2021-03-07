/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:33:38 by tdodre            #+#    #+#             */
/*   Updated: 2020/08/27 16:17:35 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_write(int fd, const void *buf, size_t count);
size_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
int		ft_atoi_base(char *str, char *base);

#endif
