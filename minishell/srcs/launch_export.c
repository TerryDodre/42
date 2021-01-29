/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:42:32 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 13:21:11 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	write_invalid_msg(char *cmd)
{
	ft_printf("export: '%s': not a valid identifier\n", cmd);
	g_exit_status = 1;
}

void	insert_node_no_assign(char *cmd, t_node **env_lst)
{
	char	*tmp;
	t_node	*new;

	if (!(is_valid_name(cmd, ft_strlen(cmd))))
		write_invalid_msg(cmd);
	else
	{
		tmp = ft_strjoin(cmd, "=");
		if ((search_name(*env_lst, tmp)) == -1)
		{
			if ((search_name(*env_lst, cmd)) == -1)
			{
				new = ft_new_node(cmd, "\0");
				if (!(ft_nodeadd_middle(env_lst, new)))
				{
					free(tmp);
					ft_clear_nodelst(env_lst);
					return ;
				}
			}
		}
		free(tmp);
	}
}

void	insert_node_2(char *cmd, t_node **env_lst, int assign)
{
	char	*tmp;
	int		name_order;
	t_node	*current;
	t_node	*new;

	tmp = ft_strndup(cmd, assign + 1);
	if ((name_order = search_name(*env_lst, tmp)) >= 0)
		modify_node_content_value(*env_lst, name_order, cmd + assign + 1);
	else
	{
		new = ft_new_env_node(cmd);
		if (!(ft_nodeadd_middle(env_lst, new)))
		{
			ft_clear_nodelst(env_lst);
			return ;
		}
	}
	free(tmp);
}

void	insert_node(char *cmd, t_node **env_lst, int assign)
{
	char	*tmp;
	int		name_order;
	t_node	*current;
	t_node	*new;
	char	*name;

	if (!(is_valid_name(cmd, assign)))
		write_invalid_msg(cmd);
	else
	{
		tmp = ft_strndup(cmd, assign);
		if ((name_order = search_name(*env_lst, tmp)) >= 0)
		{
			name = ft_strndup(cmd, assign + 1);
			modify_node_content(*env_lst, name_order, name, cmd + assign + 1);
			free(name);
		}
		else
			insert_node_2(cmd, env_lst, assign);
		free(tmp);
	}
}

void	launch_export(char **cmd, t_node **env_lst)
{
	int i;
	int	nb_tab;
	int	assign;

	nb_tab = count_tab_str(cmd);
	if (nb_tab == 1)
		sort_export_env(*env_lst);
	else if (nb_tab > 1)
	{
		i = 1;
		while (cmd[i])
		{
			assign = search_char(cmd[i], '=');
			if (assign == 0)
				write_invalid_msg(cmd[i]);
			else if (assign == -1)
				insert_node_no_assign(cmd[i], env_lst);
			else
				insert_node(cmd[i], env_lst, assign);
			i++;
		}
	}
}
