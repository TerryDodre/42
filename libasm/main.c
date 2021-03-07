/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:37:10 by tdodre            #+#    #+#             */
/*   Updated: 2020/12/09 17:16:06 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libasm.h"

int		main(void)
{
	char	*src;
	char	*dst;
	int		len_write;

	src = strndup("hello", 3);
	dst = strndup("bye", 3);
	len_write = 6;
	
	printf("ft_strlen : %lu\n", ft_strlen(src));
	printf("strlen    : %lu\n\n", strlen(src));

	printf("ft_strcpy : %s\n", ft_strcpy(dst, src));
	printf("strcpy    : %s\n\n", strcpy(dst, src));

	printf("ft_strcmp : %d\n", ft_strcmp(src, dst));
	printf("strcmp    : %d\n\n", strcmp(src, dst));

	write(1, "ft_write  : ", 12);
	printf("     // size : %zu\n", ft_write(1, src, len_write));
	write(1, "write     : ", 12);
	printf("     // size : %zu\n", write(1, src, len_write));
	printf("Test ft_write 'salut' ' ca va' dans test.txt\n");
	int		fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0600);
	ft_write(fd, "salut", 5);
	ft_write(fd, " ca va", 6);
	close(fd);
	errno = 0;
	printf("Test d'errno dans ft_write = 9 :\n");
	ft_write(546456, "dff", 25);
	printf("errno = %i\n\n", errno);

	char	orig_buffer[100];
	char	our_buffer[100];
	errno = 0;
	fd = open("test.txt", O_RDWR | O_CREAT, 0600);
	our_buffer[ft_read(fd, our_buffer, 2)] = 0;
	printf("ft_read buffer : %s\n", our_buffer);
	close(fd);
	fd = open("test.txt", O_RDWR | O_CREAT, 0600);
	orig_buffer[read(fd, orig_buffer, 2)] = 0;
	printf("read buffer    : %s\n", orig_buffer);
	close(fd);
	printf("Test d'errno dans ft_read = 9 :\n");
	ft_read(546456, 0, 25);
	printf("errno = %i\n\n", errno);
	close(fd);

	printf("ft_strdup : %s\n", ft_strdup(src));
	printf("strdup    : %s\n", strdup(src));
	return (0);
}
