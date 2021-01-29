/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:43:30 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 13:57:41 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clear_nodelst(t_node **env_lst)
{
	t_node	*tmp;

	while (*env_lst)
	{
		free((*env_lst)->content->name);
		(*env_lst)->content->name = NULL;
		free((*env_lst)->content->value);
		(*env_lst)->content->value = NULL;
		free((*env_lst)->content);
		(*env_lst)->content = NULL;
		tmp = (*env_lst)->next;
		(*env_lst)->previous = NULL;
		free(*env_lst);
		*env_lst = tmp;
	}
}

t_node	*ft_nodelast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

char	*get_value_in_node(t_node *env_lst, char *str)
{
	char	*tmp;

	if (!str || !env_lst)
		return (NULL);
	tmp = ft_strjoin(str, "=");
	while (env_lst)
	{
		if (!(ft_strcmp(env_lst->content->name, tmp)))
		{
			free(tmp);
			return (env_lst->content->value);
		}
		env_lst = env_lst->next;
	}
	free(tmp);
	return (NULL);
}

int		search_name(t_node *env_lst, char *str)
{
	int		found;
	int		i;

	i = 0;
	if (!str || !env_lst)
		return (-1);
	while (env_lst)
	{
		found = ft_strcmp(env_lst->content->name, str);
		if (found == 0)
			return (i);
		env_lst = env_lst->next;
		i++;
	}
	return (-1);
}

int		ft_nodeadd_middle(t_node **alst, t_node *new)
{
	t_node	*last;
	t_node	*previous;

	if (!new || !alst)
		return (0);
	last = ft_nodelast(*alst);
	if (last->previous != NULL)
	{
		previous = last->previous;
		previous->next = new;
		new->previous = previous;
		new->next = last;
		new->head = last->head;
		last->previous = new;
	}
	else
	{
		new->previous = NULL;
		new->head = new;
		last->head = new;
		*alst = new;
	}
	return (1);
}
