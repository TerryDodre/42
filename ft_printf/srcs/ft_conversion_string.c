/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:54:17 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/09 13:58:07 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_write_null(t_flags **flags)
{
	int i;

	if ((**flags).precision_exist == 1 && (**flags).precision < 6)
		i = (**flags).precision;
	else
		i = 6;
	if ((**flags).nb_exist == 1)
		ft_write_space((**flags).nb - i, &flags);
	i > 0 ? ft_write('(', &flags) : 0;
	i > 1 ? ft_write('n', &flags) : 0;
	i > 2 ? ft_write('u', &flags) : 0;
	i > 3 ? ft_write('l', &flags) : 0;
	i > 4 ? ft_write('l', &flags) : 0;
	i > 5 ? ft_write(')', &flags) : 0;
	if ((**flags).size_exist == 1)
		ft_write_space((**flags).size - i, &flags);
}

void		ft_conversion_string(va_list args, t_flags **flags)
{
	int		i;
	int		j;
	char	*tab;

	j = 0;
	i = 0;
	tab = va_arg(args, char *);
	if (tab == NULL)
		ft_write_null(flags);
	else
	{
		if ((**flags).precision_exist != 1 || (**flags).precision != 0)
			i = (int)ft_strlen(tab);
		if ((**flags).precision_exist == 1 && (**flags).precision < i)
			i = (**flags).precision;
		if ((**flags).nb_exist == 1)
			ft_write_space((**flags).nb - i, &flags);
		while (i > j && tab[j])
			ft_write(tab[j++], &flags);
		if ((**flags).size_exist == 1)
			ft_write_space((**flags).size - i, &flags);
	}
}
