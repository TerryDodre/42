/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:41:42 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/15 16:08:42 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int		check_wall(int x, int y, t_parsing *t)
{
	int		a;
	int		b;

	a = y;
	while (t->map2d[x][a] != '1' && a > 0 && t->map2d[x][a] != ' ')
		a--;
	if (t->map2d[x][a] != '1')
		return (-1);
	a = y;
	while (t->map2d[x][a] && t->map2d[x][a] != '1' && t->map2d[x][a] != ' ')
		a++;
	if (t->map2d[x][a] != '1')
		return (-1);
	b = x;
	while (t->map2d[b][y] != '1' && b > 0 && t->map2d[b][y] != ' ')
		b--;
	if (t->map2d[b][y] != '1')
		return (-1);
	b = x;
	while (b < t->nb_line - 1 && t->map2d[b][y] != '1' && t->map2d[b][y] != ' ')
		b++;
	if (t->map2d[b][y] != '1')
		return (-1);
	return (1);
}

void	check_backline(t_parsing *t, int x, int y)
{
	int		o;
	int		a;

	if (x != 0)
	{
		if (y > t->v)
		{
			o = y - t->v;
			while (o != 1)
			{
				a = y - o;
				if (t->map2d[x][a] != '1' && t->map2d[x][a] != ' ')
					t->sos = 1;
				o--;
			}
		}
	}
	t->v = y;
}

int		is_valid_map(t_parsing *t)
{
	int		x;
	int		y;

	x = 0;
	while (t->map2d[t->nb_line] != NULL)
		t->nb_line++;
	while (t->map2d[x] != NULL)
	{
		y = 0;
		while (t->map2d[x][y])
		{
			if (t->map2d[x][y] == '0' || t->map2d[x][y] == '2'
				|| t->map2d[x][y] == 'N' || t->map2d[x][y] == 'O'
				|| t->map2d[x][y] == 'S' || t->map2d[x][y] == 'W')
			{
				if (check_wall(x, y, t) == -1)
					return (-1);
				(t->zero)++;
			}
			y++;
		}
		check_backline(t, x, y);
		x++;
	}
	return (1);
}

int		check_map(t_parsing *t)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (t->map2d[x] != NULL)
	{
		while (t->map2d[x][y])
		{
			if (t->map2d[x][y] != '0' && t->map2d[x][y] != '1'
			&& t->map2d[x][y] != '2' && t->map2d[x][y] != ' '
			&& t->map2d[x][y] != 'N' && t->map2d[x][y] != 'S'
			&& t->map2d[x][y] != 'W' && t->map2d[x][y] != 'E')
				return (-1);
			if (t->map2d[x][y] == 'N' || t->map2d[x][y] == 'S'
					|| t->map2d[x][y] == 'W' || t->map2d[x][y] == 'E')
				t->pos += 1;
			y++;
		}
		y = 0;
		x++;
	}
	if (t->pos != 1)
		return (-1);
	return (1);
}

int		check_error(t_parsing *p, int x)
{
	if (x != 0)
		return (x);
	if (p->width == -1 || p->height == -1 || p->width == 0 || p->height == 0)
		return (-6);
	if (!p->no || !p->so || !p->we || !p->ea || !p->sprite)
		return (-8);
	if (p->floor == -1 || p->ceiling == -1)
		return (-12);
	if (p->map2d[0] == NULL)
		return (-16);
	if (check_map(p) == -1)
		return (-16);
	if (is_valid_map(p) == -1)
		return (-17);
	if (p->zero == 0 || p->sos == 1)
		return (-17);
	return (0);
}
