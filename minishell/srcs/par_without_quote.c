/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_without_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:23:57 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:23:58 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		jump_without_quote(char *tmp, int *i)
{
	int		j;

	j = 0;
	(*i) = 0;
	if (tmp[(*i)] == '\'')
	{
		(*i)++;
		while (tmp[(*i)] && tmp[(*i)] == '\'')
			(*i)++;
	}
	else if (tmp[(*i)] == '\"')
	{
		(*i)++;
		while (tmp[(*i)] && tmp[(*i)] == '\"')
			(*i)++;
	}
	if ((*i) > 0)
		j = (*i) - 1;
	if (tmp[(*i)] == '\'' || tmp[(*i)] == '\"')
		(*i)++;
	return (j);
}

int		nb_size_cmd(char *tmp)
{
	int		i;
	int		ret;

	ret = 0;
	while (*tmp)
	{
		ret += jump_without_quote(tmp, &i);
		if (i > 0)
			tmp += i;
		else if (*tmp == '\\')
			tmp++;
		else
		{
			tmp++;
			ret++;
		}
	}
	return (ret);
}

void	get_cmd_without_quote(char **tmp, char **cmd, int *i, char c)
{
	(*tmp)++;
	while ((*tmp)[0] && (*tmp)[0] != c)
		(*cmd)[(*i)++] = *(*tmp)++;
	if ((*tmp)[0] == c)
		(*tmp)++;
}

char	*parse_quote(char *tmp)
{
	char	*cmd;
	int		i;

	i = 0;
	if (!(cmd = malloc(sizeof(char) * (nb_size_cmd(tmp) + 1))))
		return (NULL);
	while (*tmp)
	{
		if (*tmp == '\'' || *tmp == '\"')
			get_cmd_without_quote(&tmp, &cmd, &i, *tmp);
		else if (*tmp == '\\')
			tmp++;
		else
			cmd[i++] = *tmp++;
	}
	cmd[i] = '\0';
	return (cmd);
}

char	**cmd_without_quote(char **tmp)
{
	char	**cmd;
	int		i;
	int		j;

	i = 0;
	while (tmp[i])
		i++;
	if (!(cmd = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		cmd[i] = parse_quote(tmp[i]);
		if (cmd[i] == NULL)
		{
			ft_free_tmp(cmd, i);
			break ;
		}
		i++;
	}
	if (cmd)
		cmd[i] = NULL;
	ft_free_tab(&tmp);
	tmp = NULL;
	return (cmd);
}
