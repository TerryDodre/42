/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:38:42 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:38:43 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	convert_char(va_list *ap, t_struct *box)
{
	char	c;

	c = va_arg(*ap, int);
	(box->value)++;
	if (box->width != -1)
		write_spaces(box->width - 1, box);
	write(1, &c, 1);
	if (box->align_left != -1)
		write_spaces(box->align_left - 1, box);
}

void	convert_percentage(t_struct *box)
{
	char	c;

	c = '%';
	(box->value)++;
	if (box->width != -1)
		write_spaces(box->width - 1, box);
	else if (box->zero != -1)
		write_zeros(box->zero - 1, box);
	write(1, &c, 1);
	if (box->align_left != -1)
		write_spaces(box->align_left - 1, box);
}
