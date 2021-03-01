/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:44:54 by gpetit            #+#    #+#             */
/*   Updated: 2021/03/01 10:44:59 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	lodev_positions2(t_datas *map)
{
	if (map->player.start == 'E')
	{
		map->player.dirx = 1;
		map->player.diry = 0;
		map->player.planx = 0;
		map->player.plany = -0.66;
	}
	else if (map->player.start == 'W')
	{
		map->player.dirx = -1;
		map->player.diry = 0;
		map->player.planx = 0;
		map->player.plany = 0.66;
	}
}

static void	lodev_positions1(t_datas *map)
{
	if (map->player.start == 'N')
	{
		map->player.dirx = 0;
		map->player.diry = -1;
		map->player.planx = -0.66;
		map->player.plany = 0;
	}
	else if (map->player.start == 'S')
	{
		map->player.dirx = 0;
		map->player.diry = 1;
		map->player.planx = 0.66;
		map->player.plany = 0;
	}
	lodev_positions2(map);
}

static void	sprites_buffer(t_datas *map)
{
	map->buff = malloc(sizeof(float) * map->res_x);
	ft_bzero(map->buff, sizeof(float) * map->res_x);
}

void		ft_initposition(t_datas *map)
{
	map->player.rfx = (float)map->player.x + 0.5;
	map->player.rfy = (float)map->player.y + 0.5;
	lodev_positions1(map);
	sprites_buffer(map);
}
