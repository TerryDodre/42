/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:25:45 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:25:45 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		exec_in_redir(char **cmd, int fd, t_node **env_lst, pid_t pid)
{
	if (pid == 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		exec_command(cmd, env_lst);
		exit(EXIT_SUCCESS);
	}
}

void		exec_out_redir(char **cmd, int fd, t_node **env_lst, pid_t pid)
{
	if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
		exec_command(cmd, env_lst);
		exit(EXIT_SUCCESS);
	}
}

void		exec_redir_choose(char **tmp, int fd, t_node **env_lst, char c)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (c == '>')
		exec_out_redir(tmp, fd, env_lst, pid);
	else
		exec_in_redir(tmp, fd, env_lst, pid);
	wait(&status);
	g_exit_status = (status == 0) ? 0 : 127;
}

void		exec_redir_continue(char **cmd, int a, t_node **env_lst, int fd)
{
	int		i;
	char	**tmp;
	int		index;

	if (cmd[a + 1] && cmd[a + 1][0] == '>')
		exec_redir(cmd, a + 1, env_lst);
	else if (cmd[0][0] != '>')
	{
		tmp = get_cmd_redir(cmd, cmd[a - 1][0]);
		index = is_builtin_exist(tmp[0]);
		if (index == -1)
			get_absolute_path(tmp, *env_lst);
		if (index != -1 || tmp[0] != NULL)
			exec_redir_choose(tmp, fd, env_lst, cmd[a - 1][0]);
		else
			prompt_command_not_found(cmd[0]);
		ft_free_tab(&tmp);
		tmp = NULL;
	}
	else
		check_behind(cmd, a, fd, env_lst);
}

void		exec_redir(char **cmd, int a, t_node **env_lst)
{
	int		fd;
	char	**tmp;
	pid_t	pid;

	fd = -1;
	if (cmd[a][0] == '>' && cmd[a + 1] && cmd[a + 1][0] != '>')
		fd = open(cmd[a + 1], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	else if (cmd[a][0] == '>' && cmd[a + 1] && cmd[a + 1][0] == '>')
	{
		fd = open(cmd[a + 2], O_WRONLY | O_CREAT | O_APPEND, 0744);
		a++;
	}
	else if (cmd[a][0] == '<' && cmd[a + 1])
		fd = open(cmd[a + 1], O_RDONLY, 0644);
	a++;
	if (fd < 0)
	{
		if (cmd[a])
			ft_printf("%s : no such file or directory\n", cmd[a]);
		else
			ft_printf("$ : ambiguous redirect\n");
		g_exit_status = 1;
	}
	else
		exec_redir_continue(cmd, a, env_lst, fd);
}
