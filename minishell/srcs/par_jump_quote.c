/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_jump_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:29 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:24:30 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			jump_quote(char *s)
{
	int		i;

	i = 0;
	if (s[i] == '\'')
	{
		i++;
		while (s[i] && s[i] != '\'')
			i++;
		i++;
	}
	else if (s[i] == '\"')
	{
		i++;
		while (s[i] && s[i] != '\"')
			i++;
		i++;
	}
	return (i);
}

int			jump_dollar(char **s, t_node *env_lst)
{
	int		j;
	int		ret;
	char	*value;

	j = 0;
	ret = 0;
	(*s)++;
	while ((*s)[j] && (((*s)[j] >= 'a' && (*s)[j] <= 'z')
		|| ((*s)[j] >= 'A' && (*s)[j] <= 'Z')
		|| ((*s)[j] >= '0' && (*s)[j] <= '9')
		|| ((*s)[j] == '_')))
		j++;
	value = ft_get_value(*s, j, env_lst);
	if (value)
	{
		ret = ft_strlen(value);
		free(value);
	}
	(*s) += j;
	return (ret);
}

int			jump_interrogation(char **s)
{
	char	*value;
	int		ret;

	(*s) += 2;
	ret = 0;
	value = ft_itoa(g_exit_status);
	if (value)
	{
		ret = ft_strlen(value);
		free(value);
	}
	return (ret);
}

int			jump_simplequote_dollar(char *s)
{
	int		ret;

	ret = 1;
	while (s[ret] && s[ret] != '\'')
		ret++;
	if (s[ret] == '\'')
		ret++;
	return (ret);
}

int			jump_quote_dollar(char *s, t_node *env_lst)
{
	int		len;

	len = 0;
	if (*s == '\'')
		len += jump_simplequote_dollar(s);
	else if (*s == '\"')
	{
		s++;
		len++;
		while (*s && *s != '\"')
		{
			if (*s == '$' && s[1] == '?')
				len += jump_interrogation(&s);
			else if (*s == '$' && s[1] != '\0' && s[1] != ' ')
				len += jump_dollar(&s, env_lst);
			else
			{
				s++;
				len++;
			}
		}
		if (*s == '\"')
			len++;
	}
	return (len);
}
