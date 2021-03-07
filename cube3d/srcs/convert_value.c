/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:05:01 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/15 16:08:50 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int		load_texture2(t_parsing *p, t_raycaster *r)
{
	if (!(r->text[3].img = mlx_xpm_file_to_image(r->mlx, p->we,
		&r->text[3].width, &r->text[3].height)))
		return (-1);
	if (!(r->text[3].img_data = (int *)mlx_get_data_addr(r->text[3].img,
		&r->text[3].bpp, &r->text[3].size_line, &r->text[3].endian)))
		return (-1);
	if (!(r->text[4].img = mlx_xpm_file_to_image(r->mlx, p->sprite,
		&r->text[4].width, &r->text[4].height)))
		return (-1);
	if (!(r->text[4].img_data = (int *)mlx_get_data_addr(r->text[4].img,
		&r->text[4].bpp, &r->text[4].size_line, &r->text[4].endian)))
		return (-1);
	if (!(r->text[5].img = mlx_xpm_file_to_image(r->mlx, "texture/viseur.xpm",
		&r->text[5].width, &r->text[5].height)))
		return (-1);
	if (!(r->text[5].img_data = (int *)mlx_get_data_addr(r->text[5].img,
		&r->text[5].bpp, &r->text[5].size_line, &r->text[5].endian)))
		return (-1);
	return (0);
}

int		load_texture(t_parsing *p, t_raycaster *r)
{
	if (!(r->text[0].img = mlx_xpm_file_to_image(r->mlx, p->no,
		&r->text[0].width, &r->text[0].height)))
		return (-1);
	if (!(r->text[0].img_data = (int *)mlx_get_data_addr(r->text[0].img,
		&r->text[0].bpp, &r->text[0].size_line, &r->text[0].endian)))
		return (-1);
	if (!(r->text[1].img = mlx_xpm_file_to_image(r->mlx, p->so,
		&r->text[1].width, &r->text[1].height)))
		return (-1);
	if (!(r->text[1].img_data = (int *)mlx_get_data_addr(r->text[1].img,
		&r->text[1].bpp, &r->text[1].size_line, &r->text[1].endian)))
		return (-1);
	if (!(r->text[2].img = mlx_xpm_file_to_image(r->mlx, p->ea,
		&r->text[2].width, &r->text[2].height)))
		return (-1);
	if (!(r->text[2].img_data = (int *)mlx_get_data_addr(r->text[2].img,
		&r->text[2].bpp, &r->text[2].size_line, &r->text[2].endian)))
		return (-1);
	return (load_texture2(p, r));
}

void	convert_resolution(t_parsing *p)
{
	if (p->height < 20)
		p->height = 20;
	if (p->width < 20)
		p->width = 20;
	if (p->height > 1050)
		p->height = 1050;
	if (p->width > 1680)
		p->width = 1680;
}

int		convert_rgb(char *str)
{
	int		red;
	int		green;
	int		blue;
	int		res;
	int		i;

	i = 0;
	red = ft_atoi(i, str);
	i = ft_strchr(str, ',');
	green = ft_atoi(i, str);
	i = i + ft_strchr(str + i, ',');
	blue = ft_atoi(i, str);
	if (red > 255 || green > 255 || blue > 255)
		return (-1);
	if (red == -1 || green == -1 || blue == -1)
		return (-1);
	res = (256 * 256 * red) + (256 * green) + blue;
	return (res);
}

int		convert_value(t_parsing *p, t_raycaster *r, int x)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (x != 0)
		return (x);
	count_nb_line(p);
	while (*p->map != '\n')
		p->map--;
	if (!(p->map2d = ft_split(p->map + 1, '\n')))
		return (-14);
	while (p->map2d[a])
		a++;
	if (a != p->nb_line)
		return (-13);
	p->floor = convert_rgb(p->f);
	free(p->f);
	p->ceiling = convert_rgb(p->c);
	free(p->c);
	convert_resolution(p);
	if (load_texture(p, r) != 0)
		return (-15);
	return (0);
}
