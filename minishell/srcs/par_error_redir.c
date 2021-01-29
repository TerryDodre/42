/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_error_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:56 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:36:13 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_outredir_error(char **s)
{
	int		i;

	i = 0;
	while (*(*s) == '>')
	{
		i++;
		(*s)++;
	}
	if (i == 3)
		ft_printf("syntax error near unexpected token `>'\n");
	else if (i > 3)
		ft_printf("syntax error near unexpected token `>>'\n");
	if (i > 2)
		return (1);
	while (*(*s) == ' ')
		(*s)++;
	if (*(*s) == '\0')
		ft_printf("syntax error near unexpected token `newline'\n");
	else if (*(*s) == '<')
		ft_printf("syntax error near unexpected token `<'\n");
	else if (*(*s) == '>')
		ft_printf("syntax error near unexpected token `>'\n");
	if (*(*s) == '<' || *(*s) == '\0' || *(*s) == '>')
		return (1);
	return (0);
}

int			check_inredir_error(char **s)
{
	int		i;

	i = 0;
	while (*(*s) == '<')
	{
		i++;
		(*s)++;
	}
	if (i > 1 && i <= 4)
		ft_printf("syntax error near unexpected token `<'\n");
	else if (i == 5)
		ft_printf("syntax error near unexpected token `<<'\n");
	else if (i > 5)
		ft_printf("syntax error near unexpected token `<<<'\n");
	if (i > 1)
		return (1);
	while (*(*s) == ' ')
		(*s)++;
	if (*(*s) == '\0')
	{
		ft_printf("syntax error near unexpected token `newline'\n");
		return (1);
	}
	return (0);
}

int			ft_check_redir(char *s)
{
	int		i;

	while (*s)
	{
		i = jump_quote(s);
		if (i > 0)
			s += i;
		else if (*s == '<')
		{
			if (check_inredir_error(&s) == 1)
				return (1);
		}
		else if (*s == '>')
		{
			if (check_outredir_error(&s) == 1)
				return (1);
		}
		else
			s++;
	}
	return (0);
}
