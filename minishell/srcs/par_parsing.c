/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:23 by terry             #+#    #+#             */
/*   Updated: 2020/11/28 14:39:50 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_ini_get_cmd(int *i, int *d_quote, char **buffer)
{
	(*i) = 0;
	(*d_quote) = 0;
	while (*(*buffer) == ' ')
		(*buffer)++;
}

int			ft_skip_semicolon(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != ';')
	{
		if (jump_quote(buffer + i) != 0)
			i += jump_quote(buffer + i);
		else
			i++;
	}
	if (buffer[i] == ';')
		i++;
	return (i);
}

int			ft_nb_cmd(char *s)
{
	int		count;
	int		i;

	count = 1;
	while (*s)
	{
		i = jump_quote(s);
		if (i != 0)
			s += i;
		else if (*s != ';')
			s++;
		else
		{
			count++;
			s++;
		}
	}
	return (count);
}

int			ft_error_command(char *s)
{
	if (ft_check_semicolon(s) == 1)
	{
		g_exit_status = 258;
		return (1);
	}
	else if (ft_check_pipe(s) == 1)
	{
		g_exit_status = 258;
		return (1);
	}
	else if (ft_check_redir(s) == 1)
	{
		g_exit_status = 258;
		return (1);
	}
	else if (ft_error_quote(s) == 1)
	{
		g_exit_status = 258;
		return (1);
	}
	return (0);
}

char		**ft_parsing(char *buffer, t_node *env_lst)
{
	char	**tmp;
	int		i;
	int		j;
	int		len;

	j = 0;
	g_signal_status = 1 ? 0 : g_signal_status;
	if (buffer == NULL)
		return (NULL);
	else if (ft_error_command(buffer) == 1)
		return (NULL);
	i = ft_nb_cmd(buffer);
	if (!(tmp = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		len = ft_size_cmd(buffer, env_lst);
		tmp[j] = ft_get_cmd(buffer, env_lst, len);
		if (tmp[j] == NULL)
			return (ft_free_tmp(tmp, j));
		buffer += ft_skip_semicolon(buffer);
		j++;
	}
	tmp[j] = NULL;
	return (tmp);
}
