/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:40:33 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:40:33 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return (0);
	if (!(*alst))
		*alst = new;
	else
		(ft_lstlast(*alst))->next = new;
	return (1);
}
