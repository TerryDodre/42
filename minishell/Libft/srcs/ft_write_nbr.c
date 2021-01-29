/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:44:07 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:44:08 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	write_nbr(char *str_nb, int len, int index_zero, t_struct *box)
{
	if (box->neg == 1)
		write(1, "-", 1);
	if (index_zero != 0)
		write_zeros(index_zero, box);
	write_words((const char *)str_nb, len, box);
}

void	add_spaces_n_init(int *len, t_struct *box)
{
	if (box->width != -1)
		write_spaces(box->width, box);
	else if (box->align_left != -1)
		write_spaces(box->align_left, box);
	init_box(box);
	*len = 0;
}

void	do_nbr_align_right(char *str_nb, int len, t_struct *box)
{
	int index_zero;

	index_zero = 0;
	if (box->width > box->precision && box->precision >= len)
		write_spaces((box->width - box->precision), box);
	else if (box->width > box->precision && box->precision < len)
		write_spaces((box->width - len), box);
	index_zero = box->precision - len;
	write_nbr(str_nb, len, index_zero, box);
}

void	do_nbr_align_left(char *str_nb, int len, t_struct *box)
{
	int index_zero;

	index_zero = 0;
	if (box->precision > len)
		index_zero = box->precision - len;
	write_nbr(str_nb, len, index_zero, box);
	if (box->align_left > box->precision && box->precision >= len)
		write_spaces((box->align_left - box->precision), box);
	else if (box->align_left > box->precision && box->precision < len)
		write_spaces((box->align_left - len), box);
}

void	add_spaces_or_zeros(char *str_nb, int len, t_struct *box)
{
	int index_zero;

	index_zero = 0;
	if (box->width != -1 && box->width > len)
		write_spaces((box->width - len), box);
	else if (box->zero != -1 && box->zero > len)
		index_zero = box->zero - len;
	else if (box->precision != -1 && box->precision > len)
		index_zero = box->precision - len;
	write_nbr(str_nb, len, index_zero, box);
	if (box->align_left != -1 && box->align_left > len)
		write_spaces((box->align_left - len), box);
}
