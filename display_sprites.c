/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:25:48 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/13 10:26:01 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void calculate_distance(float **spr_dist, t_datas *map)
{
    int i;

    i = 0;
    while (i < map->sprites_nbr)
    {
        (*spr_dist)[i] = powf(map->player.rfx - (float)(map->spr[i].x + 0.5), 2) + powf(map->player.rfy - (float)(map->spr[i].y + 0.5), 2);
        map->spr_ordr[i] = i;
        i++;
    }
}

static void sort_sprites(float **spr_dist, t_datas *map)
{
    int i;
    int j;
    float tmp;
    int tmp2;

    i = 0;
    while (i < map->sprites_nbr)
    {
        j = i + 1;
        while (j < map->sprites_nbr)
        {
            if ((*spr_dist)[i] < (*spr_dist)[j])
            {
                tmp = (*spr_dist)[j];
                (*spr_dist)[j] = (*spr_dist)[i];
                (*spr_dist)[i] = tmp;
                tmp2 = (map->spr_ordr)[j];
                (map->spr_ordr)[j] = (map->spr_ordr)[i];
                (map->spr_ordr)[i] = tmp2;
            }
            j++;
        }
        i++;
    }
}

static void get_order(t_datas *map)
{
    float *spr_dist;

    spr_dist = malloc(sizeof(float) * map->sprites_nbr); //free propre
    calculate_distance(&spr_dist, map);
    sort_sprites(&spr_dist, map);
    free(spr_dist);
}

void    ft_sprites(t_datas *map)
{
    get_order(map);
}