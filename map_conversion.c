/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:53:59 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/28 11:21:55 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	invertor_y(t_datas *map, float fy)
{
	float y;

	y = fy * (float)map->lines / (float)map->res_y;
	return (y);
}

float	invertor_x(t_datas *map, float fx)
{
	float x;

	x = fx * (float)map->columns / (float)map->res_x;
	return (x);
}

void	ft_initposition(t_datas *map)
{
	map->player.fx = (float)map->res_x / (float)map->columns * (float)map->player.x;
	map->player.rfx = (float)map->player.x;
	map->player.fy = (float)map->res_y / (float)map->lines * (float)map->player.y;
	map->player.rfy = (float)map->player.y;
}
