/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:59:57 by gpetit            #+#    #+#             */
/*   Updated: 2021/03/02 10:59:59 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	north(t_datas *map, t_ray *ray)
{
	float reste;
	float dist;
	float count;

	count = 0;
	reste = modff(map->player.rfy, &dist);
	while (map->map[(int)(dist - 0.000001)][(int)map->player.rfx] != '1')
	{
		dist--;
		count++;
	}
	ray->xc = map->player.rfx;
	ray->yc = map->player.rfy - (count + reste);
	return (count + reste);
}

static float	south(t_datas *map, t_ray *ray)
{
	float reste;
	float dist;
	float count;

	count = 0;
	reste = 1 - modff(map->player.rfy, &dist);
	dist++;
	while (map->map[(int)(dist + 0.000001)][(int)map->player.rfx] != '1')
	{
		dist++;
		count++;
	}
	ray->xc = map->player.rfx;
	ray->yc = map->player.rfy + (count + reste);
	return (count + reste);
}

static float	east(t_datas *map, t_ray *ray)
{
	float reste;
	float dist;
	float count;

	count = 0;
	reste = 1 - modff(map->player.rfx, &dist);
	dist++;
	while (map->map[(int)map->player.rfy][(int)(dist + 0.000001)] != '1')
	{
		dist++;
		count++;
	}
	ray->xc = map->player.rfx + (count + reste);
	ray->yc = map->player.rfy;
	return (count + reste);
}

static float	west(t_datas *map, t_ray *ray)
{
	float reste;
	float dist;
	float count;

	count = 0;
	reste = modff(map->player.rfx, &dist);
	while (map->map[(int)map->player.rfy][(int)(dist - 0.000001)] != '1')
	{
		dist--;
		count++;
	}
	ray->xc = map->player.rfx - (count + reste);
	ray->yc = map->player.rfy;
	return (count + reste);
}

void			straight_compass(t_datas *map, t_ray *ray, float angle)
{
	if (sinf(angle) == -1)
		ray->r = (north(map, ray));
	if (sinf(angle) == 1)
		ray->r = (south(map, ray));
	if (cosf(angle) == -1)
		ray->r = (west(map, ray));
	if (cosf(angle) == 1)
		ray->r = (east(map, ray));
}
