/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:13:11 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/25 12:29:48 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void ft_mlx_cube(t_img *img, float x, float y, float c1, float c2, int color)
{
	float a;
	float b;
	float tmpx;

	a = x + c1;
	b = y + c2;
	while (y < b)
	{
		tmpx = x;
		while (tmpx < a)
		{
			ft_mlx_pixel_put(img, tmpx, y, color);
			tmpx++;
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
	ft_mlx_cube(&map->minimap, map->player.fx, map->player.fy, 5, 5, 0xFF5733);
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw, map->minimap.img, 0, 0);
	mlx_destroy_image(map->mlx.ptr, map->minimap.img);
	return (0);
}

int	WASD(int keycode, t_datas *map)
{
	if (keycode == 13)
		map->player.fy -= 5;
	else if (keycode == 0)
		map->player.fx -= 5;
	else if (keycode == 1)
		map->player.fy += 5;
	else if (keycode == 2)
		map->player.fx += 5;
	return (0);
}

int wasdout(void *param)
{
	(void)param;
	printf("out\n");
	return(0);
}

void	ft_initposition(t_datas *map)
{
	map->player.fx = (float)map->res_x / (float)map->columns * (float)map->player.x;
	map->player.fy = (float)map->res_y / (float)map->lines * (float)map->player.y;
}

void	ft_display(t_datas *map)
{
	//void *param;

	ft_initposition(map);
	map->mlx.ptr = mlx_init();
	map->mlx.wdw = mlx_new_window(map->mlx.ptr, map->res_x, map->res_y, "Guigz's Cub3d");
	ft_minimap(map);	//EDIT IMAGE CARTE + PERSO 
	mlx_hook(map->mlx.wdw, 2, 1L<<0, WASD, map); //GESTION KEYPRESS
	mlx_loop_hook(map->mlx.ptr, ft_minimap, map);
	//mlx_hook(map->mlx.wdw, 3, 1L<<1, wasdout, &param);
	mlx_loop(map->mlx.ptr);
}
