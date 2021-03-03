/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:31:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/04 12:02:47 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		init_minimap(t_datas *map, int *k, float *y)
{
	*k = 0;
	map->mini.start_x = 0;
	map->mini.start_y = 0;
	map->c1 = (float)map->mini_x / (float)map->columns;
	map->c2 = (float)map->mini_y / (float)map->lines;
	*y = map->mini.start_y;
}

static void	ft_fork(char c, float x, float y, t_datas *map)
{
	if (c == '1')
		ft_mlx_cube(map, x, y, map->c_rgb);
	else if (c == '0')
		ft_mlx_cube(map, x, y, map->f_rgb);
	else if (c == '2')
		ft_mlx_cube(map, x, y, 0xF01120);
}

static void	ft_minimap2(t_datas *map)
{
	map->c1 = 5.0;
	map->c2 = 5.0;
	ft_mlx_cube(map, map->player.fx - 2.5, map->player.fy - 2.5, 0xFF5733);
	ft_print_ray(map);
	ft_mlx_direction(map, map->c1);
}

int			ft_minimap(t_datas *map)
{
	float	x;
	float	y;
	int		k;
	int		i;

	init_minimap(map, &k, &y);
	while (y < (map->mini_y + map->mini.start_y) && y < map->res_y &&
	map->map[k])
	{
		i = 0;
		x = map->mini.start_x;
		while (x < (map->mini_x + map->mini.start_x) && x < map->res_x &&
		map->map[k][i])
		{
			ft_fork(map->map[k][i], x, y, map);
			x += map->c1;
			i++;
		}
		y += map->c2;
		k++;
	}
	ft_minimap2(map);
	return (0);
}
