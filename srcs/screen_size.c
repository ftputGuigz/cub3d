/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:07:42 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 12:07:44 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_size_macos(t_datas *map)
{
	if (map->res_x > MAX_X)
		map->res_x = MAX_X;
	if (map->res_y > MAX_Y)
		map->res_y = MAX_Y;
}

void	screen_size_linux(t_datas *map)
{
	int sizex;
	int sizey;

	LINUX_SCREEN
	if (map->res_x > sizex)
		map->res_x = sizex;
	if (map->res_y > sizey)
		map->res_y = sizey;
}
