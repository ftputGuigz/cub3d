/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:17:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/01 22:03:50 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*float NE_RAY(t_datas *map, float angle, t_triangle *X, t_triangle *Y)
{
	X->xb = ceil(X->xa);
	X->yb = X->ya;
	
	X->r = fabsf(X->xb - X->xa) / cosf(X->angle);
	X->xc = X->xb + X->r * cosf(angle);
	X->yc = X->ya + X->r * sinf(angle);
	while ((int)X->xc < map->columns && (int)X->yc >= 0 && map->map[(int)X->yc][(int)X->xc] == '0')
	{
		X->xb++;
		X->r = fabsf(X->xb - X->xa) / cosf(X->angle);
		X->xc = X->xb + X->r * cosf(angle);
		X->yc = X->ya + X->r * sinf(angle);
	}
	
	Y->yb = floor(Y->ya);
	Y->xb = Y->xa;		
	
	Y->r = fabsf(Y->yb - Y->ya) / cosf(Y->angle);
	Y->xc = Y->xa + Y->r * cosf(angle);
	Y->yc = Y->yb + Y->r * sinf(angle);
	while ((int)X->xc < map->columns && (int)X->yc >= 0 && map->map[(int)Y->yc][(int)Y->xc] == '0')
	{
		Y->yb--;
		Y->r = fabsf(Y->yb - Y->ya) / cosf(Y->angle);
		Y->xc = Y->xa + Y->r * cosf(angle);
		Y->yc = Y->yb + Y->r * sinf(angle);
	}
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}*/

float NE_RAY(t_datas *map, float angle, t_triangle *X, t_triangle *Y)
{
	X->xb = ceil(X->xa);
	X->yb = X->ya;
	
	X->xc = X->xb;
	X->yc = X->yb - (tan(X->angle) * (X->xb - X->xa));
	while ((int)X->xc < map->columns && (int)X->yc >= 0 && map->map[(int)X->yc][(int)X->xc] == '0')
	{
		X->xb++;
		X->xc = X->xb;
		X->yc = X->yb - (tanf(X->angle) * (X->xb - X->xa));
	}
	X->r = (X->xb - X->xa) / cosf(X->angle);
	
	Y->yb = floor(Y->ya);
	Y->xb = Y->xa;		
	
	Y->yc = Y->yb;
	Y->xc = Y->xb + tanf(Y->angle) * (Y->ya - Y->yb);
	while ((int)X->xc < map->columns && (int)X->yc >= 0 && map->map[(int)Y->yc][(int)Y->xc] == '0')
	{
		Y->yb--;
		Y->yc = Y->yb;
		Y->xc = Y->xb + tanf(Y->angle) * (Y->ya - Y->yb);
	}
	Y->r = (Y->ya - Y->yb) / cosf(Y->angle);
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}

float NW_RAY(t_datas *map, float angle, t_triangle *X, t_triangle *Y)
{
	X->xb = floor(X->xa);
	X->yb = X->ya;
	
	X->r = fabsf(X->xb - X->xa);
	X->xc = X->xb;
	X->yc = X->ya + X->r / cosf(X->angle) * sinf(angle);
	while ((int)X->xc >= 0 && (int)X->yc >= 0  && map->map[(int)X->yc][(int)X->xc] == '0')
	{
		X->xb--;
		X->r = fabsf(X->xb - X->xa);
		X->xc = X->xb;
		X->yc = X->ya + X->r / cosf(X->angle) * sinf(angle);
	}
	
	Y->yb = floor(Y->ya);
	Y->xb = Y->xa;		
	
	Y->r = fabsf(Y->yb - Y->ya);
	Y->xc = Y->xa + Y->r / cosf(Y->angle) * cosf(angle);
	Y->yc = Y->yb;
	while ((int)Y->xc >= 0 && (int)Y->yc >= 0 && map->map[(int)Y->yc][(int)Y->xc] == '0')
	{
		Y->yb--;
		Y->r = fabsf(Y->yb - Y->ya);
		Y->xc = Y->xa + Y->r / cosf(Y->angle) * cosf(angle);
		Y->yc = Y->yb;
	}
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}

