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

void lodev_positions2(t_datas *map)
{
	if (map->player.start == 'E')
	{
		map->player.dirx = 1;
		map->player.diry = 0;
		map->player.planx = 0;
		map->player.plany = -0.66;
	}
	else if (map->player.start == 'W')
	{
		map->player.dirx = -1;
		map->player.diry = 0;
		map->player.planx = 0;
		map->player.plany = 0.66;
	}
}

void lodev_positions1(t_datas *map)
{
	if (map->player.start == 'N')
	{
		map->player.dirx = 0;
		map->player.diry = -1;
		map->player.planx = -0.66;
		map->player.plany = 0;
	}
	else if (map->player.start == 'S')
	{
		map->player.dirx = 0;
		map->player.diry = 1;
		map->player.planx = 0.66;
		map->player.plany = 0;
	}
	lodev_positions2(map);
}

void	sprites_buffer(t_datas *map) //MALLOC DONC AJOUTER PROTECTION
{
	map->buff = malloc(sizeof(float) * map->res_x);
	ft_bzero(map->buff, sizeof(float) * map->res_x);
}

void	ft_initposition(t_datas *map)
{
	map->player.rfx = (float)map->player.x + 0.5;
	map->player.fx = map->player.rfx * (float)map->res_x / (float)map->columns;
	map->player.rfy = (float)map->player.y + 0.5;
	map->player.fy = map->player.rfy * (float)map->res_y / (float)map->lines;
	lodev_positions1(map);
	sprites_buffer(map);
}

void	right_rotation(float rot, t_datas *map)
{
	float tmp;
	float tmp2;

	map->player.angle += rot;
	map->player.ortho += rot;

	tmp = map->player.dirx;
	map->player.dirx = map->player.dirx * cos(rot) - map->player.diry * sin(rot);
	map->player.diry = tmp * sin(rot) + map->player.diry * cos(rot);

	tmp2 = map->player.planx;
	map->player.planx = map->player.planx * cos(rot) - map->player.plany * sin(rot);
	map->player.plany = tmp2 * sin(rot) + map->player.plany * cos(rot);
}

void	left_rotation(float rot, t_datas *map)
{
	float tmp;
	float tmp2;

	map->player.angle -= rot;
	map->player.ortho -= rot;

	tmp = map->player.dirx;
	map->player.dirx = map->player.dirx * cos(-rot) - map->player.diry * sin(-rot);
	map->player.diry = tmp * sin(-rot) + map->player.diry * cos(-rot);

	tmp2 = map->player.planx;
	map->player.planx = map->player.planx * cos(-rot) - map->player.plany * sin(-rot);
	map->player.plany = tmp2 * sin(-rot) + map->player.plany * cos(-rot);
}

void	movement(float i, t_datas *map)
{
	if (map->map[(int)map->player.rfy][(int)(map->player.rfx + 2 * i * cosf(map->player.angle))] != '1')
	{
		map->player.rfx = map->player.rfx + i * cosf(map->player.angle);
		map->player.fx = ((float)map->player.rfx * (float)map->res_x) / (float)map->columns;
	}
	if (map->map[(int)(map->player.rfy + 2 * i * sinf(map->player.angle))][(int)map->player.rfx] != '1')
	{
		map->player.rfy = map->player.rfy + i * sinf(map->player.angle);
		map->player.fy = ((float)map->player.rfy * (float)map->res_y) / (float)map->lines;
	}
}

void	ortho_movement(float i, t_datas *map)
{
	if (map->map[(int)map->player.rfy][(int)(map->player.rfx + 2 * i * cosf(map->player.ortho))] != '1')
	{
		map->player.rfx = map->player.rfx + i * cosf(map->player.ortho);
		map->player.fx = (float)map->player.rfx * (float)map->res_x / (float)map->columns;
	}
	if (map->map[(int)(map->player.rfy + 2 * i * sinf(map->player.ortho))][(int)map->player.rfx] != '1')
	{
		map->player.rfy = map->player.rfy + i * sinf(map->player.ortho);
		map->player.fy = (float)map->player.rfy * (float)map->res_y / (float)map->lines;
	}
}