/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:59:01 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/08 17:02:30 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char *)s1);
	if (ft_strlen((char *)s1) < ft_strlen((char *)s2))
		return (NULL);
	while (s1[i] && n--)
	{
		while ((s1[i + j] == s2[j]) && (s1[i + j] ||
					s2[j]) && (j <= n))
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		if (s2[j] != s1[i])
			j = 0;
		i++;
	}
	return (NULL);
}
