/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:07:42 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 19:34:54 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#if (LINUX)

void	screen_size(t_datas *map)
{
	int sizex;
	int sizey;

	mlx_get_screen_size(map->mlx.ptr, &sizex, &sizey);
	if (map->res_x > sizex)
		map->res_x = sizex;
	if (map->res_y > sizey)
		map->res_y = sizey;
}

#else

void	screen_size(t_datas *map)
{
	if (map->res_x > MAX_X)
		map->res_x = MAX_X;
	if (map->res_y > MAX_Y)
		map->res_y = MAX_Y;
}

#endif
