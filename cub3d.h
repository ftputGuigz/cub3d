/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:43:05 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/12 12:12:37 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "./minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <fcntl.h>

# include "./libft/libft.h"
# include "./libft/gnl/get_next_line.h"

typedef struct s_mlx
{
	void *ptr;
	void *wdw;
	void *wdw2;
}				t_mlx;

typedef struct s_img
{
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int 		i;
	int 		j;
}				t_img;

typedef struct s_flags
{
	int R;
	int NO;
	int SO;
	int EA;
	int WE;
	int sprite;
	int F;
	int C;
}				t_flags;

typedef struct s_player
{
	char start;
	float angle;
	float ortho;
	int x;
	int y;
	float rfx;
	float rfy;
	float fx;
	float fy;
	float dirx;
	float diry;
	float planx;
	float plany;
}				t_player;

typedef struct s_triangle
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

typedef struct s_ray
{
	t_triangle trix;
	t_triangle triy;
	float xc;
	float yc;
	char dir;
	float r;
}				t_ray;

typedef struct s_sprite
{
	int x;
	int y;
	int dist;
}				t_sprite;

typedef struct	s_datas
{
	int res_x;
	int res_y;
	char *NO_path;
	char *SO_path; 
	char *EA_path;
	char *WE_path; 
	char *spr_path;
	int f_rgb;
	int c_rgb;
	char **map;
	int columns;
	int lines;
	t_player player;
	t_mlx	mlx;
	t_img minimap;
	t_img fps;
	t_img txt[5];
	t_sprite *spr;
	int sprites_nbr;
	int *spr_ordr;
}				t_datas;

int		ft_parsor(char *path, t_datas *map_datas);
int		map_parsor(char *line_map, t_datas *map_datas);
int		ft_display(t_datas *map_datas);

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_mlx_cube(t_img *img, float x, float y, float c1, float c2, int color);
int		ft_minimap(t_datas *map);
void	movement(float i, t_datas *maps);
void	ortho_movement(float i, t_datas *maps);
void	ft_initposition(t_datas *map);
void	left_rotation(float rot, t_datas *map);
void	right_rotation(float rot, t_datas *map);

int		ft_fps(t_datas *map);
void	ft_sprites(t_datas *map);

#endif
