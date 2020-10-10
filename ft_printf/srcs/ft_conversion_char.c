/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:48:51 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/09 13:53:49 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_conversion_char(va_list args, t_flags **flags)
{
	char	c;

	c = va_arg(args, int);
	if ((**flags).nb_exist == 1)
		ft_write_space((**flags).nb - 1, &flags);
	ft_write(c, &flags);
	if ((**flags).size_exist == 1)
		ft_write_space((**flags).size - 1, &flags);
}
