/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uxp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:39:00 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:39:02 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	convert_hexa(va_list *ap, t_struct *box)
{
	unsigned int	nb;
	int				len;
	char			*str_nb;

	nb = va_arg(*ap, int);
	str_nb = ft_utoa_base(nb, "0123456789abcdef");
	len = ft_strlen(str_nb);
	if (box->zero != -1 && box->precision != -1)
	{
		box->width = box->zero;
		box->zero = -1;
	}
	if (box->precision == 0 && nb == 0)
		add_spaces_n_init(&len, box);
	if (box->width != -1 && box->precision != -1)
		do_nbr_align_right(str_nb, len, box);
	else if (box->align_left != -1 && box->precision != -1)
		do_nbr_align_left(str_nb, len, box);
	else
		add_spaces_or_zeros(str_nb, len, box);
	free(str_nb);
}

void	convert_hexa_cap(va_list *ap, t_struct *box)
{
	unsigned int	nb;
	int				len;
	char			*str_nb;

	nb = va_arg(*ap, int);
	str_nb = ft_utoa_base(nb, "0123456789ABCDEF");
	len = ft_strlen(str_nb);
	if (box->zero != -1 && box->precision != -1)
	{
		box->width = box->zero;
		box->zero = -1;
	}
	if (box->precision == 0 && nb == 0)
		add_spaces_n_init(&len, box);
	if (box->width != -1 && box->precision != -1)
		do_nbr_align_right(str_nb, len, box);
	else if (box->align_left != -1 && box->precision != -1)
		do_nbr_align_left(str_nb, len, box);
	else
		add_spaces_or_zeros(str_nb, len, box);
	free(str_nb);
}

void	convert_unsigned_int(va_list *ap, t_struct *box)
{
	unsigned int	nb;
	int				len;
	char			*str_nb;

	nb = va_arg(*ap, int);
	str_nb = ft_utoa_base(nb, "0123456789");
	len = ft_strlen(str_nb);
	if (box->zero != -1 && box->precision != -1)
	{
		box->width = box->zero;
		box->zero = -1;
	}
	if (box->precision == 0 && nb == 0)
		add_spaces_n_init(&len, box);
	if (box->width != -1 && box->precision != -1)
		do_nbr_align_right(str_nb, len, box);
	else if (box->align_left != -1 && box->precision != -1)
		do_nbr_align_left(str_nb, len, box);
	else
		add_spaces_or_zeros(str_nb, len, box);
	free(str_nb);
}

void	convert_address(va_list *ap, t_struct *box)
{
	unsigned long	nb_decimal;
	void			*pointer;
	char			*str_nb;
	int				len;

	pointer = va_arg(*ap, void *);
	nb_decimal = (uintmax_t)pointer;
	str_nb = ft_utoa_base(nb_decimal, "0123456789abcdef");
	len = ft_strlen(str_nb);
	(box->value) += 2;
	if (box->precision == 0 && pointer == 0)
		len = 0;
	if (box->width != -1)
		write_spaces(box->width - len - 2, box);
	write(1, "0x", 2);
	write_words(str_nb, len, box);
	if (box->align_left != -1)
		write_spaces(box->align_left - len - 2, box);
	free(str_nb);
}
