/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:24:57 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/15 16:08:53 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void		position_sprite(t_raycaster *r)
{
	int			x;
	t_sprite	tmp;

	x = 0;
	while (x < r->nbsprite)
	{
		r->sprite[x].dist = ((r->posx - r->sprite[x].spritex) *
			(r->posx - r->sprite[x].spritex) +
			((r->posy - r->sprite[x].spritey) *
			(r->posy - r->sprite[x].spritey)));
		x++;
	}
	x = 0;
	while (x < r->nbsprite - 1)
	{
		if (r->sprite[x].dist < r->sprite[x + 1].dist)
		{
			tmp = r->sprite[x + 1];
			r->sprite[x + 1] = r->sprite[x];
			r->sprite[x] = tmp;
			x = 0;
		}
		x++;
	}
}

void		calculate_distance_sprite(t_raycaster *r, int y)
{
	r->spritex = r->sprite[y].spritex - r->posx;
	r->spritey = r->sprite[y].spritey - r->posy;
	r->inv_plane = 1.0 / ((r->planex * r->diry) - (r->dirx * r->planey));
	r->transx = r->inv_plane * (r->diry * r->spritex - r->dirx * r->spritey);
	r->transy = r->inv_plane * ((-r->planey * r->spritex) +
		(r->planex * r->spritey));
	r->sprite_screen_x = (int)((r->w / 2) * (1 + r->transx / r->transy));
	r->sprite_height = abs((int)(r->h / (r->transy)));
	r->drawstarty = (-r->sprite_height / 2 + r->h / 2);
	if (r->drawstarty < 0)
		r->drawstarty = 0;
	r->drawendy = (r->sprite_height / 2 + r->h / 2);
	if (r->drawendy >= r->h)
		r->drawendy = r->h - 1;
	r->sprite_width = abs((int)(r->h / (r->transy)));
	r->drawstartx = (-r->sprite_width / 2 + r->sprite_screen_x);
	if (r->drawstartx < 0)
		r->drawstartx = 0;
	r->drawendx = r->sprite_width / 2 + r->sprite_screen_x;
	if (r->drawendx >= r->w)
		r->drawendx = r->w - 1;
}

void		verline_sprite(t_raycaster *r, int y, t_parsing *p)
{
	int			v;

	v = r->drawstarty;
	while (v < r->drawendy)
	{
		r->texty = ((v - r->h * 0.5f + r->sprite_height * 0.5f) *
			r->text[4 + r->sprite[y].type].height - 1) / r->sprite_height;
		r->color = r->text[4 + r->sprite[y].type].img_data[r->texty *
			r->text[4 + r->sprite[y].type].width + r->textx];
		if ((r->color & 0xffffff) != 0)
			r->pxl[v * p->width + r->u] = r->color;
		v++;
	}
}

void		draw_sprite(t_raycaster *r, int y, t_parsing *p)
{
	r->u = r->drawstartx;
	while (r->u < r->drawendx)
	{
		r->textx = (int)((256 * (r->u - (-r->sprite_width / 2 +
			r->sprite_screen_x)) * r->text[4 + r->sprite[y].type].width /
			r->sprite_width) / 256);
		if (r->transy > 0 && r->u > 0 && r->u < r->w && r->transy <
			r->zbuffer[r->u])
			verline_sprite(r, y, p);
		r->u = r->u + 1;
	}
}
