/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:43:00 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 13:18:50 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fill_content(int assign, t_pair *content, char *str)
{
	assign = search_char(str, '=');
	if (assign > 0)
	{
		if (!(content->name = ft_strndup(str, assign + 1)))
			return ;
		if (!(content->value = ft_strdup(str + assign + 1)))
			return ;
	}
	else if (assign == -1)
	{
		if (!(content->name = ft_strdup(str)))
			return ;
		if (!(content->value = ft_strdup("\0")))
			return ;
	}
}

t_node	*ft_new_env_node(char *str)
{
	t_node	*new;
	int		assign;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	if (!(new->content = (t_pair *)malloc(sizeof(t_pair))))
		return (NULL);
	if (!str)
		return (NULL);
	else
	{
		assign = search_char(str, '=');
		fill_content(assign, new->content, str);
	}
	new->previous = NULL;
	new->head = new;
	new->next = NULL;
	return (new);
}

void	create_new_env(t_node **env_lst)
{
	t_node	*shlvl;
	t_node	*last_cmd;

	if (!(add_pwd_node(env_lst)))
		return ;
	shlvl = ft_new_node("SHLVL=", "1");
	if (!(ft_nodeadd_back(env_lst, shlvl)))
	{
		ft_clear_nodelst(env_lst);
		return ;
	}
	last_cmd = ft_new_node("_=", "./minishell");
	if (!(ft_nodeadd_back(env_lst, last_cmd)))
	{
		ft_clear_nodelst(env_lst);
		return ;
	}
}

t_node	*create_env_lst(char **sys_env)
{
	int		i;
	t_node	*new_node;
	t_node	*env_lst;

	i = 0;
	env_lst = NULL;
	if (!*sys_env)
	{
		create_new_env(&env_lst);
		return (env_lst);
	}
	while (sys_env[i])
	{
		if (!(new_node = ft_new_env_node(sys_env[i])))
			return (NULL);
		if (!(ft_nodeadd_back(&env_lst, new_node)))
		{
			ft_clear_nodelst(&env_lst);
			return (NULL);
		}
		i++;
	}
	check_env_lst(&env_lst);
	return (env_lst);
}

void	launch_env(t_node *env_lst)
{
	int assign;

	if (!env_lst)
		return ;
	while (env_lst)
	{
		assign = search_char(env_lst->content->name, '=');
		if (assign > 0)
			ft_printf("%s%s\n", env_lst->content->name,
						env_lst->content->value);
		env_lst = env_lst->next;
	}
}
