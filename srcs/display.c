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

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		wasd(int keycode, t_datas *map)
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

int		load_textures(t_datas *map)
{
	map->txt[0].img = mlx_xpm_file_to_image(map->mlx.ptr, map->no_path,
	&map->txt[0].i, &map->txt[0].j);
	map->txt[1].img = mlx_xpm_file_to_image(map->mlx.ptr, map->so_path,
	&map->txt[1].i, &map->txt[1].j);
	map->txt[2].img = mlx_xpm_file_to_image(map->mlx.ptr, map->ea_path,
	&map->txt[2].i, &map->txt[2].j);
	map->txt[3].img = mlx_xpm_file_to_image(map->mlx.ptr, map->we_path,
	&map->txt[3].i, &map->txt[3].j);
	map->txt[4].img = mlx_xpm_file_to_image(map->mlx.ptr, map->spr_path,
	&map->txt[4].i, &map->txt[4].j);
	if (map->txt[0].img == NULL || map->txt[1].img == NULL
		|| map->txt[2].img == NULL || map->txt[3].img == NULL ||
		map->txt[4].img == NULL)
		return (-1);
	map->txt[0].addr = mlx_get_data_addr(map->txt[0].img,
	&map->txt[0].bits_per_pixel, &map->txt[0].line_length, &map->txt[0].endian);
	map->txt[1].addr = mlx_get_data_addr(map->txt[1].img,
	&map->txt[1].bits_per_pixel, &map->txt[1].line_length, &map->txt[1].endian);
	map->txt[2].addr = mlx_get_data_addr(map->txt[2].img,
	&map->txt[2].bits_per_pixel, &map->txt[2].line_length, &map->txt[2].endian);
	map->txt[3].addr = mlx_get_data_addr(map->txt[3].img,
	&map->txt[3].bits_per_pixel, &map->txt[3].line_length, &map->txt[3].endian);
	map->txt[4].addr = mlx_get_data_addr(map->txt[4].img,
	&map->txt[4].bits_per_pixel, &map->txt[4].line_length, &map->txt[4].endian);
	return (0);
}

int		ft_display(t_datas *map)
{
	ft_initposition(map);
	if (load_textures(map))
		return (-1);
	map->fps.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y);
	map->fps.addr = mlx_get_data_addr(map->fps.img, &map->fps.bits_per_pixel,
	&map->fps.line_length, &map->fps.endian);
	if (!map->bmp)
	{
		map->mlx.wdw2 = mlx_new_window(map->mlx.ptr, map->res_x, map->res_y,
		"FPS");
		mlx_hook(map->mlx.wdw2, 2, 1L << 0, wasd, map);
		mlx_hook(map->mlx.wdw2, RED_CROSS, 1L << RED_CROSS_MASK, ft_exit, map);
	}
	else
		ft_fps(map);
	mlx_loop_hook(map->mlx.ptr, ft_fps, map);
	mlx_loop(map->mlx.ptr);
	return (0);
}
