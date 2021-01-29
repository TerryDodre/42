/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:25:18 by terry             #+#    #+#             */
/*   Updated: 2020/11/28 14:21:53 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_initial(char *buffer, char **tmp, t_node **env_lst, char **env)
{
	buffer = NULL;
	tmp = NULL;
	g_exit_status = 0;
	g_exit_out = 0;
	g_path_prompt = NULL;
	*env_lst = create_env_lst(env);
	prompt_wait_command(*env_lst);
	signal(SIGINT, (void *)signal_control);
	signal(SIGQUIT, (void *)signal_control);
}

void	main_loop(char *tmp, t_node **env_lst)
{
	char	**cmd;

	cmd = NULL;
	cmd = cmd_without_quote(ft_split_cmd(tmp));
	if (cmd != NULL)
		exec_command(cmd, env_lst);
	if (cmd != NULL)
		ft_free_tab(&cmd);
}

int		main(int argc, char **argv, char **env)
{
	char	*buffer;
	char	**tmp;
	int		i;
	t_node	*env_lst;

	ft_initial(buffer, tmp, &env_lst, env);
	while (get_next_line(0, &buffer) > 0)
	{
		i = 0;
		tmp = ft_parsing(buffer, env_lst);
		while (tmp != NULL && tmp[i] && tmp[i][0] && g_exit_out == 0)
		{
			main_loop(tmp[i], &env_lst);
			i++;
		}
		if (tmp != NULL)
			ft_free_tab(&tmp);
		if (g_exit_out == 1)
			break ;
		prompt_wait_command(env_lst);
		free(buffer);
	}
	ft_exit(buffer, &env_lst);
	return (g_exit_status);
}
