/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:38:36 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:38:37 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	len;
	int				*area;

	len = size * count;
	if (!(area = malloc(len)))
		return (NULL);
	return (ft_memset(area, '\0', len));
}
