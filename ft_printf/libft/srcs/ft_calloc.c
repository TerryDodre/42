/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:15:37 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/08 15:19:50 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned long	i;
	int				*tmp;

	i = nmemb * size;
	if (!(tmp = malloc(i)))
		return (NULL);
	return (ft_memset(tmp, '\0', i));
}
