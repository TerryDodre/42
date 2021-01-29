/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_error_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:25:05 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:25:06 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_pipe_error(char **s)
{
	int		i;

	i = 0;
	while (*(*s) == '|')
	{
		i++;
		(*s)++;
	}
	while (*(*s) == ' ')
		(*s)++;
	if (i > 1)
	{
		ft_printf("syntax error near unexpected token `||'\n");
		return (1);
	}
	else if (*(*s) == '\0' || *(*s) == '|')
	{
		ft_printf("syntax error near unexpected token `|'\n");
		return (1);
	}
	return (0);
}

int			ft_check_pipe(char *s)
{
	int		i;

	if (*s == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		return (1);
	}
	while (*s)
	{
		i = jump_quote(s);
		if (i > 0)
			s += i;
		else if (*s == '|')
		{
			if (check_pipe_error(&s) == 1)
				return (1);
		}
		else
			s++;
	}
	return (0);
}
