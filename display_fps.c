/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:17:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/29 13:41:42 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float SE_RAY(t_datas *map, t_triangle *X, t_triangle *Y)
{
	X->xb = floor(X->xa);
	X->xb++;
	X->yb = X->ya;
	while (map->map[(int)X->yc][(int)X->xc] != '1')
	{
		X->r = fabsf(X->xb - X->xa);
		X->xc = X->xa + X->r / cosf(X->angle) * cosf(X->angle);
		X->yc = X->ya + X->r / cosf(X->angle) * sinf(X->angle);
		X->xb++;
	}
	Y->yb = floor(Y->ya);
	Y->yb++;
	Y->xb = Y->xa;
	while (map->map[(int)Y->yc][(int)Y->xc] != '1')
	{
		Y->r = fabsf(Y->yb - Y->ya);
		Y->xc = Y->xa + Y->r / cosf(Y->angle) * cosf(Y->angle);
		Y->yc = Y->ya + Y->r / cosf(Y->angle) * sinf(Y->angle);
		Y->yb++;
	}
	if (X->r > Y->r)
		return (Y->r);
	else
		return (X->r);
}
float	compass(t_datas *map, float angle, t_triangle *X, t_triangle *Y)
{
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > 0 && sinf(angle) < 1) //SUD-EST
	{
		X->angle = map->player.angle;
		Y->angle = M_PI_2 - X->angle;
		return (SE_RAY(map, X, Y));
	}
	/*if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > 0 && sinf(angle) < 1)//SUD-OUEST
		Y->angle = map->player.angle - M_PI_2;
		X->angle = M_PI_2 - Y->angle;
		SW_RAY(X, Y);
		x--;
		y++;
	if (cosf(angle) > -1 && cosf(angle) < 0 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-OUEST
		X->angle = map->player.angle - M_PI;
		Y->angle = M_PI_2 - X->angle;
		NW_RAY(X, Y);
		x--;
		y--;
	if (cosf(angle) > 0 && cosf(angle) < 1 && sinf(angle) > -1 && sinf(angle) < 0) //NORD-EST
		Y->angle = map->player.angle - (3 * M_PI_2);
		X->angle = M_PI_2 - Y->angle;
		NE_RAY(X, Y);
		x++;
		y--;*/
	else
		return (0);
}

/*static void NW_RAY
static void	NE_RAY
static void SW_RAY


static void N_RAY
static void	S_RAY
static void W_RAY
static void E_RAY*/

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
	return(ft_shootrays(map, map->player.angle));
}
