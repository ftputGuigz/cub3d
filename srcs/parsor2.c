/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:10:05 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 20:13:06 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_no_path(t_malloc *m, t_datas *map, t_flags *flg, char *str)
{
	flg->no = 1;
	map->no_path = ft_strdup(str);
	if (!map->no_path)
		failed_malloc(m, map);
}

void	ft_fill_we_path(t_malloc *m, t_datas *map, t_flags *flg, char *str)
{
	flg->we = 1;
	map->we_path = ft_strdup(str);
	if (!map->we_path)
		failed_malloc(m, map);
}

void	ft_fill_ea_path(t_malloc *m, t_datas *map, t_flags *flg, char *str)
{
	flg->ea = 1;
	map->ea_path = ft_strdup(str);
	if (!map->ea_path)
		failed_malloc(m, map);
}

void	ft_fill_so_path(t_malloc *m, t_datas *map, t_flags *flg, char *str)
{
	flg->so = 1;
	map->so_path = ft_strdup(str);
	if (!map->so_path)
		failed_malloc(m, map);
}

void	ft_fillsprite_path(t_malloc *m, t_datas *map, t_flags *flg, char *str)
{
	flg->sprite = 1;
	map->spr_path = ft_strdup(str);
	if (!map->spr_path)
		failed_malloc(m, map);
}
