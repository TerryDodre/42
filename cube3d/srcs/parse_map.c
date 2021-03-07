/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:24:48 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/16 15:27:15 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int			check_color(t_parsing *p, int ret)
{
	int		d;

	if (ret != 0)
		return (ret);
	d = 0;
	while (p->f[d])
	{
		if (p->f[d] != ',' && (p->f[d] < '0' || p->f[d] > '9'))
			return (-12);
		d++;
	}
	d = 0;
	while (p->c[d])
	{
		if (p->c[d] != ',' && (p->c[d] < '0' || p->c[d] > '9'))
			return (-12);
		d++;
	}
	return (0);
}

int			check_neant(t_parsing *p, int ret)
{
	if (ret != 0)
		return (ret);
	if (!p->no || !p->so || !p->we || !p->ea)
		return (-8);
	if (!p->sprite)
		return (-9);
	if (!p->f || !p->c)
		return (-10);
	if (p->width == -1 || p->height == -1)
		return (-11);
	return (0);
}

int			find_value(t_parsing *p)
{
	while (*p->map)
	{
		if (*p->map == 'R')
		{
			if (ft_parse_resolution(p, ft_subline(p->map)) == -1)
				return (-6);
			p->map = p->map + next_line(p->map);
		}
		else if (*p->map == 'N' || *p->map == 'S' || *p->map == 'W'
				|| *p->map == 'E' || *p->map == 'F' || *p->map == 'C')
		{
			if (ft_parse_texture(p, ft_subline(p->map)) == -1)
				return (-7);
			p->map = p->map + next_line(p->map);
		}
		else if (*p->map == '1')
			break ;
		else if (*p->map != ' ' && *p->map != '\n')
			return (-1);
		if (*p->map)
			p->map++;
	}
	return (0);
}

int			parse_map(t_parsing *p, char **av, int i)
{
	int		fd;
	int		ret;
	char	*line;
	char	*tmp;

	if (i != 0)
		return (i);
	ret = 1;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-5);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		tmp = p->map;
		p->map = ft_joinmap(tmp, line);
		free(line);
		free(tmp);
	}
	close(fd);
	if (ret == -1)
		return (-5);
	ret = find_value(p);
	ret = check_neant(p, ret);
	ret = check_color(p, ret);
	return (ret);
}
