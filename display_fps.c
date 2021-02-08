/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:17:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/07 14:15:25 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void NE_RAY(t_datas *map, t_ray *ray)
{	
	ray->trix.xb = ceil(ray->trix.xa);
	ray->trix.yb = ray->trix.ya;
	ray->trix.xc = ray->trix.xb;
	ray->trix.yc = ray->trix.yb - tan(ray->trix.angle) * fabsf(ray->trix.xb - ray->trix.xa);
	while ((int)(ray->trix.xc + 0.000001) < map->columns && (int)(ray->trix.yc - 0.000001) > 0 && map->map[(int)(ray->trix.yc - 0.000001)][(int)(ray->trix.xc + 0.000001)] == '0')
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
	while ((int)(ray->triy.xc + 0.000001) < map->columns && (int)(ray->triy.yc - 0.000001) > 0 && map->map[(int)(ray->triy.yc - 0.000001)][(int)(ray->triy.xc + 0.000001)] == '0')
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
	while ((int)(ray->trix.xc - 0.000001) > 0 && (int)(ray->trix.yc - 0.000001) > 0 && map->map[(int)(ray->trix.yc - 0.000001)][(int)(ray->trix.xc - 0.000001)] == '0')
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
	while ((int)(ray->triy.xc - 0.000001) > 0 && (int)(ray->triy.yc - 0.000001) > 0 && map->map[(int)(ray->triy.yc - 0.000001)][(int)(ray->triy.xc - 0.000001)] == '0')
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
	while ((int)(ray->trix.xc - 0.000001) > 0 && (int)(ray->trix.yc + 0.000001) < map->lines && map->map[(int)(ray->trix.yc + 0.000001)][(int)(ray->trix.xc - 0.000001)] == '0')
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
	while ((int)(ray->triy.xc - 0.000001) > 0 && (int)(ray->triy.yc + 0.000001) < map->lines && map->map[(int)(ray->triy.yc + 0.000001)][(int)(ray->triy.xc - 0.000001)] == '0')
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
	while ((int)(ray->trix.xc + 0.000001) < map->columns && (int)(ray->trix.yc + 0.000001) < map->lines && map->map[(int)(ray->trix.yc + 0.000001)][(int)(ray->trix.xc + 0.000001)] == '0')
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
	while ((int)(ray->triy.xc + 0.000001) < map->columns && (int)(ray->triy.yc + 0.000001) < map->lines && map->map[(int)(ray->triy.yc + 0.000001)][(int)(ray->triy.xc + 0.000001)] == '0')
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
	while (map->map[(int)(dist - 0.000001)][(int)map->player.rfx] == '0')
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
	while (map->map[(int)(dist + 0.000001)][(int)map->player.rfx] == '0')
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
	while (map->map[(int)map->player.rfy][(int)(dist + 0.000001)] == '0')
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
	while (map->map[(int)map->player.rfy][(int)(dist - 0.000001)] == '0')
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
	if (map->map[(int)(ray->yc - 0.000001)][(int)ray->xc] != '0' && map->map[(int)ray->yc][(int)(ray->xc + 0.000001)] == '0')
		ray->dir = 'S';
	else if (map->map[(int)ray->yc][(int)(ray->xc + 0.000001)] != '0' && map->map[(int)(ray->yc - 0.000001)][(int)ray->xc] == '0')
		ray->dir = 'W';
	else if (map->map[(int)(ray->yc + 0.000001)][(int)ray->xc] != '0' && map->map[(int)ray->yc][(int)(ray->xc - 0.000001)] == '0')
		ray->dir = 'N';
	else if (map->map[(int)ray->yc][(int)(ray->xc - 0.000001)] != '0' && map->map[(int)(ray->yc + 0.000001)][(int)ray->xc] == '0')
		ray->dir = 'E';
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

void ft_shootrays(t_datas *map, float ray_angle, t_ray *ray)
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
}

