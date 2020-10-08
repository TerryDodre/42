/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:28:21 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/08 17:37:48 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (dest && src)
	{
		i = ft_strlen(src);
		if (i < n)
			ft_memcpy(dest, src, i + 1);
		else if (n != 0)
		{
			ft_memcpy(dest, src, n - 1);
			dest[n - 1] = '\0';
		}
		return (i);
	}
	return (0);
}
