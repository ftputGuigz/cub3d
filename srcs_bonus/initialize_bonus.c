/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:22:15 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/28 20:22:18 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_tmp(t_malloc *m)
{
	int i;

	i = 0;
	if (m->tmp)
	{
		while (m->tmp[i])
		{
			free(m->tmp[i]);
			i++;
		}
		free(m->tmp);
	}
}

void	free_malloc(t_malloc *m)
{
	if (m->line)
		free(m->line);
	if (m->line_map)
		free(m->line_map);
	if (m->fd != -1)
		close(m->fd);
	free_tmp(m);
}

void	init_malloc(t_malloc *m)
{
	m->line = NULL;
	m->line_map = NULL;
	m->tmp = NULL;
	m->fd = 0;
}

void	init_mlx(t_datas *map)
{
	int i;

	i = 0;
	while (i < 5)
		map->txt[i++].img = NULL;
	map->mlx.wdw2 = NULL;
	map->fps.img = NULL;
	map->mlx.ptr = NULL;
}

void	initialize_struct(t_datas *map)
{
	map->bmp = 0;
	map->res_x = 0;
	map->res_y = 0;
	map->no_path = NULL;
	map->so_path = NULL;
	map->ea_path = NULL;
	map->we_path = NULL;
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
