/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_porcent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:03:31 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/09 14:04:35 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_conversion_porcent(t_flags **flags)
{
	int		i;

	i = 0;
	if ((**flags).zero_exist == 1)
		i = (**flags).zero - 1;
	else if ((**flags).nb_exist == 1)
		ft_write_space((**flags).nb - 1, &flags);
	if (i > 0 && (**flags).size == 0)
	{
		while (i > 0)
		{
			ft_write('0', &flags);
			i--;
		}
	}
	ft_write('%', &flags);
	if ((**flags).size_exist == 1)
		ft_write_space((**flags).size - 1, &flags);
}
