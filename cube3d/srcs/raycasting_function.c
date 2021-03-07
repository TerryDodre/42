/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:19:11 by terry             #+#    #+#             */
/*   Updated: 2020/07/15 16:09:27 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void		ini_draw_type(t_raycaster *r)
{
	r->camerax = 2 * r->x / r->w - 1;
	r->raydirx = r->dirx + r->planex * r->camerax;
	r->raydiry = r->diry + r->planey * r->camerax;
	r->mapx = (int)r->posx;
	r->mapy = (int)r->posy;
	r->deltadistx = fabs(1 / r->raydirx);
	r->deltadisty = fabs(1 / r->raydiry);
	r->hit = 0;
}

void		calculate_position(t_raycaster *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->posx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->posx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->posy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - r->posy) * r->deltadisty;
	}
}

void		raycasting_function(t_raycaster *r, t_parsing *p)
{
	int		y;

	r->x = 0;
	while (r->x < p->width)
	{
		y = 0;
		ini_draw_type(r);
		calculate_position(r);
		position_wall(r, p);
		calculate_distance_line(r);
		texture_wall(r);
		verline_wall(p, r, r->drawstart, r->drawend);
		r->zbuffer[r->x] = r->perpwalldist;
		r->x = r->x + 1;
	}
	position_sprite(r);
	while (y < r->nbsprite)
	{
		calculate_distance_sprite(r, y);
		draw_sprite(r, y, p);
		y++;
	}
}
