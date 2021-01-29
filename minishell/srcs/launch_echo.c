/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:11:06 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 13:11:08 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_newline(char *str)
{
	int i;
	int	len;

	i = 0;
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (str[i] == '-')
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
		if (i == len)
			return (1);
		else
			return (0);
	}
	return (-1);
}

void	launch_echo(char **cmd, t_node *env_lst)
{
	int	i;
	int	nb_cmd;
	int	del_newline;
	int	check;

	i = 1;
	del_newline = 0;
	nb_cmd = count_tab_str(cmd);
	if (nb_cmd > 1)
	{
		while ((check = is_newline(cmd[i])) == 1 && i < nb_cmd)
		{
			del_newline = 1;
			i++;
		}
		while (cmd[i])
		{
			ft_printf("%s", cmd[i]);
			if (i < nb_cmd - 1)
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (del_newline == 0)
		ft_putchar_fd('\n', 1);
}
