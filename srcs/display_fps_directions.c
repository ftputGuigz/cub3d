/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:13:22 by gpetit            #+#    #+#             */
/*   Updated: 2021/03/02 11:13:24 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_direction(t_datas *map, t_ray *ray)
{
	if (map->map[(int)(ray->yc - 0.000001)][(int)ray->xc] == '1' &&
	map->map[(int)ray->yc][(int)(ray->xc + 0.000001)] != '1')
		ray->dir = 'N';
	else if (map->map[(int)ray->yc][(int)(ray->xc + 0.000001)] == '1' &&
	map->map[(int)(ray->yc - 0.000001)][(int)ray->xc] != '1')
		ray->dir = 'E';
	else if (map->map[(int)(ray->yc + 0.000001)][(int)ray->xc] == '1' &&
	map->map[(int)ray->yc][(int)(ray->xc - 0.000001)] != '1')
		ray->dir = 'S';
	else if (map->map[(int)ray->yc][(int)(ray->xc - 0.000001)] == '1' &&
	map->map[(int)(ray->yc + 0.000001)][(int)ray->xc] != '1')
		ray->dir = 'W';
}

void	set_angle(int code, float angle, t_ray *ray, t_datas *map)
{
	if (code == 1)
	{
		ray->trix.angle = angle;
		ray->triy.angle = M_PI_2 - ray->trix.angle;
		SE_RAY(map, ray);
	}
	if (code == 2)
	{
		ray->trix.angle = M_PI - angle;
		ray->triy.angle = M_PI_2 - ray->trix.angle;
		SW_RAY(map, ray);
	}
	if (code == 3)
	{
		ray->trix.angle = angle - M_PI;
		ray->triy.angle = M_PI_2 - ray->trix.angle;
		NW_RAY(map, ray);
	}
	if (code == 4)
	{
		ray->triy.angle = angle - (3 * M_PI_2);
		ray->trix.angle = M_PI_2 - ray->triy.angle;
		NE_RAY(map, ray);
	}
}

void	compass(t_datas *map, float angle, t_ray *ray)
{
	if (cosf(angle) == 1 || cosf(angle) == -1 || sinf(angle) == 1 ||
	sinf(angle) == -1)
		straight_compass(map, ray, angle);
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > 0 &&
	sinf(angle) < 1)
		set_angle(1, angle, ray, map);
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > 0 &&
	sinf(angle) < 1)
		set_angle(2, angle, ray, map);
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > -1 &&
	sinf(angle) < 0)
		set_angle(3, angle, ray, map);
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > -1 &&
	sinf(angle) < 0)
		set_angle(4, angle, ray, map);
	set_direction(map, ray);
}
