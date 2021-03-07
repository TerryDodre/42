/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_struct_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:59:50 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/16 15:34:50 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void		search_position(t_parsing *t, t_raycaster *r)
{
	int		x;
	int		y;

	x = 0;
	r->nbsprite = 0;
	while (t->map2d[x] != NULL)
	{
		y = 0;
		while (t->map2d[x][y])
		{
			if (t->map2d[x][y] == 'N' || t->map2d[x][y] == 'S'
			|| t->map2d[x][y] == 'W' || t->map2d[x][y] == 'E')
			{
				r->posx = x + 0.5;
				r->posy = y + 0.5;
				r->direction = t->map2d[x][y];
			}
			if (t->map2d[x][y] == '2')
				r->nbsprite = r->nbsprite + 1;
			y++;
		}
		x++;
	}
	r->sprite = (t_sprite *)malloc(sizeof(t_sprite) * r->nbsprite);
}

void		ini_struct_ray3(t_raycaster *r)
{
	if (r->direction == 'N')
	{
		r->planex = 0;
		r->planey = 0.66;
	}
	if (r->direction == 'S')
	{
		r->planex = 0;
		r->planey = -0.66;
	}
	if (r->direction == 'W')
	{
		r->planex = -0.66;
		r->planey = 0;
	}
	if (r->direction == 'E')
	{
		r->planex = 0.66;
		r->planey = 0;
	}
	r->bpp = 0;
	r->s_line = 0;
	r->movespeed = 0.08;
	r->rotspeed = 0.03;
}

void		ini_struct_ray2(t_parsing *t, t_raycaster *r)
{
	if (r->direction == 'N')
	{
		r->dirx = -1;
		r->diry = 0;
	}
	if (r->direction == 'S')
	{
		r->dirx = 1;
		r->diry = 0;
	}
	if (r->direction == 'W')
	{
		r->dirx = 0;
		r->diry = -1;
	}
	if (r->direction == 'E')
	{
		r->dirx = 0;
		r->diry = 1;
	}
	r->w = t->width;
	r->h = t->height;
	r->zbuffer = malloc(sizeof(float) * t->width - 1);
	ini_struct_ray3(r);
}

void		ini_sprite(t_raycaster *r, t_parsing *p)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (p->map2d[i] != NULL)
	{
		j = 0;
		while (p->map2d[i][j])
		{
			if (p->map2d[i][j] == '2')
			{
				r->sprite[k].spritex = i + 0.5;
				r->sprite[k].spritey = j + 0.5;
				r->sprite[k].type = p->map2d[i][j] - 50;
				k++;
			}
			j++;
		}
		i++;
	}
}

void		ini_struct_ray(t_parsing *p, t_raycaster *r)
{
	search_position(p, r);
	ini_struct_ray2(p, r);
	ini_sprite(r, p);
}
