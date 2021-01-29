/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:23:32 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:23:34 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_control(int sig)
{
	int		status;

	if (sig == SIGINT)
	{
		g_signal_status = 1;
		ft_putstr_fd("\b\b  \b\b", 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("\e[103m\e[30m ", 1);
		ft_putstr_fd(g_path_prompt, 1);
		ft_putstr_fd(" \e[0m", 1);
		ft_putstr_fd("\e[93m - $> \e[0m", 1);
	}
	else if (sig == SIGQUIT)
	{
		sig = wait(&status);
		ft_putstr_fd("\b\b  \b\b", 1);
		if (sig != -1)
			ft_putstr_fd("^\\Quit: 3\n", 1);
	}
	g_exit_status = 1;
	return ;
}
