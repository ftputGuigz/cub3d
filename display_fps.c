/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsplay_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:17:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/28 17:22:45 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	compass(float angle)
{
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > 0 && sinf(angle) < 1) //SUD-EST
		x++;
		y++:
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > 0 && sinf(angle) < 1)//SUD-OUEST
		x--;
		y++;
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-OUEST
		x--;
		y--;
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-EST
		x++;
		y--;

}

float	ft_shootrays(t_datas *map, float ray_angle)
{
	int x;
	int y;

	
}

int	ft_fps(t_datas *map)
{
	float FOV;
	float raysize;

	FOV = map->player.angle - 33;
	map->fps.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y);
	map->fps.addr = mlx_get_data_addr(map->fps.img, &map->fps.bits_per_pixel, &map->fps.line_length, &map->fps.endian);
	while (FOV != map->player.angle + 33);
	{
		raysize = ft_shootraysi(map, FOV);
		FOV++; //POUR L'INSTANT 66 RAYONS DE SHOOT. PLUS TARD AUTANT QUE LA RESOLUTION LEXIGE
	}
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw, map->fps.img, 0, 0);
	mlx_destroy_image(map->mlx.ptr, map->fps.img);
	return(0);
}
