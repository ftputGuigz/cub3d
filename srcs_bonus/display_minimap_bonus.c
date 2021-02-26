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
		if ((int)y >= 0 && (int)y < map->res_y && (int)x >= 0 && (int)x < map->res_x && map->map[(int)(y * map->lines / map->res_y)][(int)(x * map->columns / map->res_x)] != '1')
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
		while ((int)y >= 0 && (int)y < map->res_y && (int)x >= 0 && (int)x < map->res_x && map->map[(int)(y * map->lines / map->res_y)][(int)(x * map->columns / map->res_x)] != '1')
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

void	paint_it_black(t_datas *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->res_y)
	{
		x = 0;
		while (x < map->res_x)
		{
			ft_mlx_pixel_put(&map->minimap, x, y, 0x000000);
			x++;
		}
		y++;
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

	paint_it_black(map);
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
	return (0);
}
