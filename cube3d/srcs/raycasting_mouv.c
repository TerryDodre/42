/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_mouv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:11:48 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/15 16:09:30 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int			holdintput(int key, t_all *a)
{
	if (key == KEY_W)
		a->k.w = 1;
	if (key == KEY_A)
		a->k.a = 1;
	if (key == KEY_S)
		a->k.s = 1;
	if (key == KEY_D)
		a->k.d = 1;
	if (key == KEY_LEFT)
		a->k.fl = 1;
	if (key == KEY_RIGHT)
		a->k.fr = 1;
	if (key == KEY_SHIFT_LEFT)
		a->k.sl = 1;
	if (key == KEY_SPACEBAR)
		a->k.space = 1;
	if (key == KEY_CTRL_LEFT)
		a->k.cl = 1;
	if (key == KEY_ESCAPE)
		a->k.escape = 1;
	return (0);
}

int			releaseintput(int key, t_all *a)
{
	if (key == KEY_W)
		a->k.w = 0;
	if (key == KEY_A)
		a->k.a = 0;
	if (key == KEY_S)
		a->k.s = 0;
	if (key == KEY_D)
		a->k.d = 0;
	if (key == KEY_LEFT)
		a->k.fl = 0;
	if (key == KEY_RIGHT)
		a->k.fr = 0;
	if (key == KEY_SPACEBAR)
		a->k.space = 0;
	if (key == KEY_CTRL_LEFT)
		a->k.cl = 0;
	if (key == KEY_SHIFT_LEFT)
		a->k.sl = 0;
	return (0);
}

void		deplacement_vertical(t_raycaster *r, t_key *k, t_parsing *p)
{
	if (k->w == 1)
	{
		if (p->map2d[(int)(r->posx + r->dirx * r->movespeed)]
			[(int)r->posy] != '1')
			r->posx += r->dirx * (r->movespeed);
		if (p->map2d[(int)(r->posx)][(int)(r->posy + r->diry *
			r->movespeed)] != '1')
			r->posy += r->diry * (r->movespeed);
	}
	if (k->s == 1)
	{
		if (p->map2d[(int)(r->posx - r->dirx * r->movespeed)]
			[(int)r->posy] != '1')
			r->posx -= r->dirx * r->movespeed;
		if (p->map2d[(int)(r->posx)][(int)(r->posy - r->diry *
			r->movespeed)] != '1')
			r->posy -= r->diry * r->movespeed;
	}
}

void		deplacement_horizontal(t_raycaster *r, t_key *k, t_parsing *p)
{
	if (k->d == 1)
	{
		if (p->map2d[(int)(r->posx + r->planex * r->movespeed)]
			[(int)r->posy] != '1')
			r->posx += r->planex * r->movespeed;
		if (p->map2d[(int)(r->posx)][(int)(r->posy + r->planey *
			r->movespeed)] != '1')
			r->posy += r->planey * r->movespeed;
	}
	if (k->a == 1)
	{
		if (p->map2d[(int)(r->posx - r->planex * r->movespeed)]
			[(int)r->posy] != '1')
			r->posx -= r->planex * r->movespeed;
		if (p->map2d[(int)(r->posx)][(int)(r->posy - r->planey *
			r->movespeed)] != '1')
			r->posy -= r->planey * r->movespeed;
	}
}

void		rotation(t_raycaster *r, t_key *k)
{
	if (k->fr == 1)
	{
		r->olddirx = r->dirx;
		r->dirx = r->dirx * cos(-(r->rotspeed)) - r->diry * sin(-(r->rotspeed));
		r->diry = r->olddirx * sin(-(r->rotspeed)) + r->diry *
			cos(-(r->rotspeed));
		r->oldplanex = r->planex;
		r->planex = r->planex * cos(-(r->rotspeed)) -
			r->planey * sin(-(r->rotspeed));
		r->planey = r->oldplanex * sin(-(r->rotspeed)) +
			r->planey * cos(-(r->rotspeed));
	}
	if (k->fl == 1)
	{
		r->olddirx = r->dirx;
		r->dirx = r->dirx * cos(r->rotspeed) - r->diry * sin(r->rotspeed);
		r->diry = r->olddirx * sin(r->rotspeed) + r->diry * cos(r->rotspeed);
		r->oldplanex = r->planex;
		r->planex = r->planex * cos(r->rotspeed) - r->planey * sin(r->rotspeed);
		r->planey = r->oldplanex * sin(r->rotspeed) +
			r->planey * cos(r->rotspeed);
	}
}
