/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:42:23 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 14:01:59 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_node(t_node **env_lst, int name_order)
{
	int		size;
	t_node	*current;

	size = ft_nodesize(*env_lst);
	current = ft_node_find(*env_lst, name_order);
	if (name_order == 0)
	{
		(*env_lst) = (*env_lst)->next;
		(*env_lst)->previous = NULL;
	}
	else if (name_order > 0 && name_order < size - 1)
	{
		current->previous->next = current->next;
		current->next->previous = current->previous;
	}
	else if (name_order == size - 1)
		current->previous->next = NULL;
	free(current->content->name);
	current->content->name = NULL;
	free(current->content->value);
	current->content->value = NULL;
	free(current->content);
	current->content = NULL;
	free(current);
}

void	match_name(char *cmd, t_node **env_lst)
{
	int		name_order;
	char	*tmp;
	int		size;

	size = ft_nodesize(*env_lst);
	name_order = search_name(*env_lst, cmd);
	if (name_order >= 0 && size > 1)
		delete_node(env_lst, name_order);
	else if (name_order >= 0 && size == 1)
		ft_clear_nodelst(env_lst);
	else if (name_order == -1)
	{
		tmp = ft_strjoin(cmd, "=");
		name_order = search_name(*env_lst, tmp);
		if (name_order == size - 1)
			modify_node_content_value(*env_lst, name_order, "_");
		else if (name_order >= 0 && name_order != size - 1)
			delete_node(env_lst, name_order);
		free(tmp);
	}
}

void	launch_unset(char **cmd, t_node **env_lst)
{
	int i;
	int	nb_cmd;

	i = 1;
	nb_cmd = count_tab_str(cmd);
	if (nb_cmd > 1)
	{
		while (cmd[i])
		{
			if (!(is_valid_name(cmd[i], ft_strlen(cmd[i]))))
			{
				ft_printf("unset: '%s': not a valid identifier\n", cmd[i]);
				g_exit_status = 1;
			}
			else
				match_name(cmd[i], env_lst);
			i++;
		}
	}
}
