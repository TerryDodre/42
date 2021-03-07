/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:42:54 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/17 18:20:58 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int		check_argument(int ac, char **av, t_parsing *p)
{
	int		d;

	d = 0;
	if (ac < 2)
		return (-1);
	else if (ac > 3)
		return (-2);
	while (av[1][d])
		d++;
	if (av[1][d - 1] != 'b' || av[1][d - 2] != 'u'
		|| av[1][d - 3] != 'c' || av[1][d - 4] != '.')
		return (-3);
	if (ac == 3)
	{
		d = 0;
		while (av[2][d])
			d++;
		if (d != 6 || av[2][0] != '-' || av[2][1] != '-'
			|| av[2][2] != 's' || av[2][3] != 'a'
			|| av[2][4] != 'v' || av[2][5] != 'e')
			return (-4);
		p->save = 1;
	}
	return (0);
}

void	ft_stop(t_all *a)
{
	int		i;

	i = 0;
	while (a->p.map2d[i])
	{
		free(a->p.map2d[i]);
		i++;
	}
	free(a->p.map2d);
}
