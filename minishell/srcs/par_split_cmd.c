/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_split_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:06 by terry             #+#    #+#             */
/*   Updated: 2020/11/25 14:57:48 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		get_nb_option(char **s, size_t *cnt, int *i)
{
	while ((*s)[0] == '>' || (*s)[0] == '<' || (*s)[0] == '|')
	{
		(*s)++;
		(*cnt)++;
	}
	if ((*s)[0] != ' ' && (*s)[0] != '\n' && (*s)[0] != '\t')
		(*cnt)++;
}

size_t		get_nb_cmd(char *s)
{
	size_t		cnt;
	int			i;

	cnt = 1;
	while (*s != '\0')
	{
		i = jump_quote(s);
		if (i != 0)
			s += i;
		else if (s[0] == '\\' && s[1] == ' ')
			s += 2;
		else if (*s == '>' || *s == '|' || *s == '<')
			get_nb_option(&s, &cnt, &i);
		else if (*s == ' ' || *s == '\n' || *s == '\t')
		{
			while (*s == ' ' || *s == '\n' || *s == '\t')
				s++;
			if (*s != '>' && *s != '|' && *s != '<')
				cnt++;
		}
		else
			s++;
	}
	return (cnt);
}

size_t		count_part_cmd(char *s)
{
	size_t		len;

	len = 0;
	if (*(s + len) == '>' || *(s + len) == '|' || *(s + len) == '<')
		return (1);
	while (*(s + len) && *(s + len) != '>' && *(s + len) != '<'
		&& *(s + len) != '|' && *(s + len) != '\t' && *(s + len) != '\n'
		&& (*(s + len) != ' ' || (len != 0 && *(s + len - 1) == '\\')))
	{
		if (jump_quote(s + len) != 0)
			len += jump_quote(s + len);
		else if (*(s + len) != '\0')
			len++;
	}
	return (len);
}

char		**ft_split_cmd(char *s)
{
	size_t		idx;
	size_t		len;
	size_t		word_cnt;
	char		**words;

	if (!s || !(words = (char **)malloc(sizeof(char *) *
		(get_nb_cmd(s) + 1))))
		return (NULL);
	word_cnt = get_nb_cmd(s);
	idx = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		else
		{
			len = count_part_cmd(s);
			if (idx < word_cnt && !(words[idx++] = ft_substr(s, 0, len)))
				return (ft_free_tmp(words, idx));
			s += len;
		}
	}
	words[idx] = NULL;
	idx = 0;
	return (words);
}
