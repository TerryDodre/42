/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:42:55 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 19:19:20 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_str_digit(char *str)
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

void	launch_exit(char **cmd)
{
	int	size;

	size = count_tab_str(cmd);
	g_exit_out = 1;
	if (size > 1)
	{
		if (!(is_str_digit(cmd[1])))
		{
			ft_printf("exit: %s: numeric argument required\n", cmd[1]);
			g_exit_status = 255;
		}
		else if (size > 2)
		{
			ft_printf("exit: too many arguments\n");
			g_exit_status = 1;
			g_exit_out = 0;
		}
		else
			g_exit_status = ft_atoi(cmd[1]);
	}
}
