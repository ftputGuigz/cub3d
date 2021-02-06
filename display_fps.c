/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:17:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/04 12:02:48 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float NE_RAY(t_datas *map, t_triangle *X, t_triangle *Y, float angle)
{

/* 	//LA PARTIE QUI SUIT EST POUR DEBOGAGE
	float r = 0;
	static int tag = 0;
	float x;
	float y;

	x = map->player.rfx;
	y = map->player.rfy;
	while ((int)x < map->columns && (int)y > 0 && map->map[(int)y][(int)x] == '0')
	{
		x = map->player.rfx + r * cosf(map->player.angle);
		y = map->player.rfy + r * sinf(map->player.angle);
		r += 0.000001;
	}
	//return (r);
 	//FIN DE LA PARTIE DEBOGAGE */
	
	X->xb = ceil(X->xa);
	X->yb = X->ya;
	X->xc = X->xb;
	X->yc = X->yb - tan(X->angle) * fabsf(X->xb - X->xa);
	while ((int)(X->xc + 0.000001) < map->columns && (int)(X->yc - 0.000001) > 0 && map->map[(int)(X->yc - 0.000001)][(int)(X->xc + 0.000001)] == '0')
	{
		X->xb++;
		X->xc = X->xb;
		//printf("X->xc = %f\n", X->xc);
		X->yc = X->yb - tanf(X->angle) * fabsf(X->xb - X->xa);
	}
	X->r = sqrtf(powf(fabsf(X->xb - X->xa), 2) + powf(fabsf(X->yb - X->yc), 2));

	Y->yb = floor(Y->ya);
	Y->xb = Y->xa;		
	Y->yc = Y->yb;
	Y->xc = Y->xb + tanf(Y->angle) * fabsf(Y->ya - Y->yb);
	while ((int)(Y->xc + 0.000001) < map->columns && (int)(Y->yc - 0.000001) > 0 && map->map[(int)(Y->yc - 0.000001)][(int)(Y->xc + 0.000001)] == '0')
	{
		//printf("char = %c\n", map->map[(int)Y->yc][(int)Y->xc]);
		Y->yb--;
		Y->yc = Y->yb;
		//printf("Y->yc = %f\n", Y->yc);
		Y->xc = Y->xb + tanf(Y->angle) * fabsf(Y->ya - Y->yb);
	}
	Y->r = sqrtf(powf(fabsf(Y->yb - Y->ya), 2) + powf(fabsf(Y->xb - Y->xc), 2));
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}

float NW_RAY(t_datas *map, t_triangle *X, t_triangle *Y, float angle)
{
/* 	// LA PARTIE QUI SUIT EST POUR DEBOGAGE
	float r = 0;
	float x;
	float y;
	static int tag = 0;

	x = map->player.rfx;
	y = map->player.rfy;
	while ((int)x > 0 && (int)y > 0 && map->map[(int)y][(int)x] == '0')
	{
		x = map->player.rfx + r * cosf(map->player.angle);
		y = map->player.rfy + r * sinf(map->player.angle);
		r += 0.000001;
	}
	//return (r);
 	//FIN DE LA PARTIE DEBOGAGE */

	X->xb = floor(X->xa);
	X->yb = X->ya;
	
	X->xc = X->xb;
	X->yc = X->yb - tanf(X->angle) * fabsf(X->xb - X->xa);
	while ((int)(X->xc - 0.000001) > 0 && (int)(X->yc - 0.000001) > 0 && map->map[(int)(X->yc - 0.000001)][(int)(X->xc - 0.000001)] == '0')
	{
		X->xb--;
		X->xc = X->xb;
		X->yc = X->yb - tanf(X->angle) * fabsf(X->xa - X->xb);
	}
	X->r = sqrtf(powf(fabsf(X->xb - X->xa), 2) + powf(fabsf(X->yb - X->yc), 2));

	Y->yb = floor(Y->ya);
	Y->xb = Y->xa;

	Y->yc = Y->yb;
	Y->xc = Y->xb - tanf(Y->angle) * fabsf(Y->ya - Y->yb);
	while ((int)(Y->xc - 0.000001) > 0 && (int)(Y->yc - 0.000001) > 0 && map->map[(int)(Y->yc - 0.000001)][(int)(Y->xc - 0.000001)] == '0')
	{
		Y->yb--;
		Y->yc = Y->yb;
		Y->xc = Y->xb - tanf(Y->angle) * fabsf(Y->ya - Y->yb);
	}
	Y->r = sqrtf(powf(fabsf(Y->yb - Y->ya), 2) + powf(fabsf(Y->xb - Y->xc), 2));
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}

