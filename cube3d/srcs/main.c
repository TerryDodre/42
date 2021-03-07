/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:32:15 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/17 18:20:04 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	ini_struct_parse(t_parsing *p)
{
	p->save = 0;
	p->map = NULL;
	p->height = -1;
	p->width = -1;
	p->no = NULL;
	p->so = NULL;
	p->we = NULL;
	p->ea = NULL;
	p->sprite = NULL;
	p->map2d = NULL;
	p->f = NULL;
	p->c = NULL;
	p->floor = 0;
	p->ceiling = 0;
	p->nb_line = 0;
	p->pos = 0;
	p->v = 0;
	p->sos = 0;
}

int		raycasting_act(t_all *a)
{
	bonus_deplacement(&a->r, &a->k);
	if (a->k.w == 1 || a->k.s == 1)
		deplacement_vertical(&a->r, &a->k, &a->p);
	if (a->k.a == 1 || a->k.d == 1)
		deplacement_horizontal(&a->r, &a->k, &a->p);
	if (a->k.fl == 1 || a->k.fr == 1)
		rotation(&a->r, &a->k);
	if (a->k.escape == 1)
	{
		mlx_clear_window(a->r.mlx, a->r.window);
		mlx_destroy_window(a->r.mlx, a->r.window);
		ft_stop(a);
		exit(0);
	}
	raycasting_function(&a->r, &a->p);
	draw_pointer(&a->p, &a->r);
	mlx_put_image_to_window(a->r.mlx, a->r.window, a->r.img, 0, 0);
	return (1);
}

int		cross_close(t_all *a)
{
	mlx_destroy_window(a->r.mlx, a->r.window);
	ft_stop(a);
	exit(0);
}

int		main(int ac, char **av)
{
	t_all	a;
	int		wa;

	ini_struct_parse(&a.p);
	wa = check_argument(ac, av, &a.p);
	wa = parse_map(&a.p, av, wa);
	wa = convert_value(&a.p, &a.r, wa);
	wa = check_error(&a.p, wa);
	if (wa != 0)
		return (break_error(wa));
	ini_struct_ray(&a.p, &a.r);
	if (a.p.save == 1)
		return (save_bmp(&a));
	a.r.mlx = mlx_init();
	a.r.window = mlx_new_window(a.r.mlx, a.p.width, a.p.height, "Cube3D");
	a.r.img = mlx_new_image(a.r.mlx, a.p.width, a.p.height);
	a.r.pxl = (int *)mlx_get_data_addr(a.r.img, &a.r.bpp, &a.r.s_line, &a.r.ed);
	mlx_loop_hook(a.r.mlx, raycasting_act, &a);
	mlx_hook(a.r.window, 2, 0, holdintput, &a);
	mlx_hook(a.r.window, 3, 0, releaseintput, &a);
	mlx_hook(a.r.window, 17, 0, cross_close, &a);
	mlx_loop(a.r.mlx);
	return (0);
}
