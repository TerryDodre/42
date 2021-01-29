/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_export_sorting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:42:50 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 13:22:40 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_node	*colon_new_node(t_node *env_lst)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	if (!(new->content = (t_pair *)malloc(sizeof(t_pair))))
		return (NULL);
	if (!(new->content->name = ft_strdup(env_lst->content->name)))
		return (NULL);
	if (!(new->content->value = ft_strdup(env_lst->content->value)))
		return (NULL);
	new->head = new;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	compare_list(t_node *begin, t_node **second, int *j)
{
	while (*second)
	{
		if ((ft_strcmp(begin->content->name, (*second)->content->name)) <= 0)
		{
			*second = (*second)->next;
			(*j)++;
		}
		else
			break ;
	}
}

int		find_smallest(t_node *list)
{
	t_node	*begin;
	t_node	*second;
	int		size;
	int		i;
	int		j;

	i = 0;
	if (!list)
		return (-1);
	begin = list;
	size = ft_nodesize(list);
	while (begin)
	{
		j = i + 1;
		second = begin->next;
		compare_list(begin, &second, &j);
		if (j == size)
			return (i);
		begin = second;
		i = j;
	}
	return (-1);
}

t_node	*print_sorting_lst(t_node *list)
{
	t_node	*smallest;
	int		name_order;
	int		size;
	int		assign;

	size = ft_nodesize(list);
	if ((name_order = find_smallest(list)) == -1)
		return (NULL);
	smallest = ft_node_find(list, name_order);
	assign = search_char(smallest->content->name, '=');
	if (assign == -1)
		ft_printf("declare -x %s\n", smallest->content->name);
	else if ((ft_strcmp("_=", smallest->content->name)) != 0)
		ft_printf("declare -x %s\"%s\"\n", smallest->content->name,
					smallest->content->value);
	if (size == 1)
		ft_clear_nodelst(&list);
	else
		delete_node(&list, name_order);
	return (list);
}

void	sort_export_env(t_node *env_lst)
{
	t_node	*new;
	t_node	*copy;

	copy = NULL;
	while (env_lst)
	{
		if (!(new = colon_new_node(env_lst)))
			return ;
		if (!(ft_nodeadd_back(&copy, new)))
		{
			ft_clear_nodelst(&copy);
			return ;
		}
		env_lst = env_lst->next;
	}
	while (copy)
		copy = print_sorting_lst(copy);
}
