/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:40:01 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:40:02 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_tab(char ***tab)
{
	int	count;

	if (!tab)
		return ;
	count = 0;
	while ((*tab)[count])
	{
		free((*tab)[count]);
		count++;
	}
	free(*tab);
	*tab = NULL;
}
