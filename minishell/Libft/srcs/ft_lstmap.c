/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:40:58 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:40:59 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*current;

	if (lst && f)
	{
		if (!(current = ft_lstnew((*f)(lst->content))))
			return (NULL);
		first = current;
		lst = lst->next;
		while (lst)
		{
			if (!(current->next = ft_lstnew((*f)(lst->content))))
			{
				ft_lstclear(&first, (*del));
				return (NULL);
			}
			current = current->next;
			lst = lst->next;
		}
		return (first);
	}
	return (NULL);
}
