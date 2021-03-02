/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:53:19 by gpetit            #+#    #+#             */
/*   Updated: 2021/03/02 10:53:21 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void NE_RAY(t_datas *map, t_ray *ray)
{	
	ray->trix.xb = ceil(ray->trix.xa);
	ray->trix.yb = ray->trix.ya;
	ray->trix.xc = ray->trix.xb;
	ray->trix.yc = ray->trix.yb - tan(ray->trix.angle) * fabsf(ray->trix.xb - ray->trix.xa);
	while ((int)(ray->trix.xc + 0.000001) < map->columns && (int)(ray->trix.yc - 0.000001) > 0 && map->map[(int)(ray->trix.yc - 0.000001)][(int)(ray->trix.xc + 0.000001)] != '1')
	{
		ray->trix.xb++;
		ray->trix.xc = ray->trix.xb;
		ray->trix.yc = ray->trix.yb - tanf(ray->trix.angle) * fabsf(ray->trix.xb - ray->trix.xa);
	}
	ray->trix.r = sqrtf(powf(fabsf(ray->trix.xb - ray->trix.xa), 2) + powf(fabsf(ray->trix.yb - ray->trix.yc), 2));

	ray->triy.yb = floor(ray->triy.ya);
	ray->triy.xb = ray->triy.xa;		
	ray->triy.yc = ray->triy.yb;
	ray->triy.xc = ray->triy.xb + tanf(ray->triy.angle) * fabsf(ray->triy.ya - ray->triy.yb);
	while ((int)(ray->triy.xc + 0.000001) < map->columns && (int)(ray->triy.yc - 0.000001) > 0 && map->map[(int)(ray->triy.yc - 0.000001)][(int)(ray->triy.xc + 0.000001)] != '1')
	{
		ray->triy.yb--;
		ray->triy.yc = ray->triy.yb;
		ray->triy.xc = ray->triy.xb + tanf(ray->triy.angle) * fabsf(ray->triy.ya - ray->triy.yb);
	}
	ray->triy.r = sqrtf(powf(fabsf(ray->triy.yb - ray->triy.ya), 2) + powf(fabsf(ray->triy.xb - ray->triy.xc), 2));
	if (ray->trix.r > ray->triy.r)
	{
		ray->xc = ray->triy.xc;
		ray->yc = ray->triy.yc;
		ray->r = ray->triy.r;
	}
	else
	{
		ray->xc = ray->trix.xc;
		ray->yc = ray->trix.yc;
		ray->r = ray->trix.r;
	}
}

void NW_RAY(t_datas *map, t_ray *ray)
{
	ray->trix.xb = floor(ray->trix.xa);
	ray->trix.yb = ray->trix.ya;
	
	ray->trix.xc = ray->trix.xb;
	ray->trix.yc = ray->trix.yb - tanf(ray->trix.angle) * fabsf(ray->trix.xb - ray->trix.xa);
	while ((int)(ray->trix.xc - 0.000001) > 0 && (int)(ray->trix.yc - 0.000001) > 0 && map->map[(int)(ray->trix.yc - 0.000001)][(int)(ray->trix.xc - 0.000001)] != '1')
	{
		ray->trix.xb--;
		ray->trix.xc = ray->trix.xb;
		ray->trix.yc = ray->trix.yb - tanf(ray->trix.angle) * fabsf(ray->trix.xa - ray->trix.xb);
	}
	ray->trix.r = sqrtf(powf(fabsf(ray->trix.xb - ray->trix.xa), 2) + powf(fabsf(ray->trix.yb - ray->trix.yc), 2));

	ray->triy.yb = floor(ray->triy.ya);
	ray->triy.xb = ray->triy.xa;

	ray->triy.yc = ray->triy.yb;
	ray->triy.xc = ray->triy.xb - tanf(ray->triy.angle) * fabsf(ray->triy.ya - ray->triy.yb);
	while ((int)(ray->triy.xc - 0.000001) > 0 && (int)(ray->triy.yc - 0.000001) > 0 && map->map[(int)(ray->triy.yc - 0.000001)][(int)(ray->triy.xc - 0.000001)] != '1')
	{
		ray->triy.yb--;
		ray->triy.yc = ray->triy.yb;
		ray->triy.xc = ray->triy.xb - tanf(ray->triy.angle) * fabsf(ray->triy.ya - ray->triy.yb);
	}
	ray->triy.r = sqrtf(powf(fabsf(ray->triy.yb - ray->triy.ya), 2) + powf(fabsf(ray->triy.xb - ray->triy.xc), 2));
	if (ray->trix.r > ray->triy.r)
	{
		ray->xc = ray->triy.xc;
		ray->yc = ray->triy.yc;
		ray->r = ray->triy.r;
	}
	else
	{
		ray->xc = ray->trix.xc;
		ray->yc = ray->trix.yc;
		ray->r = ray->trix.r;
	}
}

void SW_RAY(t_datas *map, t_ray *ray)
{
	ray->trix.xb = floor(ray->trix.xa);
	ray->trix.yb = ray->trix.ya;
	
	ray->trix.xc = ray->trix.xb;
	ray->trix.yc = ray->trix.yb + tanf(ray->trix.angle) * fabsf(ray->trix.xb - ray->trix.xa);
	while ((int)(ray->trix.xc - 0.000001) > 0 && (int)(ray->trix.yc + 0.000001) < map->lines && map->map[(int)(ray->trix.yc + 0.000001)][(int)(ray->trix.xc - 0.000001)] != '1')
	{
		ray->trix.xb--;
		ray->trix.xc = ray->trix.xb;
		ray->trix.yc = ray->trix.yb + tanf(ray->trix.angle) * fabsf(ray->trix.xb - ray->trix.xa);
	}
	ray->trix.r = sqrtf(powf(fabsf(ray->trix.xb - ray->trix.xa), 2) + powf(fabsf(ray->trix.yb - ray->trix.yc), 2));

	ray->triy.yb = ceil(ray->triy.ya);
	ray->triy.xb = ray->triy.xa;		
	
	ray->triy.yc = ray->triy.yb;
	ray->triy.xc = ray->triy.xb - tanf(ray->triy.angle) * fabsf(ray->triy.ya - ray->triy.yb);
	while ((int)(ray->triy.xc - 0.000001) > 0 && (int)(ray->triy.yc + 0.000001) < map->lines && map->map[(int)(ray->triy.yc + 0.000001)][(int)(ray->triy.xc - 0.000001)] != '1')
	{
		ray->triy.yb++;
		ray->triy.yc = ray->triy.yb;
		ray->triy.xc = ray->triy.xb - tanf(ray->triy.angle) * fabsf(ray->triy.ya - ray->triy.yb);
	}
	ray->triy.r = sqrtf(powf(fabsf(ray->triy.yb - ray->triy.ya), 2) + powf(fabsf(ray->triy.xb - ray->triy.xc), 2));
	if (ray->trix.r > ray->triy.r)
	{
		ray->xc = ray->triy.xc;
		ray->yc = ray->triy.yc;
		ray->r = ray->triy.r;
	}
	else
	{
		ray->xc = ray->trix.xc;
		ray->yc = ray->trix.yc;
		ray->r = ray->trix.r;
	}
}

void SE_RAY(t_datas *map, t_ray *ray)
{
	ray->trix.xb = ceil(ray->trix.xa);
	ray->trix.yb = ray->trix.ya;
	
	ray->trix.xc = ray->trix.xb;
	ray->trix.yc = ray->trix.yb + tanf(ray->trix.angle) * fabsf(ray->trix.xb - ray->trix.xa);
	while ((int)(ray->trix.xc + 0.000001) < map->columns && (int)(ray->trix.yc + 0.000001) < map->lines && map->map[(int)(ray->trix.yc + 0.000001)][(int)(ray->trix.xc + 0.000001)] != '1')
	{
		ray->trix.xb++;
		ray->trix.xc = ray->trix.xb;
		ray->trix.yc = ray->trix.yb + tanf(ray->trix.angle) * fabsf(ray->trix.xb - ray->trix.xa);
	}
	ray->trix.r = sqrtf(powf(fabsf(ray->trix.xb - ray->trix.xa), 2) + powf(fabsf(ray->trix.yb - ray->trix.yc), 2));
	
	ray->triy.yb = ceil(ray->triy.ya);
	ray->triy.xb = ray->triy.xa;		
	
	ray->triy.yc = ray->triy.yb;
	ray->triy.xc = ray->triy.xb + tanf(ray->triy.angle) * fabsf(ray->triy.ya - ray->triy.yb);
	while ((int)(ray->triy.xc + 0.000001) < map->columns && (int)(ray->triy.yc + 0.000001) < map->lines && map->map[(int)(ray->triy.yc + 0.000001)][(int)(ray->triy.xc + 0.000001)] != '1')
	{
		ray->triy.yb++;
		ray->triy.yc = ray->triy.yb;
		ray->triy.xc = ray->triy.xb + tanf(ray->triy.angle) * fabsf(ray->triy.ya - ray->triy.yb);
	}
	ray->triy.r = sqrtf(powf(fabsf(ray->triy.yb - ray->triy.ya), 2) + powf(fabsf(ray->triy.xb - ray->triy.xc), 2));
	if (ray->trix.r > ray->triy.r)
	{
		ray->xc = ray->triy.xc;
		ray->yc = ray->triy.yc;
		ray->r = ray->triy.r;
	}
	else
	{
		ray->xc = ray->trix.xc;
		ray->yc = ray->trix.yc;
		ray->r = ray->trix.r;
	}
}
