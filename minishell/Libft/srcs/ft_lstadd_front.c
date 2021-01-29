/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:40:37 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:40:38 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return (0);
	new->next = *alst;
	*alst = new;
	return (1);
}
