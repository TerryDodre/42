/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:43:12 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 14:53:52 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	modify_oldpwd(t_node **env_lst, char *last_pos)
{
	int		name_order;
	t_node	*oldpwd;

	if ((name_order = search_name(*env_lst, "OLDPWD=")) >= 0)
		modify_node_content_value(*env_lst, name_order, last_pos);
	else
	{
		if ((name_order = search_name(*env_lst, "OLDPWD")) >= 0)
			modify_node_content(*env_lst, name_order, "OLDPWD=", last_pos);
	}
}

void	modify_pwd(t_node **env_lst, char *last_pos)
{
	t_node	*pwd;
	int		name_order;
	char	buff[4096 + 1];

	getcwd(buff, 4096);
	modify_oldpwd(env_lst, last_pos);
	if ((name_order = search_name(*env_lst, "PWD=")) >= 0)
		modify_node_content_value(*env_lst, name_order, buff);
	else
	{
		if ((name_order = search_name(*env_lst, "PWD")) >= 0)
			modify_node_content(*env_lst, name_order, "PWD=", buff);
	}
}

void	launch_cd(char **cmd, t_node **env_lst)
{
	int		error;
	char	buff[4096 + 1];

	getcwd(buff, 4096);
	if (!cmd[1])
		return ;
	error = chdir(cmd[1]);
	modify_pwd(env_lst, buff);
	if (error == -1)
	{
		ft_printf("cd : %s: No such file or directory\n", cmd[1]);
		g_exit_status = 1;
	}
}
