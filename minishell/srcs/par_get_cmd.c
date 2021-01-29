/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_get_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:40 by terry             #+#    #+#             */
/*   Updated: 2020/11/28 14:44:50 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_get_dollar(char **buffer, char **tmp,
	int *i, t_node *env_lst)
{
	int		j;
	int		k;
	char	*value;

	j = 0;
	k = 0;
	(*buffer)++;
	while ((*buffer)[j] && (((*buffer)[j] >= 'a' && (*buffer)[j] <= 'z')
		|| ((*buffer)[j] >= 'A' && (*buffer)[j] <= 'Z')
		|| ((*buffer)[j] >= '0' && (*buffer)[j] <= '9')
		|| ((*buffer)[j] == '_')))
		j++;
	value = ft_get_value(*buffer, j, env_lst);
	(*buffer) += j;
	if (value)
	{
		while (value[k])
			(*tmp)[(*i)++] = value[k++];
		free(value);
	}
}

void		ft_get_interrogation(char **buffer, char **tmp, int *i)
{
	char	*value;
	int		j;

	j = 0;
	(*buffer) += 2;
	value = ft_itoa(g_exit_status);
	if (value)
	{
		while (value[j])
			(*tmp)[(*i)++] = value[j++];
		free(value);
		value = NULL;
	}
}

void		ft_get_quote(char **buffer, char **tmp, int *i)
{
	(*tmp)[(*i)++] = *(*buffer)++;
	while ((*buffer)[0] && (*buffer)[0] != '\'')
		(*tmp)[(*i)++] = *(*buffer)++;
	if ((*buffer)[0] == '\'')
		(*tmp)[(*i)++] = *(*buffer)++;
}

void		ft_get_slash(char **buffer, char **tmp, int *i)
{
	(*tmp)[(*i)++] = *(*buffer)++;
	(*buffer)++;
}

char		*ft_get_cmd(char *buffer, t_node *env_lst, int len)
{
	char	*tmp;
	int		i;
	int		d_quote;

	ft_ini_get_cmd(&i, &d_quote, &buffer);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (*buffer == '\"')
			d_quote++;
		if (*buffer == '\'' && (d_quote % 2) == 0)
			ft_get_quote(&buffer, &tmp, &i);
		else if ((d_quote % 2) != 0 && *buffer == '\\' && buffer[1] == '\\')
			ft_get_slash(&buffer, &tmp, &i);
		else if (buffer[0] == '$' && buffer[1] == '?')
			ft_get_interrogation(&buffer, &tmp, &i);
		else if (buffer[0] == '$' && buffer[1] != '\0' && buffer[1] != ' ')
			ft_get_dollar(&buffer, &tmp, &i, env_lst);
		else
			tmp[i++] = *buffer++;
	}
	tmp[i] = '\0';
	return (tmp);
}
