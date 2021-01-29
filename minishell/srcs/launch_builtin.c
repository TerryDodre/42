/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:42:23 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 14:01:59 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_builtin_exist(char *cmd)
{
	char	*tab_builtin[8];
	int		index;

	index = 0;
	tab_builtin[0] = "echo";
	tab_builtin[1] = "cd";
	tab_builtin[2] = "pwd";
	tab_builtin[3] = "export";
	tab_builtin[4] = "unset";
	tab_builtin[5] = "env";
	tab_builtin[6] = "exit";
	tab_builtin[7] = NULL;
	while (tab_builtin[index])
	{
		if (ft_strcmp(tab_builtin[index], cmd) == 0)
			return (index);
		index++;
	}
	return (-1);
}

void	exec_builtin(char **cmd, t_node **env_lst, int index)
{
	int		last_cmd;

	last_cmd = count_tab_str(cmd) - 1;
	if (!(ft_strcmp(cmd[last_cmd], "env")))
		modify_node_content_value(*env_lst, ft_nodesize(*env_lst) - 1,
								"/usr/bin/env");
	else
		modify_node_content_value(*env_lst, ft_nodesize(*env_lst) - 1,
								cmd[last_cmd]);
	g_exit_status = 0;
	if (index == 0)
		launch_echo(cmd, *env_lst);
	else if (index == 1)
		launch_cd(cmd, env_lst);
	else if (index == 2)
		launch_pwd();
	else if (index == 3)
		launch_export(cmd, env_lst);
	else if (index == 4)
		launch_unset(cmd, env_lst);
	else if (index == 5)
		launch_env(*env_lst);
	else if (index == 6)
		launch_exit(cmd);
}
