/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:23:44 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:23:45 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		prompt_wait_ctr_c(char *prompt)
{
	if (g_path_prompt != NULL)
	{
		free(g_path_prompt);
		g_path_prompt = NULL;
	}
	g_path_prompt = ft_strdup(prompt);
}

void		prompt_wait_command(t_node *env_lst)
{
	char	*path;
	char	*cwd;
	char	*prompt;
	char	buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	path = ft_strdup(get_value_in_node(env_lst, "HOME"));
	if (ft_strcmp(path, cwd) >= 0)
		prompt = ft_strdup(cwd);
	else
		prompt = ft_strjoin("~", cwd + ft_strlen(path));
	prompt_wait_ctr_c(prompt);
	if (g_signal_status == 0)
	{
		ft_putstr_fd("\e[103m\e[30m ", 1);
		ft_putstr_fd(prompt, 1);
		ft_putstr_fd(" \e[0m", 1);
		ft_putstr_fd("\e[93m - $> \e[0m", 1);
	}
	free(prompt);
	free(path);
	prompt = NULL;
	path = NULL;
}

int			prompt_command_not_found(char *buffer)
{
	ft_putstr_fd(buffer, 1);
	ft_putstr_fd(" : command not found", 1);
	ft_putstr_fd("\n", 1);
	return (1);
}

void		ft_exit(char *buffer, t_node **env_lst)
{
	free(g_path_prompt);
	free(buffer);
	ft_clear_nodelst(env_lst);
	ft_printf("exit\n");
}
