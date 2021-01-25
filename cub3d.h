/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:43:05 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/25 17:26:32 by gpetit           ###   ########.fr       */
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
}				t_mlx;

typedef struct s_img
{
	void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
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
	float fx;
	float fy;
}				t_player;

typedef struct	s_datas
{
	int res_x;
	int res_y;
	char *NO_path;
	char *SO_path; 
	char *EA_path;
	char *WE_path; 
	char *sprite_path;
	char *F_rgb;
	char *C_rgb;
	char **map;
	int columns;
	int lines;
	t_player player;
	t_mlx	mlx;
	t_img minimap;
}				t_datas;

int		ft_parsor(char *path, t_datas *map_datas);
int		map_parsor(char *line_map, t_datas *map_datas);
void	ft_display(t_datas *map_datas);

#endif
