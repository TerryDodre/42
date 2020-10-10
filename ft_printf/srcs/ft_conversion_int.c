/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:01:49 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/09 14:10:58 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_write_conversion_int(long int a, int b, t_flags **flags, int c)
{
	if (b != 0 || (**flags).precision_exist != 1 || (**flags).precision != 0)
	{
		if (a < 0)
		{
			ft_write('-', &flags);
			a = -a;
		}
		while (c > 0)
		{
			ft_write('0', &flags);
			c--;
		}
		if (a > 9)
			ft_write_conversion_int(a / 10, b, flags, c);
		ft_write(a % 10 + 48, &flags);
	}
}

int			ft_write_zero_int(long int a, int b, t_flags **ap)
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

int			ft_count_nb(long int a, t_flags **flags)
{
	int		b;

	b = 0;
	if (a == 0 && ((**flags).precision_exist != 1 || (**flags).precision != 0))
		b = 1;
	if (a < 0)
	{
		a = -a;
		b++;
	}
	while (a > 0)
	{
		a = a / 10;
		b++;
	}
	return (b);
}

void		ft_conversion_int(va_list args, t_flags **flags)
{
	long int		a;
	int				b;
	int				c;

	a = va_arg(args, int);
	b = ft_count_nb(a, flags);
	b = ft_write_zero_int(a, b, flags);
	if ((**flags).precision == b && a < 0)
		b++;
	if ((**flags).nb_exist == 1)
		ft_write_space((**flags).nb - b, &flags);
	c = b - ft_count_nb(a, flags);
	ft_write_conversion_int(a, a, flags, c);
	if ((**flags).size_exist == 1)
		ft_write_space((**flags).size - b, &flags);
}
