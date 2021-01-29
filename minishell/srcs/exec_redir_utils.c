/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:25:49 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:45:18 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**get_cmd_redir_continue(char **cmd, char c, char **tmp, int i)
{
	if (!(tmp = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (*cmd != NULL)
	{
		if (*cmd[0] != c)
		{
			tmp[i] = ft_strdup(*cmd);
			i++;
		}
		else if (cmd[1][0] != c)
			cmd++;
		cmd++;
	}
	tmp[i] = NULL;
	return (tmp);
}

char		**get_cmd_redir(char **cmd, char c)
{
	int			num;
	int			i;
	char		**tmp;

	num = 0;
	i = 0;
	while (cmd[num])
	{
		if (cmd[num][0] != c)
			i++;
		num++;
	}
	if (cmd[0][0] == c)
		return (NULL);
	return (get_cmd_redir_continue(cmd, c, tmp, i));
}

void		check_behind(char **cmd, int a, int fd, t_node **env_lst)
{
	int		i;
	pid_t	pid;
	int		status;

	pid = fork();
	if (cmd[a - 1][0] == '>')
		exec_out_redir(cmd + a + 1, fd, env_lst, pid);
	else
		exec_in_redir(cmd + a + 1, fd, env_lst, pid);
	wait(&status);
}
