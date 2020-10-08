/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:16:15 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/08 17:52:43 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		count_size_nb(long n)
{
	int		i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		size_nb;
	char	*tmp;

	nb = n;
	size_nb = count_size_nb(nb) - 1;
	if (!(tmp = ft_calloc(sizeof(char), size_nb + 2)))
		return (NULL);
	if (nb == 0)
		tmp[0] = '0';
	else
	{
		if (nb < 0)
		{
			tmp[0] = '-';
			nb = -nb;
		}
		while (size_nb >= 0 && tmp[size_nb] == '\0')
		{
			tmp[size_nb--] = 48 + (nb % 10);
			nb /= 10;
		}
	}
	return (tmp);
}
