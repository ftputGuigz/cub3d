/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:17:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/13 10:15:57 by gpetit           ###   ########.fr       */
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

static float NORTH(t_datas *map, t_ray *ray)
{
	float reste;
	float dist;
	float count = 0;

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

static float SOUTH(t_datas *map, t_ray *ray)
{
	float reste;
	float dist;
	float count = 0;

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

static float EAST(t_datas *map, t_ray *ray)
{
	float reste;
	float dist;
	float count = 0;

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
static float WEST(t_datas *map, t_ray *ray)
{
	float reste;
	float dist;
	float count = 0;

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

static void straight_compass(t_datas *map, t_ray *ray, float angle)
{
	if (sinf(angle) == -1)
		ray->r = (NORTH(map, ray));
	if (sinf(angle) == 1)
		ray->r = (SOUTH(map, ray));
	if (cosf(angle) == -1)
		ray->r = (WEST(map, ray));
	if (cosf(angle) == 1)
		ray->r = (EAST(map, ray));
}

void set_direction(t_datas *map, t_ray *ray)
{
	if (map->map[(int)(ray->yc - 0.000001)][(int)ray->xc] == '1' && map->map[(int)ray->yc][(int)(ray->xc + 0.000001)] != '1')
		ray->dir = 'N';
	else if (map->map[(int)ray->yc][(int)(ray->xc + 0.000001)] == '1' && map->map[(int)(ray->yc - 0.000001)][(int)ray->xc] != '1')
		ray->dir = 'E';
	else if (map->map[(int)(ray->yc + 0.000001)][(int)ray->xc] == '1' && map->map[(int)ray->yc][(int)(ray->xc - 0.000001)] != '1')
		ray->dir = 'S';
	else if (map->map[(int)ray->yc][(int)(ray->xc - 0.000001)] == '1' && map->map[(int)(ray->yc + 0.000001)][(int)ray->xc] != '1')
		ray->dir = 'W';
}

void compass(t_datas *map, float angle, t_ray *ray)
{
	if (cosf(angle) == 1 || cosf(angle) == -1 || sinf(angle) == 1 || sinf(angle) == -1)
		straight_compass(map, ray, angle);
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > 0 && sinf(angle) < 1) //SUD-EST
	{
		ray->trix.angle = angle;
		ray->triy.angle = M_PI_2 - ray->trix.angle;
		SE_RAY(map, ray);
	}
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > 0 && sinf(angle) < 1)//SUD-OUEST
	{
		ray->trix.angle = M_PI - angle;
		ray->triy.angle = M_PI_2 - ray->trix.angle;	
		SW_RAY(map, ray);
	}
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-OUEST
	{
		ray->trix.angle = angle - M_PI;
		ray->triy.angle = M_PI_2 - ray->trix.angle;
		NW_RAY(map, ray);
	}
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-EST
	{
		ray->triy.angle = angle - (3 * M_PI_2);
		ray->trix.angle = M_PI_2 - ray->triy.angle;
		NE_RAY(map, ray);
	}
	set_direction(map, ray);
}

void ft_shootrays(t_datas *map, float ray_angle, t_ray *ray, int x)
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
	map->buff[x] = ray->r; //REMPLISSAGE DES DISTANCES EUCLIDIENNES BUFFER
}

int	texture_number(char orientation)
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

int	painter(t_datas *map, t_ray *ray, float y_tex)
{
	int rank;
	float reste;
	float x_tex;
	char *color;
	int color2;
	
	rank = texture_number(ray->dir);
	if (ray->dir == 'N')
		x_tex = modff(ray->xc, &reste) * map->txt[rank].i;
	else if (ray->dir == 'S')
		x_tex = (1 - modff(ray->yc, &reste)) * map->txt[rank].i;
	else if (ray->dir == 'W')
		x_tex = (1 - modff(ray->yc, &reste)) * map->txt[rank].i;
	else 
		x_tex = modff(ray->xc, &reste) * map->txt[rank].i;
	color = map->txt[rank].addr + ((int)y_tex * map->txt[rank].line_length + (int)x_tex * (map->txt[rank].bits_per_pixel / 8));
	color2 = *(unsigned int *)color;
	return (color2);
}

void print_ray(t_datas *map, int x, t_ray *ray)
{
	float ray_p;
	float k;
	int y;
	int start;
	float y_tex;
	float step;
	int rank;
	
	k = map->res_y;
	ray_p = (k * 1 / ray->r);
	start = (map->res_y - ray_p) / 2;
	if (start > 0)
	{
		y = 0;
		while (y != start && y <= map->res_y / 2)
		{	
			ft_mlx_pixel_put(&map->fps, x, y, map->c_rgb);
			y++;
		}
	}
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
	{
		while (y < map->res_y)
		{	
			ft_mlx_pixel_put(&map->fps, x, y, map->f_rgb);
			y++;
		}
	}
}

int	ft_fps(t_datas *map)
{
	t_ray ray;
	float FOV;
	int x;

	x = 0;
	FOV = map->player.angle - 0.575959;
	map->fps.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y);
	map->fps.addr = mlx_get_data_addr(map->fps.img, &map->fps.bits_per_pixel, &map->fps.line_length, &map->fps.endian);
	while (x < map->res_x && FOV <= (map->player.angle + 0.575959))
	{
		ft_shootrays(map, FOV, &ray, x);
		print_ray(map, x, &ray);
		x++;
		FOV = map->player.angle + atanf((x - map->res_x / 2) / ((map->res_x / 2) / tanf(1.15192 / 2)));
	}
	ft_sprites(map);
	if (map->bmp) //EXIT PROPREMENT
		make_bmp(map);
	ft_minimap(map);
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw2, map->fps.img, 0, 0);
	mlx_destroy_image(map->mlx.ptr, map->fps.img);
	return(0);
}
