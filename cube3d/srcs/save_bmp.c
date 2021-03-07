/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:24:05 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/17 18:20:25 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	creat_bmp(int fd, t_all *a)
{
	int					x;
	int					y;
	int					pixel;
	unsigned char		color[3];

	y = a->p.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < a->p.width)
		{
			pixel = a->r.pxl[y * a->p.width + x];
			color[0] = pixel % 256;
			pixel = pixel / 256;
			color[1] = pixel % 256;
			pixel = pixel / 256;
			color[2] = pixel % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void	ini_bmp(int fd, t_all *a)
{
	t_bmpfileheader		bfh;
	t_bmpinfoheader		bih;

	bfh.signature[0] = 'B';
	bfh.signature[1] = 'M';
	bfh.bmp_size = a->p.width * a->p.height * 3 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset = 0;
	bih.header_size = 40;
	bih.width = a->p.width;
	bih.height = a->p.height;
	bih.planes = 1;
	bih.bit_pxl = 24;
	bih.compression = 0;
	bih.image_size = a->p.width * a->p.height * 3 + 54;
	bih.res_x = 1;
	bih.res_y = 1;
	bih.color_img = 0;
	bih.color_important = 0;
	close(open("save.bmp", O_RDONLY | O_CREAT, 0777));
	fd = open("save.bmp", O_RDWR);
	write(fd, &bfh, 14);
	write(fd, &bih, 40);
	creat_bmp(fd, a);
}

int		save_bmp(t_all *a)
{
	int					fd;

	fd = 0;
	a->r.mlx = mlx_init();
	a->r.img = mlx_new_image(a->r.mlx, a->p.width, a->p.height);
	a->r.pxl = (int *)mlx_get_data_addr(a->r.img, &a->r.bpp,
		&a->r.s_line, &a->r.ed);
	raycasting_function(&a->r, &a->p);
	draw_pointer(&a->p, &a->r);
	ini_bmp(fd, a);
	ft_stop(a);
	return (0);
}
