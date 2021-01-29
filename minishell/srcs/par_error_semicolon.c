/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_error_semicolon.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:51 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:24:51 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_semicolon_after(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ';')
		{
			i++;
			while (s[i] && s[i] == ' ')
				i++;
			if (s[i] == '|')
			{
				ft_printf("syntax error near unexpected token `|'\n");
				return (1);
			}
		}
		else
			i++;
	}
	return (0);
}

int			check_semicolon_before(char *s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		if (s[i] == ';')
		{
			j = i - 1;
			while (j > 0 && s[j] == ' ')
				j--;
			if (s[j] == '|')
			{
				ft_printf("syntax error near unexpected token `;'\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int			check_first_letter(char *s)
{
	int			i;

	while (*s == ' ')
		s++;
	if (s[0] == ';' && s[1] != ';')
	{
		ft_printf("syntax error near unexpected token `;'\n");
		return (1);
	}
	while (*s)
	{
		i = jump_quote(s);
		if (i > 0)
			s += i;
		else if (s[0] == ';' && s[1] == ';')
		{
			ft_printf("syntax error near unexpected token `;;'\n");
			return (1);
		}
		else
			s++;
	}
	return (0);
}

int			ft_check_semicolon(char *s)
{
	if (check_first_letter(s) == 1 || check_semicolon_before(s) == 1
		|| check_semicolon_after(s) == 1)
	{
		g_exit_status = 258;
		return (1);
	}
	return (0);
}
