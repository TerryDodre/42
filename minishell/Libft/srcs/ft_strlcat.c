/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:42:56 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:42:57 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned	int x;
	unsigned	int	y;
	unsigned	int	len;

	len = 0;
	x = 0;
	y = 0;
	while (dst[x])
		x++;
	len = ft_strlen(dst);
	if (size > len + 1)
	{
		while (src[y] && y < (size - len - 1))
		{
			dst[x] = src[y];
			x++;
			y++;
		}
		dst[x] = '\0';
	}
	if (size < len)
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + len);
}
