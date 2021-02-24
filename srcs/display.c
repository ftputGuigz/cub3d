/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:13:11 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 11:24:04 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char	*dst;

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

int	WASD(int keycode, t_datas *map)
{
	if (keycode == FRONT)
		movement(0.2, map);
	else if (keycode == LEFT)
		ortho_movement(-0.2, map);
	else if (keycode == BACK)
		movement(-0.2, map);
	else if (keycode == RIGHT)
		ortho_movement(0.2, map);
	else if (keycode == ROTATE_LEFT)
		left_rotation(0.1, map);
	else if (keycode == ROTATE_RIGHT)
		right_rotation(0.1, map);
	else if (keycode == ESC)
		ft_exit(map);
	else
		printf("%d\n", keycode);
	return (0);
}

int wasdout(int keycode, t_datas *map)
{
	(void)keycode;
	(void)map;
	return(0);
}

int	load_textures(t_datas *map)
{
	map->txt[0].img = mlx_xpm_file_to_image(map->mlx.ptr, map->NO_path, &map->txt[0].i, &map->txt[0].j);
	map->txt[1].img = mlx_xpm_file_to_image(map->mlx.ptr, map->SO_path, &map->txt[1].i, &map->txt[1].j);
	map->txt[2].img = mlx_xpm_file_to_image(map->mlx.ptr, map->EA_path, &map->txt[2].i, &map->txt[2].j);
	map->txt[3].img = mlx_xpm_file_to_image(map->mlx.ptr, map->WE_path, &map->txt[3].i, &map->txt[3].j);
	map->txt[4].img = mlx_xpm_file_to_image(map->mlx.ptr, map->spr_path, &map->txt[4].i, &map->txt[4].j);
	if (map->txt[0].img == NULL || map->txt[1].img == NULL
		|| map->txt[2].img == NULL || map->txt[3].img == NULL || map->txt[4].img == NULL)
		return (-1);
	map->txt[0].addr = mlx_get_data_addr(map->txt[0].img, &map->txt[0].bits_per_pixel, &map->txt[0].line_length, &map->txt[0].endian);
	map->txt[1].addr = mlx_get_data_addr(map->txt[1].img, &map->txt[1].bits_per_pixel, &map->txt[1].line_length, &map->txt[1].endian);
	map->txt[2].addr = mlx_get_data_addr(map->txt[2].img, &map->txt[2].bits_per_pixel, &map->txt[2].line_length, &map->txt[2].endian);
	map->txt[3].addr = mlx_get_data_addr(map->txt[3].img, &map->txt[3].bits_per_pixel, &map->txt[3].line_length, &map->txt[3].endian);
	map->txt[4].addr = mlx_get_data_addr(map->txt[4].img, &map->txt[4].bits_per_pixel, &map->txt[4].line_length, &map->txt[4].endian);
	return (0);
}

int	ft_display(t_datas *map)
{
	ft_initposition(map);
	map->mlx.ptr = mlx_init();
	if (load_textures(map))
		return (-1);
	map->fps.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y); //IMG FPS
	map->fps.addr = mlx_get_data_addr(map->fps.img, &map->fps.bits_per_pixel, &map->fps.line_length, &map->fps.endian);
	map->minimap.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y); //IMG MINIMAP
	map->minimap.addr = mlx_get_data_addr(map->minimap.img, &map->minimap.bits_per_pixel, &map->minimap.line_length, &map->minimap.endian);
	if (!map->bmp)
	{
		map->mlx.wdw = mlx_new_window(map->mlx.ptr, map->res_x, map->res_y, "Map");
		map->mlx.wdw2 = mlx_new_window(map->mlx.ptr, map->res_x, map->res_y, "FPS");
		mlx_hook(map->mlx.wdw2, 2, 1L<<0, WASD, map);
		mlx_hook(map->mlx.wdw2, 3, 1L<<1, wasdout, map);
		mlx_hook(map->mlx.wdw2, RED_CROSS, RED_CROSS_MASK, ft_exit, map);
	}
	mlx_loop_hook(map->mlx.ptr, ft_fps, map);
	mlx_loop(map->mlx.ptr);
	return (0);
}
