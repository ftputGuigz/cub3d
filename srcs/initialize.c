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

#include "cub3d.h"

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
}