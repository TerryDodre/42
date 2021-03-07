/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:25:23 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/16 14:09:23 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strchr(const char *str, int charset)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == charset)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	maxsize;

	i = -1;
	if (s == 0)
		return (NULL);
	maxsize = ((start >= ft_strlen(s)) ? 0 : len);
	if (!(str = malloc(sizeof(char) * (maxsize + 1))))
		return (NULL);
	while (++i < maxsize && s[start + i])
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	if (!(dst = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
