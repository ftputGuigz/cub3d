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

#include "cub3d_bonus.h"

void	right_rotation(float rot, t_datas *map)
{
	float tmp;
	float tmp2;

	map->player.angle += rot;
	map->player.ortho += rot;
	tmp = map->player.dirx;
	map->player.dirx = map->player.dirx * cos(rot) - map->player.diry *
	sin(rot);
	map->player.diry = tmp * sin(rot) + map->player.diry * cos(rot);
	tmp2 = map->player.planx;
	map->player.planx = map->player.planx * cos(rot) - map->player.plany *
	sin(rot);
	map->player.plany = tmp2 * sin(rot) + map->player.plany * cos(rot);
}

void	left_rotation(float rot, t_datas *map)
{
	float tmp;
	float tmp2;

	map->player.angle -= rot;
	map->player.ortho -= rot;
	tmp = map->player.dirx;
	map->player.dirx = map->player.dirx * cos(-rot) - map->player.diry *
	sin(-rot);
	map->player.diry = tmp * sin(-rot) + map->player.diry * cos(-rot);
	tmp2 = map->player.planx;
	map->player.planx = map->player.planx * cos(-rot) - map->player.plany *
	sin(-rot);
	map->player.plany = tmp2 * sin(-rot) + map->player.plany * cos(-rot);
}

void	movement(float i, t_datas *map)
{
	if (map->map[(int)map->player.rfy][(int)(map->player.rfx + 2 * i *
	cosf(map->player.angle))] != '1' &&
	map->map[(int)map->player.rfy][(int)(map->player.rfx + 2 * i *
	cosf(map->player.angle))] != '2')
	{
		map->player.rfx = map->player.rfx + i * cosf(map->player.angle);
		map->player.fx = ((float)map->player.rfx * (float)map->mini_x) /
		(float)map->columns;
	}
	if (map->map[(int)(map->player.rfy + 2 * i *
	sinf(map->player.angle))][(int)map->player.rfx] != '1' &&
	map->map[(int)(map->player.rfy + 2 * i *
	sinf(map->player.angle))][(int)map->player.rfx] != '2')
	{
		map->player.rfy = map->player.rfy + i * sinf(map->player.angle);
		map->player.fy = ((float)map->player.rfy * (float)map->mini_y) /
		(float)map->lines;
	}
}

void	ortho_movement(float i, t_datas *map)
{
	if (map->map[(int)map->player.rfy][(int)(map->player.rfx + 2 * i *
	cosf(map->player.ortho))] != '1' &&
	map->map[(int)map->player.rfy][(int)(map->player.rfx + 2 * i *
	cosf(map->player.ortho))] != '2')
	{
		map->player.rfx = map->player.rfx + i * cosf(map->player.ortho);
		map->player.fx = (float)map->player.rfx * (float)map->mini_x /
		(float)map->columns;
	}
	if (map->map[(int)(map->player.rfy + 2 * i *
	sinf(map->player.ortho))][(int)map->player.rfx] != '1' &&
	map->map[(int)(map->player.rfy + 2 * i *
	sinf(map->player.ortho))][(int)map->player.rfx] != '2')
	{
		map->player.rfy = map->player.rfy + i * sinf(map->player.ortho);
		map->player.fy = (float)map->player.rfy * (float)map->mini_y /
		(float)map->lines;
	}
}
