/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:26:02 by terry             #+#    #+#             */
/*   Updated: 2020/11/28 14:06:15 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		exec_cmd_others2(char **cmd, t_node *env_lst, char *tmp)
{
	prompt_command_not_found(tmp);
	cmd[0] = ft_strdup(tmp);
	g_exit_status = 127;
}

void		exec_cmd_others(char **cmd, t_node *env_lst)
{
	pid_t	pid;
	int		status;
	char	*tmp;
	char	**dash;

	tmp = ft_strdup(cmd[0]);
	get_absolute_path(cmd, env_lst);
	if (!*cmd)
		exec_cmd_others2(cmd, env_lst, tmp);
	else
	{
		status = 0;
		pid = fork();
		if (pid == 0)
		{
			dash = put_lst_to_tab(env_lst);
			execve(cmd[0], cmd, dash);
			if (dash != NULL)
				ft_free_tab(&dash);
			exit(EXIT_SUCCESS);
		}
		wait(&status);
		g_exit_status = (status == 0) ? 0 : 1;
	}
	free(tmp);
}

int			search_redir(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '>' || cmd[i][0] == '<')
			return (i);
		else
			i++;
	}
	return (-1);
}

int			search_pipe(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != NULL)
	{
		if (cmd[i][0] == '|')
			return (i);
		else
			i++;
	}
	return (-1);
}

void		exec_command(char **cmd, t_node **env_lst)
{
	int		a;
	int		last_cmd;

	if (cmd && *cmd && g_exit_out == 0 && cmd[0][0])
	{
		if ((a = search_pipe(cmd)) >= 0)
			exec_pipe(cmd, a, env_lst);
		else if ((a = search_redir(cmd)) >= 0)
			exec_redir(cmd, a, env_lst);
		else if ((a = is_builtin_exist(*cmd)) != -1)
			exec_builtin(cmd, env_lst, a);
		else
		{
			last_cmd = count_tab_str(cmd) - 1;
			modify_node_content_value(*env_lst, ft_nodesize(*env_lst) - 1,
								cmd[last_cmd]);
			exec_cmd_others(cmd, *env_lst);
		}
	}
	else if (cmd[0][0] == '\0')
		ft_printf("  : command not found\n");
}
