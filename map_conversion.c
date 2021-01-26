/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:53:59 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/26 17:10:50 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	invertor_y(t_datas *map, float fy)
{
	float y;

	y = fy * map->lines / map->res_y;
	return ((int)y);
}

int	invertor_x(t_datas *map, float fx)
{
	float x;

	x = fx * map->columns / map->res_x;
	return ((int)x);
}

/*float	real_x(float position_x, t_datas *maps)
{
	float x;

	x = position_x * (float)map->columns / (float)map->res_x;
	return (x);
}

float	real_y(float position_y, t_datas *maps)
{
	float y;

	y = position_y * (float)map->lines / (float)map->res_y;
	return (y);
}

void	rfx(t_datas *map)
{
	map->player.rfx = map->player.fx * (float)map->columns / (float)map->res_x;
	map->player.rfy = map->player.fy * (float)map->lines / (float)map->res_y;
}*/

void	ft_initposition(t_datas *map)
{
	map->player.fx = (float)map->res_x / (float)map->columns * (float)map->player.x;
	map->player.fy = (float)map->res_y / (float)map->lines * (float)map->player.y;
}
