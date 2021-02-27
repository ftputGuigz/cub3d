/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c       		                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:46:32 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/22 18:58:39 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_kill_textures(t_datas *map)
{
	if (map->NO_path)
		free(map->NO_path);
	if (map->SO_path)
		free(map->SO_path);
	if (map->EA_path)
		free(map->EA_path);
	if (map->WE_path)
		free(map->WE_path);
	if (map->spr_path)
		free(map->spr_path);
	if (map->buff)
		free(map->buff);
	if (map->spr)
		free(map->spr);
	if (map->spr_ordr)
		free(map->spr_ordr);
}

void	ft_kill_map(t_datas *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	if (map->map)
		free(map->map);
}

void	ft_kill_mlx(t_datas *map)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (map->txt[i].img)
			mlx_destroy_image(map->mlx.ptr, map->txt[i].img);
		i++;
	}
	if (map->fps.img)
		mlx_destroy_image(map->mlx.ptr, map->fps.img);
	if (map->minimap.img)
		mlx_destroy_image(map->mlx.ptr, map->minimap.img);
	if (map->mlx.wdw)
		mlx_destroy_window(map->mlx.ptr, map->mlx.wdw);
	if (map->mlx.wdw2)
		mlx_destroy_window(map->mlx.ptr, map->mlx.wdw2);
	exit (0);
}

int	ft_exit(t_datas *map)
{
	ft_kill_textures(map);
	ft_kill_map(map);
	ft_kill_mlx(map);
	return (0);
}

void	init_mlx(t_datas *map)
{
	int i;

	i = 0;
	while (i < 5)
		map->txt[i++].img = NULL;
	map->mlx.wdw = NULL;
	map->mlx.wdw2 = NULL;
	map->minimap.img = NULL;
	map->fps.img = NULL;
}

void	initialize_struct(t_datas *map)
{
	map->bmp = 0;
	map->res_x = 0;
	map->res_y = 0;
	map->NO_path = NULL;
	map->SO_path = NULL;
	map->EA_path = NULL;
	map->WE_path = NULL;
	map->spr_path = NULL;
	map->f_rgb = 0;
	map->c_rgb = 0;
	map->map = NULL;
	map->columns = 0;
	map->lines = 0;
	map->buff = NULL;
	map->spr = NULL;
	map->sprites_nbr = 0;
	map->spr_ordr = NULL;
	init_mlx(map);
}