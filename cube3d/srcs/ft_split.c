/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:25:11 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/15 16:09:00 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static void		ft_free_tab(char ***tab)
{
	int	count;

	if (!tab)
		return ;
	count = 0;
	while ((*tab)[count])
	{
		free((*tab)[count]);
		count++;
	}
	free(*tab);
	*tab = NULL;
}

static int		ft_countwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char		*ft_mallocwords(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if ((word = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		**ft_make_tab(char **arr, char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if ((arr[i] = ft_mallocwords(s, c)) == NULL)
			{
				ft_free_tab(&arr);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;

	if (s)
	{
		if ((arr = malloc(sizeof(char *) * (ft_countwords(s, c) + 1))) == NULL)
			return (NULL);
		return (ft_make_tab(arr, s, c));
	}
	return (NULL);
}