char *texture_path(char orientation)
{
	if (orientation == 'N')
		return ("./texturesMinecraft/grass.xpm");
	if (orientation == 'S')
		return ("./texturesMinecraft/grass.xpm");
	if (orientation == 'W')
		return ("./texturesMinecraft/grass.xpm");
	if (orientation == 'E')
		return ("./texturesMinecraft/grass.xpm");
	else
		return ("NULL");
}

char	*painter(t_datas *map, t_ray *ray, int y)
{
	t_img	texture;
	float reste;
	int i;
	int j;
	int x_tex;
	int y_tex;
	char *color;

	texture.img = mlx_xpm_file_to_image(map->mlx.ptr, texture_path(ray->dir), &i, &j);
	if (ray->dir == 'N' || ray->dir == 'S')
	{
		x_tex = modff(ray->xc, &reste) * i;
		y_tex = y * j / map->res_y;
	}
	if (ray->dir == 'W' || ray->dir == 'E')
	{	
		x_tex = modff(ray->yc, &reste) * i;
		y_tex = y * j / map->res_y;
	}
	texture.addr = mlx_get_data_addr(texture.img, &texture.bits_per_pixel, &texture.line_length, &texture.endian);
	color = texture.addr + texture.line_length * y_tex + texture.bits_per_pixel * x_tex;
	mlx_destroy_image(map->mlx.ptr, texture.img);
	return (color);
}

void print_ray(t_datas *map, int x, t_ray *ray)
{
	float ray_p;
	float k;
	int y;
	
	k = map->res_y;
	y = map->res_y / 2;
	ray_p = (k * 1 / ray->r) / 2; //PROPORTIONNELLE
	while (ray_p >= 0 && y >= 0)
	{
		printf("pixel = %s\n", painter(map, ray, y));
		ft_mlx_pixel_put(&map->fps, x, y, 0xFF0000);
		ray_p--;
		y--;
	}
	y = map->res_y / 2;
	ray_p = (k * 1 / ray->r) / 2;
	while (ray_p <= k * 1 / ray->r && y < map->res_y)
	{
		printf("pixel = %s\n", painter(map, ray, y));
		ft_mlx_pixel_put(&map->fps, x, y, 0xFF0000);
		ray_p++;	
		y++;	
	}
}

int	ft_fps(t_datas *map)
{
	t_ray ray;
	float FOV;
	//float increment;
	int x = 0;

	//increment = 1.15192 / (float)map->res_x;
	FOV = map->player.angle - 0.575959;
	map->fps.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y);
	map->fps.addr = mlx_get_data_addr(map->fps.img, &map->fps.bits_per_pixel, &map->fps.line_length, &map->fps.endian);
	while (x < map->res_x && FOV <= (map->player.angle + 0.575959))
	{
		ft_shootrays(map, FOV, &ray);
		print_ray(map, x, &ray);
	/* 	if (x == map->res_x / 2)
		{	printf("ray.xc = %f\nray.yc =%f\n", ray.xc, ray.yc);
			printf("map->map[(int)(ray->yc)][(int)ray->xc] = %c\n", map->map[(int)(ray.yc)][(int)ray.xc]);
			printf("SOUTH WALL(yc - 0.1) = %c\n", map->map[(int)(ray.yc - 0.000001)][(int)ray.xc]);
			printf("NORTH WALL(yc + 0.1) = %c\n", map->map[(int)(ray.yc + 0.000001)][(int)ray.xc]);
			printf("EAST WALL(xc - 0.1) = %c\n", map->map[(int)(ray.yc)][(int)(ray.xc - 0.000001)]);
			printf("WEST WALL(xc + 0.1) = %c\n", map->map[(int)(ray.yc)][(int)(ray.xc + 0.000001)]);
			printf("ray.dir = %c\n", ray.dir);
		} */
		x++;
		FOV = map->player.angle + atanf((x - map->res_x / 2) / ((map->res_x / 2) / tanf(1.15192 / 2)));
		//FOV += increment;
	}
	ft_minimap(map);
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw2, map->fps.img, 0, 0);
	mlx_destroy_image(map->mlx.ptr, map->fps.img);
	return(0);
}
