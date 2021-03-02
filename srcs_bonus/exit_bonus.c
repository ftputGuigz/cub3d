/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:15:02 by gpetit            #+#    #+#             */
/*   Updated: 2021/03/01 12:26:55 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_kill_textures(t_datas *map)
{
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->we_path)
		free(map->we_path);
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
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

#if __linux__

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
	if (map->mlx.wdw2)
		mlx_destroy_window(map->mlx.ptr, map->mlx.wdw2);
	mlx_destroy_display(map->mlx.ptr);
	free(map->mlx.ptr);
	exit(0);
}

#elif __APPLE__

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
	if (map->mlx.wdw2)
		mlx_destroy_window(map->mlx.ptr, map->mlx.wdw2);
	free(map->mlx.ptr);
	exit(0);
}

#endif

int		ft_exit(t_datas *map)
{
	ft_kill_textures(map);
	ft_kill_map(map);
	ft_kill_mlx(map);
	return (0);
}
