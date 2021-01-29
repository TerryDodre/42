/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:42:28 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:42:28 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t		get_cnt(char const *s, char c)
{
	size_t		cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (cnt);
}

char		**free_machine(char **s, int idx)
{
	while (s[idx] != NULL && idx >= 0)
	{
		free(s[idx]);
		s[idx] = NULL;
		idx--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	size_t		idx;
	size_t		len;
	size_t		word_cnt;
	char		**words;

	if (!s || !(words = (char **)malloc(sizeof(char *) * (get_cnt(s, c) + 1))))
		return (NULL);
	word_cnt = get_cnt(s, c);
	idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				len++;
			if (idx < word_cnt && !(words[idx++] = ft_substr(s, 0, len)))
				return (free_machine(words, idx));
			s += len;
		}
	}
	words[idx] = NULL;
	return (words);
}
