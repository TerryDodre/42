/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:58:46 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/09 14:01:19 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_write_conversion_pointer(unsigned long int a,
				unsigned long int b, t_flags **flags)
{
	if ((**flags).precision_exist == 0 || b > 0)
	{
		if (a > 15)
		{
			ft_write_conversion_pointer(a / 16, b, flags);
			ft_write_conversion_pointer(a % 16, b, flags);
		}
		else if (a < 10)
			ft_write((a + 48), &flags);
		else
		{
			a == 10 ? ft_write('a', &flags) : 0;
			a == 11 ? ft_write('b', &flags) : 0;
			a == 12 ? ft_write('c', &flags) : 0;
			a == 13 ? ft_write('d', &flags) : 0;
			a == 14 ? ft_write('e', &flags) : 0;
			a == 15 ? ft_write('f', &flags) : 0;
		}
	}
}

int			ft_count_pointer(unsigned long int a)
{
	int		b;

	b = 0;
	if (a == 0)
		b = 1;
	while (a > 0)
	{
		a = a / 16;
		b++;
	}
	return (b);
}

void		ft_conversion_pointer(va_list args, t_flags **flags)
{
	void	*pointer;
	int		a;

	pointer = va_arg(args, char *);
	a = ft_count_pointer((uintmax_t)pointer) + 2;
	if ((**flags).nb_exist == 1)
		ft_write_space((**flags).nb - a, &flags);
	ft_write('0', &flags);
	ft_write('x', &flags);
	ft_write_conversion_pointer((uintmax_t)pointer, (uintmax_t)pointer, flags);
	if ((**flags).size_exist == 1)
		ft_write_space((**flags).size - a, &flags);
}
