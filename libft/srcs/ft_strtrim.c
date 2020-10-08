/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:53:17 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/08 17:59:17 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		find_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	if (!s1)
		return (NULL);
	while (find_set(set, *s1) == 1)
		s1++;
	i = ft_strlen(s1);
	if (i > 0)
		i--;
	while (find_set(set, s1[i]) == 1)
		i--;
	if (!(tmp = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	while (j <= i)
		tmp[j++] = *s1++;
	return (tmp);
}
