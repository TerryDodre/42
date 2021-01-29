/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_export_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:42:43 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 13:21:54 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_node	*ft_node_find(t_node *env_lst, int order)
{
	int	i;

	i = 0;
	if (!env_lst || order < 0)
		return (NULL);
	while (i < order)
	{
		env_lst = env_lst->next;
		i++;
	}
	return (env_lst);
}

int		ft_nodesize(t_node *lst)
{
	int i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_node	*ft_new_node(char *name, char *value)
{
	t_node	*new;
	int		assign;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	if (!(new->content = (t_pair *)malloc(sizeof(t_pair))))
		return (NULL);
	new->content->name = ft_strdup(name);
	new->content->value = ft_strdup(value);
	new->previous = NULL;
	new->head = new;
	new->next = NULL;
	return (new);
}

void	modify_node_content_value(t_node *env_lst, int order, char *value)
{
	t_node	*node;

	node = ft_node_find(env_lst, order);
	free(node->content->value);
	node->content->value = ft_strdup(value);
}

void	modify_node_content(t_node *env_lst, int order, char *name, char *value)
{
	t_node	*node;

	node = ft_node_find(env_lst, order);
	free(node->content->name);
	free(node->content->value);
	node->content->name = ft_strdup(name);
	node->content->value = ft_strdup(value);
}
