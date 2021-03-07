/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:32:26 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/17 18:19:40 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_ESCAPE		53
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_SHIFT_LEFT	257
# define KEY_SPACEBAR	49
# define KEY_CTRL_LEFT	256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

typedef struct	s_stock
{
	char			*str;
	int				eof;
}				t_stock;

typedef struct	s_img
{
	void			*img;
	int				*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}				t_img;

typedef struct	s_sprite
{
	float			spritex;
	float			spritey;
	int				type;
	float			dist;
}				t_sprite;

typedef struct	s_bmpfileheader
{
	unsigned char	signature[2];
	int				bmp_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset;
}				t_bmpfileheader;

typedef struct	s_bmpinfoheader
{
	unsigned int	header_size;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_pxl;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	res_x;
	unsigned int	res_y;
	unsigned int	color_img;
	unsigned int	color_important;
}				t_bmpinfoheader;

typedef struct	s_parsing
{
	int				save;
	char			*map;
	int				width;
	int				height;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*sprite;
	char			*f;
	char			*c;
	int				nb_line;
	char			**map2d;
	int				floor;
	int				ceiling;
	int				pos;
	int				zero;
	int				sos;
	int				v;
}				t_parsing;

typedef struct	s_raycaster
{
	void			*mlx;
	void			*window;
	t_img			text[15];
	int				x;
	void			*img;
	int				*pxl;
	char			direction;
	float			posx;
	float			posy;
	float			dirx;
	float			diry;
	float			planex;
	float			planey;
	float			w;
	float			h;
	int				bpp;
	int				s_line;
	int				ed;
	float			movespeed;
	float			rotspeed;
	float			olddirx;
	float			oldplanex;
	float			camerax;
	float			raydirx;
	float			raydiry;
	int				mapx;
	int				mapy;
	float			deltadistx;
	float			deltadisty;
	int				hit;
	int				stepx;
	int				stepy;
	float			sidedistx;
	float			sidedisty;
	int				side;
	float			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	int				textnb;
	float			wallpos;
	int				textx;
	int				texty;
	int				mapsprix;
	int				mapspriy;
	t_sprite		*sprite;
	int				nbsprite;
	float			spritex;
	float			spritey;
	float			inv_plane;
	float			transx;
	float			transy;
	float			sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				drawstarty;
	int				drawstartx;
	int				drawendy;
	int				drawendx;
	int				u;
	float			*zbuffer;
}				t_raycaster;

typedef struct	s_key
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				fr;
	int				fl;
	int				sl;
	int				space;
	int				cl;
	int				escape;
}				t_key;

typedef struct	s_all
{
	t_parsing		p;
	t_raycaster		r;
	t_key			k;
}				t_all;

int				main(int ac, char **av);
int				check_argument(int ac, char **av, t_parsing *p);
int				break_error(int wa);
int				get_next_line(int fd, char **line);
int				ft_strchr(const char *str, int charset);
int				ft_atoi(int i, char *parse);
int				next_line(char *str);
int				parse_map(t_parsing *p, char **av, int i);
int				ft_parse_resolution(t_parsing *p, char *parse);
int				ft_parse_texture(t_parsing *p, char *parse);
int				convert_value(t_parsing *p, t_raycaster *r, int x);
int				check_error(t_parsing *p, int x);
int				holdintput(int key, t_all *a);
int				releaseintput(int key, t_all *a);
int				save_bmp(t_all *a);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_joinmap(char *s1, char const *s2);
char			*ft_submap(char const *s, unsigned int start, size_t len);
char			*ft_subline(char const *s);
char			**ft_split(char const *s, char c);
void			count_nb_line(t_parsing *p);
void			ini_struct_ray(t_parsing *p, t_raycaster *r);
void			deplacement_vertical(t_raycaster *r, t_key *k, t_parsing *p);
void			deplacement_horizontal(t_raycaster *r, t_key *k, t_parsing *p);
void			rotation(t_raycaster *r, t_key *k);
void			raycasting_function(t_raycaster *r, t_parsing *p);
void			position_wall(t_raycaster *r, t_parsing *p);
void			calculate_distance_line(t_raycaster *r);
void			texture_wall(t_raycaster *r);
void			verline_wall(t_parsing *t, t_raycaster *r, int start, int end);
void			position_sprite(t_raycaster *r);
void			calculate_distance_sprite(t_raycaster *r, int y);
void			draw_sprite(t_raycaster *r, int y, t_parsing *p);
void			bonus_deplacement(t_raycaster *r, t_key *k);
void			draw_pointer(t_parsing *p, t_raycaster *r);
void			ft_stop(t_all *a);
#endif
