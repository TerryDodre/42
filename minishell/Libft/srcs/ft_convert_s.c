/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:38:52 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:38:53 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		str_null(t_struct *box, char **str)
{
	box->snull = 1;
	*str = ft_strdup("(null)");
	return (6);
}

void	do_str_align_right(char *str, int len, t_struct *box)
{
	if (box->precision == -1)
	{
		if (box->width > len)
			write_spaces((box->width - len), box);
		write_words(str, len, box);
	}
	else
	{
		if ((box->width) <= (box->precision) && (box->precision) < len)
			write_words(str, box->precision, box);
		else
		{
			if (box->precision >= len)
				box->precision = len;
			write_spaces((box->width) - (box->precision), box);
			write_words(str, box->precision, box);
		}
	}
}

void	do_str_align_left(char *str, int len, t_struct *box)
{
	if (box->precision == -1)
	{
		write_words(str, len, box);
		if (box->align_left > len)
			write_spaces((box->align_left - len), box);
	}
	else
	{
		if ((box->align_left) <= (box->precision) && (box->precision) < len)
			write_words(str, box->precision, box);
		else
		{
			if (box->precision >= len)
				box->precision = len;
			write_words(str, box->precision, box);
			write_spaces((box->align_left) - (box->precision), box);
		}
	}
}

void	convert_str(va_list *ap, t_struct *box)
{
	char	*str;
	int		len;

	str = va_arg(*ap, char *);
	if (str == NULL)
		len = str_null(box, &str);
	else
		len = (box->precision == 0 ? 0 : ft_strlen(str));
	if (box->precision_neg == 1 && box->precision < 0)
		box->precision = len;
	if (box->width != -1)
		do_str_align_right(str, len, box);
	else if (box->align_left != -1)
		do_str_align_left(str, len, box);
	else if (box->precision != -1)
	{
		if (box->precision > len)
			box->precision = len;
		write_words(str, box->precision, box);
	}
	else
		write_words(str, len, box);
	if (box->snull == 1)
		free(str);
}
