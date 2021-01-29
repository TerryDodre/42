/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:41:44 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:41:45 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	init_box(t_struct *box)
{
	box->width = -1;
	box->align_left = -1;
	box->zero = -1;
	box->precision = -1;
	box->option = -1;
	box->snull = -1;
	box->neg = 0;
	box->precision_neg = 0;
}

void	init_tab_index(char *tab_index)
{
	tab_index[0] = 'c';
	tab_index[1] = 's';
	tab_index[2] = 'd';
	tab_index[3] = 'i';
	tab_index[4] = 'u';
	tab_index[5] = 'x';
	tab_index[6] = 'X';
	tab_index[7] = 'p';
	tab_index[8] = '%';
	tab_index[9] = 0;
}

void	apply_conversion(int index, va_list *ap, t_struct *box)
{
	void	(*ptr_function[8]) (va_list *, t_struct *);

	ptr_function[0] = &convert_char;
	ptr_function[1] = &convert_str;
	ptr_function[2] = &convert_decimal;
	ptr_function[3] = &convert_decimal;
	ptr_function[4] = &convert_unsigned_int;
	ptr_function[5] = &convert_hexa;
	ptr_function[6] = &convert_hexa_cap;
	ptr_function[7] = &convert_address;
	(*ptr_function[index])(ap, box);
}
