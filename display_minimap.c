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

#include "cub3d.h"

void	movement(float i, t_datas *map)
{
	if (map->map[(int)map->player.rfy][(int)(map->player.rfx + 2 * i * cosf(map->player.angle))] == '0')
	{
		map->player.rfx = map->player.rfx + i * cosf(map->player.angle);
		map->player.fx = ((float)map->player.rfx * (float)map->res_x) / (float)map->columns;
	}
	if (map->map[(int)(map->player.rfy + 2 * i * sinf(map->player.angle))][(int)map->player.rfx] == '0')
	{
		map->player.rfy = map->player.rfy + i * sinf(map->player.angle);
		map->player.fy = ((float)map->player.rfy * (float)map->res_y) / (float)map->lines;
	}
}

void	ortho_movement(float i, t_datas *map)
{
	if (map->map[(int)map->player.rfy][(int)(map->player.rfx + 2 * i * cosf(map->player.ortho))] == '0')
	{
		map->player.rfx = map->player.rfx + i * cosf(map->player.ortho);
		map->player.fx = (float)map->player.rfx * (float)map->res_x / (float)map->columns;
	}
	if (map->map[(int)(map->player.rfy + 2 * i * sinf(map->player.ortho))][(int)map->player.rfx] == '0')
	{
		map->player.rfy = map->player.rfy + i * sinf(map->player.ortho);
		map->player.fy = (float)map->player.rfy * (float)map->res_y / (float)map->lines;
	}
}

static void	ft_mlx_direction(t_datas *map, float c1)
{
	float x;
	float y;
	float r;

	r = c1;
	while (r >= 0)
	{
		x = map->player.fx + (r * cosf(map->player.angle));
		y = map->player.fy + (r * sinf(map->player.angle));
		ft_mlx_pixel_put(&map->minimap, x, y, 0xFF0000);
		r = r - 0.1; //changer decrementation
	}
}

static void	ft_print_ray(t_datas *map)
{
	float x;
	float y;
	float ray;
	float angle;

	angle = map->player.angle - 0.575959;
	//angle = map->player.angle - 2 * M_PI;
	while (angle <= map->player.angle + 0.575959)		
	{
		x = map->player.fx;
		y = map->player.fy;
		ray = 0;
		while ((int)y >= 0 && (int)y < map->res_y && (int)x >= 0 && (int)x < map->res_x && map->map[(int)(y * map->lines / map->res_y)][(int)(x * map->columns / map->res_x)] == '0')
		{
			x = map->player.fx + (ray * cosf(angle)); //remettre ANGLE
			y = map->player.fy + (ray * sinf(angle)); //REMETTRE ANGLE
			ft_mlx_pixel_put(&map->minimap, x, y, 0xFFF000);
			ray = ray + 0.2; //changer decrementation
		}
		angle = angle + 0.08;
	}
}

static void grid_print(t_datas *map)
{
	float x;
	float x2;
	float y2;
	float y;
	float c1;
	float c2;

	c1 = (float)map->res_x / (float)map->columns;
	c2 = (float)map->res_y / (float)map->lines;
	x = 0;
	while (x < map->res_x)
	{
		y2 = 0;
		while(y2 < map->res_y)
		{
			ft_mlx_pixel_put(&map->minimap, x, y2, 0xFF3599);
			y2 += 0.1;
		}
		x += c1;
	}
	y = 0;
	while (y < map->res_y)
	{
		x2 = 0;
		while(x2 < map->res_x)
		{
			ft_mlx_pixel_put(&map->minimap, x2, y, 0xFF3599);
			x2 += 0.1;
		}
		y += c2;
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
	c2 = (float)(map->res_y / (float)map->lines);
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
	ft_mlx_cube(&map->minimap, map->player.fx - 2.5, map->player.fy - 2.5, 5.0, 5.0, 0xFF5733);
	grid_print(map); //GRILLE
	ft_print_ray(map); //RAYONS - FOV
	ft_mlx_direction(map, c1); // RAYON - DIRECTION
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw, map->minimap.img, 0, 0);
	mlx_destroy_image(map->mlx.ptr, map->minimap.img);
	return (0);
}
