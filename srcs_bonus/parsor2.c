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

void	ft_fill_no_path(t_datas *map, t_flags *flags, char *str)
{
	flags->NO = 1;
	map->NO_path = ft_strdup(str);
}

void	ft_fill_we_path(t_datas *map, t_flags *flags, char *str)
{
	flags->WE = 1;
	map->WE_path = ft_strdup(str);
}

void	ft_fill_ea_path(t_datas *map, t_flags *flags, char *str)
{
	flags->EA = 1;
	map->EA_path = ft_strdup(str);
}

void	ft_fill_so_path(t_datas *map, t_flags *flags, char *str)
{
	flags->SO = 1;
	map->SO_path = ft_strdup(str);
}

void	ft_fillsprite_path(t_datas *map, t_flags *flags, char *str)
{
	flags->sprite = 1;
	map->spr_path = ft_strdup(str);
}
