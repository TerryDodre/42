/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:25:04 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/15 16:08:57 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void		position_wall(t_raycaster *r, t_parsing *p)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (p->map2d[r->mapx][r->mapy] == '1')
			r->hit = 1;
	}
}

void		calculate_distance_line(t_raycaster *r)
{
	if (r->side == 0)
		r->perpwalldist = (r->mapx - r->posx + (1 - r->stepx) / 2) / r->raydirx;
	else
		r->perpwalldist = (r->mapy - r->posy + (1 - r->stepy) / 2) / r->raydiry;
	r->lineheight = (int)(r->h / r->perpwalldist);
	r->drawstart = -(r->lineheight) / 2 + r->h / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + r->h / 2;
	if (r->drawend >= r->h)
		r->drawend = r->h - 1;
}

void		texture_wall(t_raycaster *r)
{
	if (r->side == 1)
		r->textnb = r->raydiry < 0 ? 2 : 3;
	else
		r->textnb = r->raydirx < 0 ? 1 : 0;
	if (r->side == 0)
		r->wallpos = r->posy + r->perpwalldist * r->raydiry;
	else
		r->wallpos = r->posx + r->perpwalldist * r->raydirx;
	r->wallpos -= (int)r->wallpos;
	r->textx = (int)(r->wallpos * (float)(r->text[r->textnb].width));
	if (r->side == 0 && r->raydirx > 0)
		r->textx = r->text[r->textnb].width - r->textx - 1;
	if (r->side == 1 && r->raydiry > 0)
		r->textx = r->text[r->textnb].width - r->textx - 1;
}

void		verline_wall(t_parsing *t, t_raycaster *r, int start, int end)
{
	int		a;

	a = 0;
	while (a < t->height)
	{
		if (a < start)
			r->pxl[r->x + a * t->width] = t->ceiling;
		else if (a >= start && a <= end)
		{
			r->texty = ((a - r->h * 0.5f + r->lineheight * 0.5f) *
				r->text[r->textnb].height - 1) / r->lineheight;
			r->color = r->text[r->textnb].img_data[r->texty *
				r->text[r->textnb].width + r->textx];
			r->pxl[r->x + a * t->width] = r->color;
		}
		else
			r->pxl[r->x + a * t->width] = t->floor;
		a++;
	}
}
