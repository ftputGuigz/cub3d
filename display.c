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

void ft_mlx_wall(t_img *img, int x, int y, int c1, int c2, int color)
{
	int a;
	int b;
	int tmpx;

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

void	ft_minimap(t_img *minimap, t_datas *map_datas)
{
	int c1;
	int c2;
	int x;
	int y = 0;
	int k = 0;
	int i;

	c1 = map_datas->res_x / map_datas->columns;
	printf("c1 vaut %d\n", c1);
	c2 = map_datas->res_y / map_datas->lines;
	printf("c2 vaut %d\n", c2);
	while (map_datas->map[k] && y < map_datas->res_y)
	{
		i = 0;
		x = 0;
		while (map_datas->map[k][i] && x < map_datas->res_x)
		{
			if (map_datas->map[k][i] == '1')
			{
				ft_mlx_wall(minimap, x, y, c1, c2, 0x00FF00);
				printf("x = %d\ny = %d\n", x, y);
			}
			x += c1;
			i++;
		}
		y += c2;
		k++;
	}
}

void	ft_display(t_datas *map_datas)
{
	t_mlx mlx;
	t_img minimap;
	
	mlx.ptr = mlx_init();
	mlx.wdw = mlx_new_window(mlx.ptr, map_datas->res_x, map_datas->res_y, "Guigz's Cub3d");
	minimap.img = mlx_new_image(mlx.ptr, map_datas->res_x, map_datas->res_y);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel, &minimap.line_length, &minimap.endian);
	ft_minimap(&minimap, map_datas);//IMPRIMER MINIMAP
	mlx_put_image_to_window(mlx.ptr, mlx.wdw, minimap.img, 0, 0);
	mlx_loop(mlx.ptr);
}
