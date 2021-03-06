/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:43:05 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 20:13:41 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../libft/gnl/get_next_line.h"

# if __linux__
#  include "../minilibx-linux/mlx.h"
#  define FRONT 119
#  define BACK 115
#  define LEFT 97
#  define RIGHT 100
#  define ROTATE_LEFT 65361
#  define ROTATE_RIGHT 65363
#  define ESC 65307
#  define RED_CROSS 33
#  define RED_CROSS_MASK 17
# elif __APPLE__
#  include "../minilibx/mlx.h"
#  define FRONT 13
#  define BACK 1
#  define LEFT 0
#  define RIGHT 2
#  define ROTATE_LEFT 123
#  define ROTATE_RIGHT 124
#  define ESC 53
#  define RED_CROSS 17
#  define RED_CROSS_MASK 13
# endif

typedef struct	s_mlx
{
	void *ptr;
	void *wdw2;
}				t_mlx;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			i;
	int			j;
}				t_img;

typedef struct	s_flags
{
	int r;
	int no;
	int so;
	int ea;
	int we;
	int sprite;
	int f;
	int c;
}				t_flags;

typedef struct	s_player
{
	char	start;
	float	angle;
	float	ortho;
	int		x;
	int		y;
	float	rfx;
	float	rfy;
	float	fx;
	float	fy;
	float	dirx;
	float	diry;
	float	planx;
	float	plany;
}				t_player;

typedef struct	s_triangle
{
	float xa;
	float ya;
	float xb;
	float yb;
	float xc;
	float yc;
	float angle;
	float r;
}				t_triangle;

typedef struct	s_ray
{
	t_triangle	trix;
	t_triangle	triy;
	float		xc;
	float		yc;
	char		dir;
	float		r;
}				t_ray;

typedef struct	s_sprite
{
	int x;
	int y;
	int dist;
}				t_sprite;

typedef struct	s_malloc
{
	char	*line;
	char	*line_map;
	char	**tmp;
	int		fd;
}				t_malloc;

typedef struct	s_spr
{
	float	spritx;
	float	sprity;
	float	invdet;
	float	transformx;
	float	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		spritewidth;
	int		drawstarty;
	int		drawendy;
	int		drawstartx;
	int		drawendx;
	int		stripe;
	int		texx;
	int		texy;
	int		d;
}				t_spr;

typedef struct	s_mini
{
	int start_x;
	int	start_y;
}				t_mini;

typedef struct	s_datas
{
	int			bmp;
	int			res_x;
	int			res_y;
	int			mini_x;
	int			mini_y;
	float		c1;
	float		c2;
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	char		*spr_path;
	int			f_rgb;
	int			c_rgb;
	char		**map;
	int			columns;
	int			lines;
	float		*buff;
	t_mini		mini;
	t_player	player;
	t_mlx		mlx;
	t_img		fps;
	t_img		txt[5];
	t_sprite	*spr;
	int			sprites_nbr;
	int			*spr_ordr;
}				t_datas;

int				create_trgb(int t, int r, int g, int b);
void			ft_fillmap(t_malloc *m, t_datas *map);
int				ft_fill_floor(t_datas *map, t_flags *flags, char **tmp);
int				ft_fill_ceiling(t_datas *map, t_flags *flags, char **tmp);
int				ft_rgb(int *mapclearance, t_malloc *m, t_datas *map,
t_flags *flags);
void			ft_fill_no_path(t_malloc *m, t_datas *map, t_flags *flags,
char *str);
void			ft_fill_we_path(t_malloc *m, t_datas *map, t_flags *flags,
char *str);
void			ft_fill_ea_path(t_malloc *m, t_datas *map, t_flags *flags,
char *str);
void			ft_fill_so_path(t_malloc *m, t_datas *map, t_flags *flags,
char *str);
void			ft_fillsprite_path(t_malloc *m, t_datas *map, t_flags *flags,
char *str);
int				comma_count(char *line);
int				check_num_res(char **tmp);
int				check_num_fc(char **tmp);

int				ft_parsor(char *path, t_datas *map_datas);
int				map_parsor(t_malloc *m, t_datas *map_datas);
int				ft_display(t_datas *map_datas);

void			ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void			movement(float i, t_datas *maps);
void			ortho_movement(float i, t_datas *maps);
void			ft_initposition(t_datas *map);
void			left_rotation(float rot, t_datas *map);
void			right_rotation(float rot, t_datas *map);

int				ft_fps(t_datas *map);
void			ft_sprites(t_datas *map);
void			get_order(t_datas *map);

void			make_bmp(t_datas *map);
void			initialize_struct(t_datas *map);
int				ft_exit(t_datas *map);
void			screen_size(t_datas *map);
void			init_malloc(t_malloc *m);
void			free_malloc(t_malloc *m);
void			failed_malloc(t_malloc *m, t_datas *map);
void			failed_reading(t_malloc *m, t_datas *map);
void			free_tmp(t_malloc *m);

int				primary_check(char *str, int k);
int				map_checkfirstline(char *firstline, char *underline);
int				map_checklastline(char *lastline, char *upperline);
int				map_checkmiddleline(char *middleline, char *upperline,
char *underline);
int				map_checkerror(char **map, int k);
void			get_angle(t_datas *map);
void			init_double_array(t_malloc *m, t_datas *map);

void			map_correction(t_malloc *m, t_datas *map);
void			straight_compass(t_datas *map, t_ray *ray, float angle);
void			compass(t_datas *map, float angle, t_ray *ray);
void			ne_ray(t_datas *map, t_ray *ray);
void			sw_ray(t_datas *map, t_ray *ray);
void			se_ray(t_datas *map, t_ray *ray);
void			nw_ray(t_datas *map, t_ray *ray);
void			print_ray(t_datas *map, int x, float ray_p, t_ray *ray);
void			stock_ray(t_ray *ray);
int				ft_minimap(t_datas *map);
void			ft_mlx_cube(t_datas *map, float x, float y, int color);
void			ft_print_ray(t_datas *map);
void			ft_mlx_direction(t_datas *map, float c1);
int				check_comma_start_end(char *line);

#endif
