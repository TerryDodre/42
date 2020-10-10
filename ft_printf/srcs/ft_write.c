/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:51:28 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/09 13:52:47 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_write(char c, t_flags ***ap)
{
	ft_putchar_fd(c, 1);
	(**ap)->value += 1;
}

void	ft_write_space(int i, t_flags ***ap)
{
	while (0 < i--)
	{
		ft_putchar_fd(' ', 1);
		(**ap)->value += 1;
	}
}
