/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:40:48 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:40:49 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lst_find(t_list *env_lst, int lst_index)
{
	int	i;

	i = 0;
	if (!env_lst)
		return (NULL);
	while (i < lst_index)
	{
		env_lst = env_lst->next;
		i++;
	}
	return (env_lst);
}
