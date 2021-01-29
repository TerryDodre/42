/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:43:00 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:43:01 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	if (dst && src)
	{
		srclen = ft_strlen(src);
		if (srclen < size)
			ft_memcpy(dst, src, srclen + 1);
		else if (size != 0)
		{
			ft_memcpy(dst, src, size - 1);
			dst[size - 1] = '\0';
		}
		return (srclen);
	}
	return (0);
}
