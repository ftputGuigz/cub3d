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

/* static void calculate_distance(float *spr_dist, t_datas *map)
{
    int i;

    i = 0;
    while (i < map->sprites_nbr)
    {
        spr_dist[i] = sqrtf(map->player.rfx - map->spr[i].x) + sqrtf(map->player.rfy - map->spr[i].y);
        i++;
    }
}

static void sort_sprites(t_datas *map)
{
    float spr_dist[map->sprites_nbr];
    int i;
    int j;
    int tmp;

    calculate_distance(&spr_dist[map->sprites_nbr], map);
    i = 0;
    while (i < map->sprites_nbr)
    {
        j = i + 1;
        while (j < map->sprites_nbr)
        {
            if (spr_dist[i] > spr_dist[j])
            {
                tmp = spr_dist[j];
                spr_dist[j] = spr_dist[i];
                spr_dist[i] = tmp;
                tmp = map->spr_ordr[j];
                map->spr_ordr[j] = map->spr_ordr[i];
                map->spr_ordr[i] = tmp;
            }
            j++;
        }
        i++;
    }

} */

void    ft_sprites(t_datas *map)
{
    //sort_sprites(map);

    int i = 0;
    while (i < map->sprites_nbr)
    {
        printf("Order = %i\n", map->spr_ordr[i]);
        i++;
    }
}