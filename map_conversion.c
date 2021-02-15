/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:53:59 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/02 13:15:09 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initposition(t_datas *map)
{
	map->player.rfx = (float)map->player.x + 0.5;
	//printf("rfx = %f\n", map->player.rfx);
	map->player.fx = map->player.rfx * (float)map->res_x / (float)map->columns;
	//printf("fx = %f\n", map->player.fx);
	map->player.rfy = (float)map->player.y + 0.5;
	//printf("rfy = %f\n", map->player.rfy);
	map->player.fy = map->player.rfy * (float)map->res_y / (float)map->lines;
	//printf("fy = %f\n", map->player.fy);
}
