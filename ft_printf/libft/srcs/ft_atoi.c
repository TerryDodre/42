/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:06:21 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/08 17:02:49 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_atoi(const char *s)
{
	int		ret;
	int		sign;

	ret = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || (*s == ' '))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s) == 1)
	{
		ret = ret * 10 + (*s - 48);
		s++;
	}
	return (ret * sign);
}
