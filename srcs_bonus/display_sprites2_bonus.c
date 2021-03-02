/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:09:32 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/28 20:10:48 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	calculate_distance(float **spr_dist, t_datas *map)
{
	int i;

	i = 0;
	while (i < map->sprites_nbr)
	{
		(*spr_dist)[i] = powf(map->player.rfx - (float)(map->spr[i].x + 0.5), 2)
		+ powf(map->player.rfy - (float)(map->spr[i].y + 0.5), 2);
		map->spr_ordr[i] = i;
		i++;
	}
}

static void	sort_sprites2(float **spr_dist, t_datas *map, int i, int j)
{
	float	tmp;
	int		tmp2;

	tmp = (*spr_dist)[j];
	(*spr_dist)[j] = (*spr_dist)[i];
	(*spr_dist)[i] = tmp;
	tmp2 = (map->spr_ordr)[j];
	(map->spr_ordr)[j] = (map->spr_ordr)[i];
	(map->spr_ordr)[i] = tmp2;
}

static void	sort_sprites(float **spr_dist, t_datas *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->sprites_nbr)
	{
		j = i + 1;
		while (j < map->sprites_nbr)
		{
			if ((*spr_dist)[i] < (*spr_dist)[j])
				sort_sprites2(spr_dist, map, i, j);
			j++;
		}
		i++;
	}
}

void		get_order(t_datas *map)
{
	float *spr_dist;

	spr_dist = malloc(sizeof(float) * map->sprites_nbr);
	if (!spr_dist)
	{
		write(1, "Malloc related issue.\n", 22);
		ft_exit(map);
	}
	calculate_distance(&spr_dist, map);
	sort_sprites(&spr_dist, map);
	free(spr_dist);
}
