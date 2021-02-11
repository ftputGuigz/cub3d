/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:13:11 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/04 12:02:48 by gpetit           ###   ########.fr       */
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
	if (keycode == 13)
		movement(0.2, map);
	else if (keycode == 0)
		ortho_movement(-0.2, map);
	else if (keycode == 1)
		movement(-0.2, map);
	else if (keycode == 2)
		ortho_movement(0.2, map);
	else if (keycode == 123)
	{
		map->player.angle -= 0.1;
		map->player.ortho -= 0.1;
	}
	else if (keycode == 124)
	{
		map->player.angle += 0.1;
		map->player.ortho += 0.1;
	}
	else
		printf("%d\n", keycode);
	return (0);
}

int wasdout(int keycode) //, t_datas *map)
{
	(void)keycode;
	//printf("cos(angle) = %f\n", cosf(map->player.angle));
	//printf("sin(angle) = %f\n", sinf(map->player.angle));
	//printf("rfx = %f\nrfy = %f\n", map->player.rfx, map->player.rfy);
	//printf("angle = %f\nangle2 = %f\n", map->player.angle, M_PI_2 - map->player.angle);
	//printf("final ray = %f\n<============>\n", ft_fps(map));
	return(0);
}

int	load_textures(t_datas *map)
{
	map->txt[0].img = mlx_xpm_file_to_image (map->mlx.ptr, "./texturesMinecraft/stone.xpm", &map->txt[0].i, &map->txt[0].j);
	map->txt[1].img = mlx_xpm_file_to_image (map->mlx.ptr, "./texturesMinecraft/brick.xpm", &map->txt[1].i, &map->txt[1].j);
	map->txt[2].img = mlx_xpm_file_to_image (map->mlx.ptr, "./texturesMinecraft/wood.xpm", &map->txt[2].i, &map->txt[2].j);
	map->txt[3].img = mlx_xpm_file_to_image (map->mlx.ptr, "./texturesMinecraft/grass.xpm", &map->txt[3].i, &map->txt[3].j);
	if (map->txt[0].img == NULL || map->txt[1].img == NULL || map->txt[2].img == NULL || map->txt[3].img == NULL)
		return (-1);
	map->txt[0].addr = mlx_get_data_addr(map->txt[0].img, &map->txt[0].bits_per_pixel, &map->txt[0].line_length, &map->txt[0].endian);
	map->txt[1].addr = mlx_get_data_addr(map->txt[1].img, &map->txt[1].bits_per_pixel, &map->txt[1].line_length, &map->txt[1].endian);
	map->txt[2].addr = mlx_get_data_addr(map->txt[2].img, &map->txt[2].bits_per_pixel, &map->txt[2].line_length, &map->txt[2].endian);
	map->txt[3].addr = mlx_get_data_addr(map->txt[3].img, &map->txt[3].bits_per_pixel, &map->txt[3].line_length, &map->txt[3].endian);
	return (0);
}

void	ft_display(t_datas *map)
{
	ft_initposition(map);
	map->mlx.ptr = mlx_init();
	load_textures(map);
	map->mlx.wdw = mlx_new_window(map->mlx.ptr, map->res_x, map->res_y, "Map");
	map->mlx.wdw2 = mlx_new_window(map->mlx.ptr, map->res_x, map->res_y, "FPS");
	ft_fps(map);	// MINIMAP APPELEE ICI EDIT IMAGE CARTE + PERSO
	mlx_hook(map->mlx.wdw2, 2, 1L<<0, WASD, map); //GESTION KEYPRESS
	mlx_hook(map->mlx.wdw2, 3, 1L<<1, wasdout, map); //GEStiON KEYOUT + POSITION PERSO
	mlx_loop_hook(map->mlx.ptr, ft_fps, map);
	mlx_loop(map->mlx.ptr);
}