float SW_RAY(t_datas *map, t_triangle *X, t_triangle *Y, float angle)
{
/* 	//LA PARTIE QUI SUIT EST POUR DEBOGAGE
	float r = 0;
	float x;
	float y;

	x = map->player.rfx;
	y = map->player.rfy;
	while ((int)x > 0 && (int)y < map->lines && map->map[(int)y][(int)x] == '0')
	{
		x = map->player.rfx + r * cosf(map->player.angle);
		y = map->player.rfy + r * sinf(map->player.angle);
		r += 0.000001;
	}
	//return (r);
 	//FIN DE LA PARTIE DEBOGAGE */
	

	X->xb = floor(X->xa);
	X->yb = X->ya;
	
	X->xc = X->xb;
	X->yc = X->yb + tanf(X->angle) * fabsf(X->xb - X->xa);
	while ((int)(X->xc - 0.000001) > 0 && (int)(X->yc + 0.000001) < map->lines && map->map[(int)(X->yc + 0.000001)][(int)(X->xc - 0.000001)] == '0')
	{
		X->xb--;
		X->xc = X->xb;
		X->yc = X->yb + tanf(X->angle) * fabsf(X->xb - X->xa);
	}
	X->r = sqrtf(powf(fabsf(X->xb - X->xa), 2) + powf(fabsf(X->yb - X->yc), 2));

	Y->yb = ceil(Y->ya);
	Y->xb = Y->xa;		
	
	Y->yc = Y->yb;
	Y->xc = Y->xb - tanf(Y->angle) * fabsf(Y->ya - Y->yb);
	while ((int)(Y->xc - 0.000001) > 0 && (int)(Y->yc + 0.000001) < map->lines && map->map[(int)(Y->yc + 0.000001)][(int)(Y->xc - 0.000001)] == '0')
	{
		Y->yb++;
		Y->yc = Y->yb;
		Y->xc = Y->xb - tanf(Y->angle) * fabsf(Y->ya - Y->yb);
	}
	Y->r = sqrtf(powf(fabsf(Y->yb - Y->ya), 2) + powf(fabsf(Y->xb - Y->xc), 2));
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}

float SE_RAY(t_datas *map, t_triangle *X, t_triangle *Y, float angle)
{
/* 	//LA PARTIE QUI SUIT EST POUR DEBOGAGE
	float r = 0;
	float x;
	float y;

	x = map->player.rfx;
	y = map->player.rfy;
	while ((int)x < map->columns && (int)y < map->lines && map->map[(int)y][(int)x] == '0')
	{
		x = map->player.rfx + r * cosf(map->player.angle);
		y = map->player.rfy + r * sinf(map->player.angle);
		r += 0.000001;
	}
	//return (r);
 	//FIN DE LA PARTIE DEBOGAGE */
	
	X->xb = ceil(X->xa);
	X->yb = X->ya;
	
	X->xc = X->xb;
	X->yc = X->yb + tanf(X->angle) * fabsf(X->xb - X->xa);
	while ((int)(X->xc + 0.000001) < map->columns && (int)(X->yc + 0.000001) < map->lines && map->map[(int)(X->yc + 0.000001)][(int)(X->xc + 0.000001)] == '0')
	{
		X->xb++;
		X->xc = X->xb;
		X->yc = X->yb + tanf(X->angle) * fabsf(X->xb - X->xa);
	}
	X->r = sqrtf(powf(fabsf(X->xb - X->xa), 2) + powf(fabsf(X->yb - X->yc), 2));
	
	Y->yb = ceil(Y->ya);
	Y->xb = Y->xa;		
	
	Y->yc = Y->yb;
	Y->xc = Y->xb + tanf(Y->angle) * fabsf(Y->ya - Y->yb);
	while ((int)(Y->xc + 0.000001) < map->columns && (int)(Y->yc + 0.000001) < map->lines && map->map[(int)(Y->yc + 0.000001)][(int)(Y->xc + 0.000001)] == '0')
	{
		Y->yb++;
		Y->yc = Y->yb;
		Y->xc = Y->xb + tanf(Y->angle) * fabsf(Y->ya - Y->yb);
	}
	Y->r = sqrtf(powf(fabsf(Y->yb - Y->ya), 2) + powf(fabsf(Y->xb - Y->xc), 2));
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}

