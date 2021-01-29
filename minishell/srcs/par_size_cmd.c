/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_size_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:16 by terry             #+#    #+#             */
/*   Updated: 2020/11/28 14:13:06 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_size_interrogation(char **buffer)
{
	char	*value;
	int		ret;

	(*buffer) += 2;
	ret = 0;
	value = ft_itoa(g_exit_status);
	if (value)
	{
		ret = ft_strlen(value);
		free(value);
		value = NULL;
	}
	return (ret);
}

int			ft_size_dollar(char **buffer, t_node *env_lst)
{
	int		i;
	int		ret;
	char	*value;

	i = 0;
	ret = 0;
	(*buffer)++;
	while ((*buffer)[i] && (((*buffer)[i] >= 'a' && (*buffer)[i] <= 'z')
		|| ((*buffer)[i] >= 'A' && (*buffer)[i] <= 'Z')
		|| ((*buffer)[i] >= '0' && (*buffer)[i] <= '9')
		|| ((*buffer)[i] == '_')))
		i++;
	value = ft_get_value(*buffer, i, env_lst);
	if (value)
	{
		ret = ft_strlen(value);
		free(value);
		value = NULL;
	}
	(*buffer) += i;
	return (ret);
}

int			ft_check_space_end_continue(int ret, char *buffer)
{
	while (*buffer && *buffer != ';')
	{
		if (*buffer == '\"')
		{
			buffer++;
			while (*buffer && *buffer != '\"')
			{
				if (*buffer == '\\' && buffer[1] == '\\')
				{
					buffer++;
					ret++;
				}
				buffer++;
			}
			if (*buffer == '\"')
				buffer++;
		}
		else
			buffer++;
	}
	return (ret);
}

int			ft_check_space_end(char *buffer)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (buffer[i] && buffer[i] != ';')
	{
		if (jump_quote(buffer + i) != 0)
			i += jump_quote(buffer + i);
		i++;
	}
	while (i > 0 && buffer[i - 1] == ' ')
	{
		i--;
		ret++;
	}
	ret = ft_check_space_end_continue(ret, buffer);
	return (ret);
}

int			ft_size_cmd(char *buffer, t_node *env_lst)
{
	int		i;
	int		j;

	i = 0;
	while (*buffer == ' ')
		buffer++;
	j = ft_check_space_end(buffer);
	while (*buffer && *buffer != ';')
	{
		if (jump_quote(buffer) != 0)
		{
			i += jump_quote_dollar(buffer, env_lst);
			buffer += jump_quote(buffer);
		}
		else if (buffer[0] == '$' && buffer[1] == '?')
			i += ft_size_interrogation(&buffer);
		else if (buffer[0] == '$' && buffer[1] != '\0' && buffer[1] != ' ')
			i += ft_size_dollar(&buffer, env_lst);
		else
		{
			buffer++;
			i++;
		}
	}
	return (i - j);
}
