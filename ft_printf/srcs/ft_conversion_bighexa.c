/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_bighexa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:20:20 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/09 14:35:08 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_write_conversion_bighexa(long int a, int b, t_flags **ap, int c)
{
	if (b != 0 || (**ap).precision_exist != 1 || (**ap).precision != 0)
	{
		while (c-- > 0)
			ft_write('0', &ap);
		if (a > 15)
		{
			ft_write_conversion_bighexa(a / 16, b, ap, c);
			ft_write_conversion_bighexa(a % 16, b, ap, c);
		}
		else if (a < 10)
			ft_write((a + 48), &ap);
		else
		{
			a == 10 ? ft_write('A', &ap) : 0;
			a == 11 ? ft_write('B', &ap) : 0;
			a == 12 ? ft_write('C', &ap) : 0;
			a == 13 ? ft_write('D', &ap) : 0;
			a == 14 ? ft_write('E', &ap) : 0;
			a == 15 ? ft_write('F', &ap) : 0;
		}
	}
}

int			ft_write_zero_bighexa(long int a, int b, t_flags **ap)
{
	if ((**ap).zero_exist == 1 && (**ap).zero > b)
	{
		if ((**ap).precision_exist == 1 && (**ap).precision < (**ap).zero)
		{
			if (a != 0 && (**ap).precision == 0)
				ft_write_space((**ap).zero - b, &ap);
			else if ((**ap).precision >= b || a == 0)
			{
				if (a < 0)
					ft_write_space((**ap).zero - ((**ap).precision + 1), &ap);
				else
					ft_write_space((**ap).zero - ((**ap).precision), &ap);
			}
			else
				ft_write_space((**ap).zero - b, &ap);
			b = (**ap).precision;
		}
		else if ((**ap).precision > (**ap).zero)
			b = (**ap).precision;
		else
			b = (**ap).zero;
	}
	else if ((**ap).precision_exist == 1 && (**ap).precision > b)
		b = (**ap).precision;
	return (b);
}

int			ft_count_bighexa(long int a, t_flags **ap)
{
	int		b;

	b = 0;
	if (a == 0 && ((**ap).precision_exist != 1 || (**ap).precision != 0))
		b = 1;
	while (a > 0)
	{
		a = a / 16;
		b++;
	}
	return (b);
}

void		ft_conversion_bighexa(va_list args, t_flags **flags)
{
	long int	a;
	int			b;
	int			c;

	a = va_arg(args, long int);
	if (a >= 0)
		b = ft_count_bighexa(a, flags);
	else
	{
		b = 8;
		a = 4294967296 - (-a);
	}
	b = ft_write_zero_bighexa(a, b, flags);
	if ((**flags).precision == b && a < 0)
		b++;
	if ((**flags).nb_exist == 1)
		ft_write_space((**flags).nb - b, &flags);
	c = b - ft_count_bighexa(a, flags);
	ft_write_conversion_bighexa(a, a, flags, c);
	if ((**flags).size_exist == 1)
		ft_write_space((**flags).size - b, &flags);
}
