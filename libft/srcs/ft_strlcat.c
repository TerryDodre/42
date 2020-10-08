/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 12:35:23 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/08 17:27:45 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (*dest)
		dest++;
	if (i + 1 < n)
	{
		while (src[j] && j < (n - i - 1))
			*dest++ = src[j++];
		*dest = '\0';
	}
	if (n < i)
		return (ft_strlen(src) + n);
	return (ft_strlen(src) + i);
}
