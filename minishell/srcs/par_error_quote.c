/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_error_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:14:18 by terry             #+#    #+#             */
/*   Updated: 2020/11/28 15:42:41 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_write_error_quote(char c)
{
	if (c == '\'')
		ft_printf("error : a quote remains open `'`\n");
	else if (c == '\"')
		ft_printf("error : a double quote remains open `\"`\n");
	return (1);
}

int			ft_error_dquote(char **s)
{
	(*s)++;
	while (*(*s) && *(*s) != '\"')
		(*s)++;
	if (*(*s) == '\"')
	{
		(*s)++;
		return (0);
	}
	else
		return (ft_write_error_quote('\"'));
}

int			ft_error_quote(char *s)
{
	while (*s)
	{
		if (*s == '\'')
		{
			s++;
			while (*s && *s != '\'')
				s++;
			if (*s == '\'')
				s++;
			else
				return (ft_write_error_quote('\''));
		}
		else if (*s == '\"')
		{
			if (ft_error_dquote(&s) == 1)
				return (1);
		}
		else
			s++;
	}
	return (0);
}
