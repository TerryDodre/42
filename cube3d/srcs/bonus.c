/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:24:21 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/15 16:07:42 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void		bonus_deplacement(t_raycaster *r, t_key *k)
{
	r->movespeed = 0.08;
	if (k->sl == 1)
		r->movespeed = 0.15;
}

void		draw_pointer(t_parsing *p, t_raycaster *r)
{
	int		g;
	int		h;
	int		i;
	int		j;

	g = p->height / 2 - 17;
	h = p->width / 2 - 17;
	j = 0;
	i = 0;
	while (i < 420)
	{
		j = 0;
		while (j < 420)
		{
			r->color = r->text[5].img_data[i * r->text[5].width + j];
			if ((r->color & 0xffffff) != 0)
				r->pxl[(h + i / 12) + (g + j / 12) * p->width] = r->color;
			j++;
		}
		i++;
	}
}
