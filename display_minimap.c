/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:31:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/01 13:06:35 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	movement(int i, int j, t_datas *map)
{
	if (map->map[(int)invertor_y(map, map->player.fy)][(int)invertor_x(map, map->player.fx + (i * cosf(map->player.angle)))] == '0')
	{
		map->player.fx = map->player.fx + (i * cosf(map->player.angle));
		map->player.rfx = invertor_x(map, map->player.fx);
	}
	//	printf("%f\n", map->player.fx);
	if (map->map[(int)invertor_y(map,map->player.fy + (j * sinf(map->player.angle)))][(int)invertor_x(map, map->player.fx)] == '0')
	{
		map->player.fy = map->player.fy + (j * sinf(map->player.angle));
		map->player.rfy = invertor_y(map, map->player.fy);
	}
	//	printf("%f\n", map->player.fy);
}

void	ortho_movement(int i, int j, t_datas *map)
{
	if (map->map[(int)invertor_y(map, map->player.fy)][(int)invertor_x(map, map->player.fx + (i * cosf(map->player.ortho)))] == '0')
	{
		map->player.fx = map->player.fx + (i * cosf(map->player.ortho));
		map->player.rfx = invertor_x(map, map->player.fx);
	}
	if (map->map[(int)invertor_y(map,map->player.fy + (j * sinf(map->player.ortho)))][(int)invertor_x(map, map->player.fx)] == '0')
	{
		map->player.fy = map->player.fy + (j * sinf(map->player.ortho));
		map->player.rfy = invertor_y(map, map->player.fy);
	}
}

static void	ft_mlx_direction(t_datas *map, float c1, float c2)
{
	float x;
	float y;
	float r;

	r = c1;
	while (r >= 0)
	{
		x = map->player.fx + (r * cosf(map->player.angle));
		y = map->player.fy + (r * sinf(map->player.angle));
		ft_mlx_pixel_put(&map->minimap, x + c1 / 2, y + c2 / 2, 0x00FF00);
		r = r - 0.5; //changer decrementation
	}
}

int	ft_minimap(t_datas *map)
{
	float c1;
	float c2;
	float x;
	float y = 0;
	int k = 0;
	int i;

	map->minimap.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y);
	map->minimap.addr = mlx_get_data_addr(map->minimap.img, &map->minimap.bits_per_pixel, &map->minimap.line_length, &map->minimap.endian);
	c1 = (float)map->res_x / (float)map->columns;
	c2 = (float)map->res_y / (float)map->lines;
	while (y <= map->res_y && map->map[k])
	{
		i = 0;
		x = 0;
		while (x <= map->res_x && map->map[k][i]) // <= peut etre responsable d'une SEGFAULT
		{
			if (map->map[k][i] == '1')
				ft_mlx_cube(&map->minimap, x, y, c1, c2, 0x00FF00);
			x += c1;
			i++;
		}
		y += c2;
		k++;
	}
	ft_mlx_cube(&map->minimap, map->player.fx, map->player.fy, c1, c2, 0xFF5733);
	ft_mlx_direction(map, c1, c2);
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw, map->minimap.img, 0, 0);
	mlx_destroy_image(map->mlx.ptr, map->minimap.img);
	return (0);
}
