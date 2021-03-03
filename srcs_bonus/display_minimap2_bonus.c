/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:31:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/04 12:02:47 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_mlx_direction(t_datas *map, float c1)
{
	float x;
	float y;
	float r;

	r = c1;
	while (r >= 0)
	{
		x = map->player.fx + (r * cosf(map->player.angle));
		y = map->player.fy + (r * sinf(map->player.angle));
		if ((int)y >= 0 && (int)y < map->mini_y && y < map->res_y && (int)x >= 0
		&& (int)x < map->mini_x && map->map[(int)(y * map->lines / map->mini_y)]
		[(int)(x * map->columns / map->mini_x)] != '1')
			ft_mlx_pixel_put(&map->fps, x, y, 0xFF0000);
		r = r - 0.1;
	}
}

void	ft_print_ray(t_datas *map)
{
	float x;
	float y;
	float ray;
	float angle;

	angle = map->player.angle - 0.575959;
	while (angle <= map->player.angle + 0.575959)
	{
		x = map->player.fx;
		y = map->player.fy;
		ray = 0;
		while ((int)y >= 0 && (int)y < map->mini_y && y < map->res_y && (int)x
		>= 0 && (int)x < map->mini_x && map->map[(int)(y * map->lines /
		map->mini_y)][(int)(x * map->columns / map->mini_x)] != '1')
		{
			x = map->player.fx + (ray * cosf(angle));
			y = map->player.fy + (ray * sinf(angle));
			ft_mlx_pixel_put(&map->fps, x, y, 0xFFF000);
			ray = ray + 0.2;
		}
		angle = angle + 0.08;
	}
}
