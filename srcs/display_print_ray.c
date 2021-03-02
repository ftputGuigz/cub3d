/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_print_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:09:41 by gpetit            #+#    #+#             */
/*   Updated: 2021/03/02 12:09:43 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		texture_number(char orientation)
{
	if (orientation == 'N')
		return (0);
	if (orientation == 'S')
		return (1);
	if (orientation == 'W')
		return (2);
	if (orientation == 'E')
		return (3);
	return (0);
}

int		painter(t_datas *map, t_ray *ray, float y_tex)
{
	int		rank;
	float	reste;
	float	x_tex;
	char	*color;
	int		color2;

	rank = texture_number(ray->dir);
	if (ray->dir == 'N')
		x_tex = modff(ray->xc, &reste) * map->txt[rank].i;
	else if (ray->dir == 'S')
		x_tex = (1 - modff(ray->yc, &reste)) * map->txt[rank].i;
	else if (ray->dir == 'W')
		x_tex = (1 - modff(ray->yc, &reste)) * map->txt[rank].i;
	else
		x_tex = modff(ray->xc, &reste) * map->txt[rank].i;
	color = map->txt[rank].addr + ((int)y_tex * map->txt[rank].line_length +
	(int)x_tex * (map->txt[rank].bits_per_pixel / 8));
	color2 = *(unsigned int *)color;
	return (color2);
}

void	paint_sky(int start, int x, t_datas *map)
{
	int y;

	y = 0;
	while (y != start && y <= map->res_y / 2)
	{
		ft_mlx_pixel_put(&map->fps, x, y, map->c_rgb);
		y++;
	}
}

void	paint_floor(int y, int x, t_datas *map)
{
	while (y < map->res_y)
	{
		ft_mlx_pixel_put(&map->fps, x, y, map->f_rgb);
		y++;
	}
}

void	print_ray(t_datas *map, int x, float ray_p, t_ray *ray)
{
	int		y;
	int		start;
	float	y_tex;
	float	step;
	int		rank;

	start = (map->res_y - ray_p) / 2;
	if (start > 0)
		paint_sky(start, x, map);
	y = start;
	y_tex = 0;
	rank = texture_number(ray->dir);
	step = (float)map->txt[rank].j / ray_p;
	while (y >= start && y < map->res_y && ray_p >= 0)
	{
		if (y >= 0)
			ft_mlx_pixel_put(&map->fps, x, y, painter(map, ray, y_tex));
		ray_p--;
		y++;
		y_tex += step;
	}
	if (y < map->res_y)
		paint_floor(y, x, map);
}
