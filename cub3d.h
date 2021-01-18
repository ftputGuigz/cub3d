/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:43:05 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/18 17:13:46 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <fcntl.h>

# include "./srcs/libft/libft.h"
# include "./srcs/gnl/get_next_line.h"

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
}				t_datas;

int	ft_parsor(char *path, t_datas *map_datas);
char **map_parsor(char *line_map);

#endif
