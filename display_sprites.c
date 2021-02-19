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
	int i;
	float spritx;
	float sprity;
	float invDet;
	char *color;
	int color2;

	i = 0;
    get_order(map);
	while (i < map->sprites_nbr)
	{
		spritx = (map->spr[map->spr_ordr[i]].x + 0.5) - map->player.rfx;
		sprity = (map->spr[map->spr_ordr[i]].y + 0.5) - map->player.rfy;

		invDet = 1.0 / (map->player.planx * map->player.diry - map->player.dirx * map->player.plany);

		float transformX = invDet * (map->player.diry * spritx - map->player.dirx * sprity);
		float transformY = invDet * (-map->player.plany * spritx + map->player.planx * sprity);

		int spriteScreenx = (int)((map->res_x / 2) * (1 - transformX / transformY));

		int spriteHeight = abs((int)(map->res_y / (transformY)));
		int spriteWidth = abs((int)(map->res_y / (transformY)));

		int drawStartY = -spriteHeight / 2 + map->res_y / 2;
		if(drawStartY < 0)
			drawStartY = 0;

		int drawEndY = spriteHeight / 2 + map->res_y / 2;
      	if(drawEndY >= map->res_y) 
			drawEndY = map->res_y - 1;

      	int drawStartX = -spriteWidth / 2 + spriteScreenx;
      	if(drawStartX < 0) 
			drawStartX = 0;
     	int drawEndX = spriteWidth / 2 + spriteScreenx;
      	if(drawEndX >= map->res_x)
			drawEndX = map->res_x - 1;
		
		int stripe = drawStartX;
		while (stripe < drawEndX)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenx)) * map->txt2[0].i / spriteWidth)) / 256;
			if (transformY > 0 && stripe > 0 && stripe < map->res_x && transformY < map->buff[stripe])
			{
				int y = drawStartY;
				while (y < drawEndY)
				{
					int d = y * 256 - map->res_y * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					int texY = ((d * map->txt2[0].j) / spriteHeight) / 256;
					color = map->txt2[0].addr + (texY * map->txt2[0].line_length + texX * (map->txt2[0].bits_per_pixel / 8));
					color2 = *(unsigned int *)color;
					if (color2 != 0x000000)
						ft_mlx_pixel_put(&map->fps, stripe, y, color2);
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}