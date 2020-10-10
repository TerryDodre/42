/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:24:40 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/09 13:42:29 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_flags_nbr(const char **str, t_flags **flags, int i)
{
	long	result;

	result = 0;
	while ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str)[i])
	{
		result = result * 10 + ((*str)[i] - 48);
		i++;
	}
	(*flags)->nb_exist = 1;
	(*flags)->nb = result;
	return (i);
}

int		ft_flags_precision(const char **str, va_list args, t_flags **ap, int i)
{
	long	result;

	result = 0;
	i++;
	if ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str)[i])
	{
		while ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str)[i])
		{
			result = result * 10 + ((*str)[i] - 48);
			i++;
		}
	}
	else if ((*str)[i] == '*')
	{
		result = va_arg(args, int);
		i++;
	}
	(*ap)->precision_exist = 1;
	(*ap)->precision = result;
	if (result < 0)
		(*ap)->precision_exist = 0;
	return (i);
}

int		ft_flag_size(const char **str, va_list args, t_flags **ap, int i)
{
	long	result;

	result = 0;
	while ((*str)[i] == '-')
		i++;
	if ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str)[i])
	{
		while ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str)[i])
		{
			result = result * 10 + ((*str)[i] - 48);
			i++;
		}
	}
	else if ((*str)[i] == '*')
	{
		result = va_arg(args, int);
		i++;
	}
	(*ap)->size_exist = 1;
	(*ap)->size = result;
	if (result < 0)
		(*ap)->size = -result;
	return (i);
}

int		ft_flags_zero(char const **str, va_list args, t_flags **ap, int i)
{
	long	result;

	result = 0;
	i++;
	if ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str)[i])
	{
		while ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str)[i])
		{
			result = result * 10 + ((*str)[i] - 48);
			i++;
		}
	}
	else if ((*str)[i] == '*')
	{
		result = va_arg(args, int);
		i++;
	}
	result >= 0 ? (*ap)->zero_exist = 1 : 0;
	result >= 0 ? (*ap)->zero = result : 0;
	result < 0 ? (*ap)->size_exist = 1 : 0;
	result < 0 ? (*ap)->size = -result : 0;
	return (i);
}

int		ft_flags_args(va_list args, t_flags **ap, int i)
{
	int		a;

	i++;
	a = va_arg(args, int);
	if (a >= 0)
	{
		(*ap)->nb_exist = 1;
		(*ap)->nb = a;
	}
	else
	{
		(*ap)->size_exist = 1;
		(*ap)->size = -a;
	}
	return (i);
}