float SW_RAY(t_datas *map, float angle, t_triangle *X, t_triangle *Y)
{
	X->xb = floor(X->xa);
	X->yb = X->ya;
	
	X->r = fabsf(X->xb - X->xa);
	X->xc = X->xb;
	X->yc = X->ya + X->r / cosf(X->angle) * sinf(angle);
	while ((int)X->xc >= 0 && (int)X->yc < map->lines && map->map[(int)X->yc][(int)X->xc] == '0')
	{
		X->xb--;
		X->r = fabsf(X->xb - X->xa);
		X->xc = X->xb;
		X->yc = X->ya + X->r / cosf(X->angle) * sinf(angle);
	}
	
	Y->yb = ceil(Y->ya);
	Y->xb = Y->xa;		
	
	Y->r = fabsf(Y->yb - Y->ya);
	Y->xc = Y->xa + Y->r / cosf(Y->angle) * cosf(angle);
	Y->yc = Y->yb;
	while ((int)Y->xc >= 0 && (int)Y->yc < map->lines && map->map[(int)Y->yc][(int)Y->xc] == '0')
	{
		Y->yb++;
		Y->r = fabsf(Y->yb - Y->ya);
		Y->xc = Y->xa + Y->r / cosf(Y->angle) * cosf(angle);
		Y->yc = Y->yb;
	}
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}

float SE_RAY(t_datas *map, float angle, t_triangle *X, t_triangle *Y)
{
	X->xb = ceil(X->xa);
	X->yb = X->ya;
	
	X->r = fabsf(X->xb - X->xa);
	X->xc = X->xb;
	X->yc = X->ya + X->r / cosf(X->angle) * sinf(angle);
	while ((int)X->xc < map->columns && (int)X->yc < map->lines && map->map[(int)X->yc][(int)X->xc] == '0')
	{
		X->xb++;
		X->r = fabsf(X->xb - X->xa);
		X->xc = X->xb;
		X->yc = X->ya + X->r / cosf(X->angle) * sinf(angle);
	}
	
	Y->yb = ceil(Y->ya);
	Y->xb = Y->xa;		
	
	Y->r = fabsf(Y->yb - Y->ya);
	Y->xc = Y->xa + Y->r / cosf(Y->angle) * cosf(angle);
	Y->yc = Y->yb;
	while ((int)Y->xc < map->columns && (int)Y->yc < map->lines && map->map[(int)Y->yc][(int)Y->xc] == '0')
	{
		Y->yb++;
		Y->r = fabsf(Y->yb - Y->ya);
		Y->xc = Y->xa + Y->r / cosf(Y->angle) * cosf(angle);
		Y->yc = Y->yb;
	}
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}

float	compass(t_datas *map, float angle, t_triangle *X, t_triangle *Y)
{
	if (cosf(angle) > 0 && cosf(angle) <= 1 && sinf(angle) > 0 && sinf(angle) < 1) //SUD-EST
	{
		X->angle = angle;
		Y->angle = M_PI_2 - X->angle;
		return (SE_RAY(map, angle, X, Y));
	}
	if (cosf(angle) > -1 && cosf(angle) <= 0 && sinf(angle) > 0 && sinf(angle) <= 1)//SUD-OUEST
	{
		X->angle = M_PI - angle;
		Y->angle = M_PI_2 - X->angle;
		return(SW_RAY(map, angle, X, Y));
	}
	if (cosf(angle) >= -1 && cosf(angle) < 0 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-OUEST
	{
		X->angle = angle - M_PI;
		Y->angle = M_PI_2 - X->angle;
		return(NW_RAY(map, angle, X, Y));
	}
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) >= -1 && sinf(angle) < 0) //NORD-EST
	{
		Y->angle = angle - (3 * M_PI_2);
		X->angle = M_PI_2 - Y->angle;
		return(NE_RAY(map, angle, X, Y));
	}
	else
		return (0);
}


float	ft_shootrays(t_datas *map, float ray_angle)
{
	t_triangle X;
	t_triangle Y;
	float ray;

	X.xa = map->player.rfx;
	X.ya = map->player.rfy;
	Y.xa = map->player.rfx;
	Y.ya = map->player.rfy;
	ray = compass(map, ray_angle, &X, &Y);
	return (ray);
}

float	ft_fps(t_datas *map)
{
	/*float FOV;
	float raysize;

	FOV = map->player.angle - 33;
	map->fps.img = mlx_new_image(map->mlx.ptr, map->res_x, map->res_y);
	map->fps.addr = mlx_get_data_addr(map->fps.img, &map->fps.bits_per_pixel, &map->fps.line_length, &map->fps.endian);
	while (FOV != map->player.angle + 33);
	{
		raysize = ft_shootraysi(map, FOV);
		FOV++; //POUR L'INSTANT 66 RAYONS DE SHOOT. PLUS TARD AUTANT QUE LA RESOLUTION LEXIGE
	}
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.wdw, map->fps.img, 0, 0);
	mlx_destroy_image(map->mlx.ptr, map->fps.img);*/
	float result;
	result = ft_shootrays(map, map->player.angle);
	return(result);
}
