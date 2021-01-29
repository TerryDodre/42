/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:43:30 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 13:57:41 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**put_lst_to_tab(t_node *env_lst)
{
	char	**tab;
	int		i;
	int		size;

	i = 0;
	size = ft_nodesize(env_lst);
	if (!(tab = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (env_lst)
	{
		tab[i] = ft_strjoin(env_lst->content->name, env_lst->content->value);
		if (tab[i] == NULL)
			return (ft_free_tmp(tab, i));
		env_lst = env_lst->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		ft_nodeadd_back(t_node **alst, t_node *new)
{
	t_node	*ptr;

	if (!new || !alst)
		return (0);
	if (!(*alst))
		*alst = new;
	else
	{
		ptr = ft_nodelast(*alst);
		new->previous = ptr;
		new->head = ptr->head;
		ptr->next = new;
	}
	return (1);
}

int		add_pwd_node(t_node **env_lst)
{
	t_node	*pwd;
	char	buff[4096 + 1];

	getcwd(buff, 4096);
	pwd = ft_new_node("PWD=", buff);
	if (!(ft_nodeadd_back(env_lst, pwd)))
	{
		ft_clear_nodelst(env_lst);
		return (0);
	}
	return (1);
}

int		add_pwd_node_middle(t_node **env_lst)
{
	t_node	*pwd;
	char	buff[4096 + 1];

	getcwd(buff, 4096);
	pwd = ft_new_node("PWD=", buff);
	if (!(ft_nodeadd_middle(env_lst, pwd)))
	{
		ft_clear_nodelst(env_lst);
		return (0);
	}
	return (1);
}

int		check_env_lst(t_node **env_lst)
{
	t_node	*shlvl;
	int		name_order;
	int		nb_shell;
	char	*tmp;

	if ((search_name(*env_lst, "PWD=")) == -1)
		if (!(add_pwd_node_middle(env_lst)))
			return (0);
	if ((name_order = search_name(*env_lst, "SHLVL=")) >= 0)
	{
		nb_shell = ft_atoi(get_value_in_node(*env_lst, "SHLVL")) + 1;
		tmp = ft_itoa(nb_shell);
		modify_node_content_value(*env_lst, name_order, tmp);
		free(tmp);
	}
	else
	{
		shlvl = ft_new_node("SHLVL=", "1");
		if (!(ft_nodeadd_middle(env_lst, shlvl)))
		{
			ft_clear_nodelst(env_lst);
			return (0);
		}
	}
	return (1);
}
