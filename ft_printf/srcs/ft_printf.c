/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:58:24 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/10 10:09:37 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_parse_conversion(const char **str, va_list args, t_flags *flags)
{
	if (**str == 'c')
		ft_conversion_char(args, &flags);
	else if (**str == 's')
		ft_conversion_string(args, &flags);
	else if (**str == 'p')
		ft_conversion_pointer(args, &flags);
	else if (**str == 'd' || **str == 'i')
		ft_conversion_int(args, &flags);
	else if (**str == 'u')
		ft_conversion_unsint(args, &flags);
	else if (**str == 'x')
		ft_conversion_littlehexa(args, &flags);
	else if (**str == 'X')
		ft_conversion_bighexa(args, &flags);
	else if (**str == '%')
		ft_conversion_porcent(&flags);
	else
		return (-1);
	(*str)++;
	return (0);
}

int		ft_parse_flags(const char **str, va_list args, t_flags *flags)
{
	while (**str)
	{
		if (**str > '0' && **str <= '9')
			*str += ft_flags_nbr(str, &flags, 0);
		if (**str == '.' && (*flags).precision_exist == 0)
			*str += ft_flags_precision(str, args, &flags, 0);
		else if (**str == '.')
			return (-1);
		if (**str == '-' && (*flags).size_exist == 0)
			*str += ft_flag_size(str, args, &flags, 0);
		else if (**str == '-')
			return (-1);
		if (**str == '0' && (*flags).zero_exist == 0)
			*str += ft_flags_zero(str, args, &flags, 0);
		else if (**str == '0')
			return (-1);
		if (**str == '*' && (*flags).nb_exist == 0)
			*str += ft_flags_args(args, &flags, 0);
		else if (**str == '*')
			return (-1);
		if (**str != '.' && **str != '-' && **str != '0' && **str != '*')
			return (0);
	}
	return (-1);
}

void	ft_ini_struct(t_flags *flags)
{
	(flags)->nb_exist = 0;
	(flags)->precision_exist = 0;
	(flags)->size_exist = 0;
	(flags)->zero_exist = 0;
	(flags)->nb = 0;
	(flags)->precision = 0;
	(flags)->size = 0;
	(flags)->zero = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;

	va_start(args, str);
	(flags).value = 0;
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			ft_ini_struct(&flags);
			if (ft_parse_flags(&str, args, &flags) == -1)
				return (-1);
			if (ft_parse_conversion(&str, args, &flags) == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(*str++, 1);
			(flags).value += 1;
		}
	}
	return ((flags).value);
}
