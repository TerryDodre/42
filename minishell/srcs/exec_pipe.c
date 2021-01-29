/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:25:53 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:25:54 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		first_cmd(int pid, char **cmd, int fd[2], t_node **env_lst)
{
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_command(cmd, env_lst);
		exit(EXIT_SUCCESS);
	}
}

void		second_cmd(int pid, char **cmd, int fd[2], t_node **env_lst)
{
	if (pid == 0 && g_exit_out == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_command(cmd, env_lst);
		exit(EXIT_SUCCESS);
	}
}

char		**get_cmd_pipe(char **cmd)
{
	int		i;
	char	**tmp;

	i = 0;
	while (cmd[i] != NULL && cmd[i][0] != '|')
		i++;
	if (!(tmp = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (*cmd != NULL && cmd[0][0] != '|')
	{
		tmp[i] = ft_strdup(*cmd);
		i++;
		cmd++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void		exec_pipe(char **cmd, int a, t_node **env_lst)
{
	int		fd[2];
	int		pid[2];
	int		status[2];
	char	**tmp;

	pipe(fd);
	tmp = get_cmd_pipe(cmd);
	if (tmp)
	{
		pid[0] = fork();
		first_cmd(pid[0], tmp, fd, env_lst);
		pid[1] = fork();
		second_cmd(pid[1], cmd + a + 1, fd, env_lst);
		if (ft_strcmp(cmd[a + 1], "exit") == 0)
			pipe_exit(cmd + a + 1);
		close(fd[0]);
		close(fd[1]);
		wait(&status[0]);
		wait(&status[1]);
		ft_free_tab(&tmp);
		tmp = NULL;
	}
}
