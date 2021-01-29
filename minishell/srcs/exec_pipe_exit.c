/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:25:57 by terry             #+#    #+#             */
/*   Updated: 2020/11/18 16:10:29 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		pipe_str_digit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

void	pipe_exit_continue(char **cmd)
{
	int		o;

	o = 256;
	if (ft_atoi(cmd[1]) < 0)
	{
		g_exit_status = (-ft_atoi(cmd[1]));
		while (o < g_exit_status)
			o += 256;
		g_exit_status = o - g_exit_status;
	}
	else
		g_exit_status = ft_atoi(cmd[1]) % 256;
}

void	pipe_exit(char **cmd)
{
	int	size;

	size = count_tab_str(cmd);
	if (size > 1)
	{
		if (!(pipe_str_digit(cmd[1])))
		{
			ft_printf("exit: %s: numeric argument required\n", cmd[1]);
			g_exit_status = 255;
		}
		else if (size > 2)
		{
			ft_printf("exit: too many arguments\n");
			g_exit_status = 1;
		}
		else
			pipe_exit_continue(cmd);
	}
}
