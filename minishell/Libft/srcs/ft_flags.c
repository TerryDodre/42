/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:39:56 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:39:58 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		put_width(const char *format, int *pos, t_struct *box)
{
	box->width = get_int(format, pos);
	return (1);
}

int		put_align_left(const char *format, int *pos, t_struct *box)
{
	box->align_left = get_int(format, pos);
	return (1);
}

int		put_precision(const char *format, int *pos, t_struct *box)
{
	box->precision = get_int(format, pos);
	return (1);
}

int		put_option(int *pos, va_list *ap, t_struct *box)
{
	int		i;

	i = va_arg(*ap, int);
	if (box->width == -1 && box->option == -1 && box->precision != 0 &&
		box->align_left != 0 && box->zero != 0)
	{
		box->width = (i >= 0 ? i : -1);
		box->align_left = (i < 0 ? -(i) : -1);
		box->option = 1;
	}
	else if (box->align_left == 0 && box->option == -1 && box->precision != 0)
		box->align_left = (i < 0 ? -(i) : i);
	else if (box->zero == 0 && box->option == -1 && box->precision != 0)
	{
		box->zero = (i >= 0 ? i : -1);
		box->align_left = (i < 0 ? -(i) : -1);
	}
	else if (box->option == 1 || box->precision == 0)
	{
		box->precision_neg = 1;
		box->precision = i;
	}
	(*pos)++;
	return (1);
}

int		put_zero(const char *format, int *pos, t_struct *box)
{
	box->zero = get_int(format, pos);
	return (1);
}
