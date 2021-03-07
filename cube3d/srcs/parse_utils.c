/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:38:09 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/16 15:35:32 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int		next_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int		ft_atoi(int i, char *parse)
{
	int		nb;

	nb = 0;
	if (parse[i] < '0' || parse[i] > '9')
		return (-1);
	while (parse[i] >= '0' && parse[i] <= '9')
	{
		nb = nb * 10 + (parse[i] - '0');
		i++;
	}
	return (nb);
}

char	*ft_subline(char const *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_submap(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	maxsize;

	i = -1;
	if (s == 0)
		return (NULL);
	maxsize = ((start >= ft_strlen(s)) ? 0 : len);
	if (!(str = malloc(sizeof(char) * (maxsize + 2))))
		return (NULL);
	while (++i < maxsize && s[start + i])
		str[i] = s[start + i];
	str[i] = '\n';
	str[i + 1] = '\0';
	return (str);
}

char	*ft_joinmap(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!s1)
		return (ft_submap(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (ft_submap(s1, 0, ft_strlen(s1)));
	if (!(dst = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\n';
	dst[i + j + 1] = '\0';
	return (dst);
}
