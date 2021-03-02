/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:17:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/27 13:59:52 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_shootrays(t_datas *map, float ray_angle, t_ray *ray, int x)
{
	float fisheye_angle;

	ray->trix.xa = map->player.rfx;
	ray->trix.ya = map->player.rfy;
	ray->triy.xa = map->player.rfx;
	ray->triy.ya = map->player.rfy;
	if (ray_angle > map->player.angle)
		fisheye_angle = ray_angle - map->player.angle;
	else
		fisheye_angle = map->player.angle - ray_angle;
	compass(map, ray_angle, ray);
	ray->r *= cosf(fisheye_angle);
	map->buff[x] = ray->r;
}

int		ft_fps(t_datas *map)
{
	t_ray	ray;
	float	fov;
	int		x;
	float	ray_p;

	x = 0;
	fov = map->player.angle - 0.575959;
	while (x < map->res_x && fov <= (map->player.angle + 0.575959))
	{
		ft_shootrays(map, fov, &ray, x);
		ray_p = ((float)(map->res_y) * 1 / ray.r);
		print_ray(map, x, ray_p, &ray);
		x++;
		fov = map->player.angle + atanf((x - map->res_x / 2) /
		((map->res_x / 2) / tanf(1.15192 / 2)));
	}
	ft_sprites(map);
	if (map->bmp)
		make_bmp(map);
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw2, map->fps.img, 0, 0);
	return (0);
}
