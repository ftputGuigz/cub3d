/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:13:11 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/20 17:18:30 by gpetit           ###   ########.fr       */
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
	while (y <= b)
	{
		tmpx = x;
		while (tmpx <= a)
		{
			ft_mlx_pixel_put(img, tmpx, y, color);
			tmpx++;
		}
		y++;
	}
}

int	ft_minimap(t_datas *map_datas)
{
	float c1;
	float c2;
	float x;
	float y = 0;
	int k = 0;
	int i;

	mlx_clear_window(map_datas->mlx.ptr, map_datas->mlx.wdw);
	c1 = (float)map_datas->res_x / (float)map_datas->columns;
	c2 = (float)map_datas->res_y / (float)map_datas->lines;
	while (map_datas->map[k] && y < map_datas->res_y)
	{
		i = 0;
		x = 0;
		while (map_datas->map[k][i] && x < map_datas->res_x)
		{
			if (map_datas->map[k][i] == '1')
				ft_mlx_cube(&map_datas->minimap, x, y, c1, c2, 0x00FF00);
			x += c1;
			i++;
		}
		y += c2;
		k++;
	}
	ft_mlx_cube(&map_datas->minimap, map_datas->fstart_x, map_datas->fstart_y, 5, 5, 0xFF5733);
	mlx_put_image_to_window(map_datas->mlx.ptr, map_datas->mlx.wdw, map_datas->minimap.img, 0, 0);
	return (0);
}

int	wasd(int keycode, t_datas *map_datas)
{
	if (keycode == 13)
		map_datas->fstart_y -= 10;
	else if (keycode == 0)
		map_datas->fstart_x -= 10;
	else if (keycode == 1)
		map_datas->fstart_y += 10;
	else if (keycode == 2)
		map_datas->fstart_x += 10;
	return (0);
}

int wasdout(void *param)
{
	(void)param;
	printf("out\n");
	return(0);
}

void	ft_initposition(t_datas *map_datas)
{
	map_datas->fstart_x = (float)map_datas->res_x / (float)map_datas->columns * (float)map_datas->start_x;
	map_datas->fstart_y = (float)map_datas->res_y / (float)map_datas->lines * (float)map_datas->start_y;
}

void	ft_display(t_datas *map_datas)
{
	void *param;

	ft_initposition(map_datas);
	map_datas->mlx.ptr = mlx_init();
	map_datas->mlx.wdw = mlx_new_window(map_datas->mlx.ptr, map_datas->res_x, map_datas->res_y, "Guigz's Cub3d");
	map_datas->minimap.img = mlx_new_image(map_datas->mlx.ptr, map_datas->res_x, map_datas->res_y);
	map_datas->minimap.addr = mlx_get_data_addr(map_datas->minimap.img, &map_datas->minimap.bits_per_pixel, &map_datas->minimap.line_length, &map_datas->minimap.endian);
	ft_minimap(map_datas);	//EDIT IMAGE CARTE + PERSO 
	mlx_hook(map_datas->mlx.wdw, 2, 1L<<0, wasd, map_datas); //GESTION KEYPRESS
	mlx_loop_hook(map_datas->mlx.ptr, ft_minimap, map_datas);
	mlx_hook(map_datas->mlx.wdw, 3, 1L<<1, wasdout, &param);
	mlx_loop(map_datas->mlx.ptr);
}
