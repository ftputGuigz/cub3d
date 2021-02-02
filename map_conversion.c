/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:53:59 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/02 13:15:09 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	invertor_y(t_datas *map, float fy)
{
	float rfy;

	rfy = fy * (float)map->lines / (float)map->res_y;
	return (rfy);
}

float	invertor_x(t_datas *map, float fx)
{
	float rfx;

	rfx = fx * (float)map->columns / (float)map->res_x;
	return (rfx);
}

void	ft_initposition(t_datas *map)
{
	map->player.fx = (float)map->res_x / (float)map->columns * (float)map->player.x;
	map->player.rfx = (float)map->player.x;
	map->player.fy = (float)map->res_y / (float)map->lines * (float)map->player.y;
	map->player.rfy = (float)map->player.y;
}
