/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:13:11 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/26 12:20:36 by gpetit           ###   ########.fr       */
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

int	WASD(int keycode, t_datas *map)
{
	if (keycode == 13)
		movement(5, 5, map);
	else if (keycode == 0)
		ortho_movement(-5, -5, map);
	else if (keycode == 1)
		movement(-5, -5, map);
	else if (keycode == 2)
		ortho_movement(5, 5, map);
	else if (keycode == 123)
	{
		map->player.angle -= 0.2;
		map->player.ortho -= 0.2;
	}
	else if (keycode == 124)
	{
		map->player.angle += 0.2;
		map->player.ortho += 0.2;
	}
	else
		printf("%d\n", keycode);
	return (0);
}

int wasdout(int keycode, t_datas *map)
{
	(void)keycode;
	printf("x = %f\ny = %f\n", map->player.fx, map->player.fy);
	printf("angle = %f\northo = %f\n", map->player.angle, map->player.ortho);
	return(0);
}

static void	ft_initposition(t_datas *map)
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
	mlx_hook(map->mlx.wdw, 3, 1L<<1, wasdout, map); //GEStiON KEYOUT + POSITION PERSO
	mlx_loop_hook(map->mlx.ptr, ft_minimap, map);
	mlx_loop(map->mlx.ptr);
}