static float NORTH(t_datas *map)
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
	return (count + reste);
}

static float SOUTH(t_datas *map)
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
	return (count + reste);
}

static float EAST(t_datas *map)
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
	return (count + reste);
}
static float WEST(t_datas *map)
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
	return (count + reste);
}

static float straight_compass(t_datas *map, float angle)
{
	if (sinf(angle) == -1)
		return (NORTH(map));
	if (sinf(angle) == 1)
		return (SOUTH(map));
	if (cosf(angle) == -1)
		return (WEST(map));
	if (cosf(angle) == 1)
		return (EAST(map));
	return (0);
}

float	compass(t_datas *map, float angle, t_triangle *X, t_triangle *Y)
{
	if (cosf(angle) == 1 || cosf(angle) == -1 || sinf(angle) == 1 || sinf(angle) == -1)
		return (straight_compass(map, angle));
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > 0 && sinf(angle) < 1) //SUD-EST
	{
		X->angle = angle;
		Y->angle = M_PI_2 - X->angle;
		return (SE_RAY(map, X, Y , angle));
	}
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > 0 && sinf(angle) < 1)//SUD-OUEST
	{
		X->angle = M_PI - angle;
		Y->angle = M_PI_2 - X->angle;
		return(SW_RAY(map, X, Y, angle));
	}
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-OUEST
	{
		X->angle = angle - M_PI;
		Y->angle = M_PI_2 - X->angle;
		return(NW_RAY(map, X, Y, angle));
	}
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-EST
	{
		Y->angle = angle - (3 * M_PI_2);
		X->angle = M_PI_2 - Y->angle;
		return(NE_RAY(map, X, Y, angle));
	}
	return (0);
}

float	ft_shootrays(t_datas *map, float ray_angle)
{
	t_triangle X;
	t_triangle Y;
	float ray;
	float fisheye_angle;

	X.xa = map->player.rfx;
	X.ya = map->player.rfy;
	Y.xa = map->player.rfx;
	Y.ya = map->player.rfy;
	if (ray_angle > map->player.angle)
		fisheye_angle = ray_angle - map->player.angle;
	else
		fisheye_angle = map->player.angle - ray_angle;
	ray = compass(map, ray_angle, &X, &Y);
	ray *= cosf(fisheye_angle);
	//printf("X.xc = %f\nX.yc = %f\n---------------\n", X.xc, X.yc);
	//printf("Y.xc = %f\nY.yc = %f\n---------------\n", Y.xc, Y.yc);
	//printf("Xr = %f\nYr = %f\n---------------\n", X.r, Y.r);
	return (ray);
}

void print_ray(t_datas *map, int x, float raysize, float FOV)
{
	float ray;
	float k;
	int y;

	int N;
	int S;
	int E;
	int W;
	
	k = map->res_y;
	y = map->res_y / 2;
	ray = (k * 1 / raysize) / 2; //PROPORTIONNELLE
	while (ray >= 0 && y >= 0)
	{
		ft_mlx_pixel_put(&map->fps, x, y, 0xFF0000);
		ray--;
		y--;
	} 
	y = map->res_y / 2;
	ray = (k * 1 / raysize) / 2;
	while (ray <= k * 1 / raysize && y < map->res_y)
	{
		ft_mlx_pixel_put(&map->fps, x, y, 0xFF0000);
		ray++;	
		y++;	
	}
}

int	ft_fps(t_datas *map)
{
	float FOV;
	//float increment;
	float raysize;
	int x = 0;

	//increment = 1.15192 / (float)map->res_x;
	FOV = map->player.angle - 0.575959;
	map->fps.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y);
	map->fps.addr = mlx_get_data_addr(map->fps.img, &map->fps.bits_per_pixel, &map->fps.line_length, &map->fps.endian);
	while (x < map->res_x && FOV <= (map->player.angle + 0.575959))
	{
		raysize = ft_shootrays(map, FOV);
		print_ray(map, x, raysize, FOV);
		x++;
		FOV = map->player.angle + atanf((x - map->res_x / 2) / ((map->res_x / 2) / tanf(1.15192 / 2)));
		//FOV += increment;
	}
	ft_minimap(map);
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw2, map->fps.img, 0, 0);
	mlx_destroy_image(map->mlx.ptr, map->fps.img);
	return(0);
}
