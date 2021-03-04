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

#include "cub3d_bonus.h"

void		spr_calculation(t_spr *s, t_datas *map, int i)
{
	s->spritx = (map->spr[map->spr_ordr[i]].x + 0.5) - map->player.rfx;
	s->sprity = (map->spr[map->spr_ordr[i]].y + 0.5) - map->player.rfy;
	s->invdet = 1.0 / (map->player.planx * map->player.diry - map->player.dirx *
	map->player.plany);
	s->transformx = s->invdet * (map->player.diry * s->spritx -
	map->player.dirx * s->sprity);
	s->transformy = s->invdet * (-map->player.plany * s->spritx +
	map->player.planx * s->sprity);
	s->spritescreenx = (int)((map->res_x / 2) *
	(1 - s->transformx / s->transformy));
	s->spriteheight = abs((int)(map->res_y / (s->transformy)));
	s->spritewidth = abs((int)(map->res_y / (s->transformy)));
	s->drawstarty = -s->spriteheight / 2 + map->res_y / 2;
	if (s->drawstarty < 0)
		s->drawstarty = 0;
	s->drawendy = s->spriteheight / 2 + map->res_y / 2;
	if (s->drawendy >= map->res_y)
		s->drawendy = map->res_y - 1;
	s->drawstartx = -s->spritewidth / 2 + s->spritescreenx;
	if (s->drawstartx < 0)
		s->drawstartx = 0;
	s->drawendx = s->spritewidth / 2 + s->spritescreenx;
	if (s->drawendx >= map->res_x)
		s->drawendx = map->res_x - 1;
}

void		spr_draw(t_spr *s, t_datas *map, int *color)
{
	int y;

	s->stripe = s->drawstartx;
	while (s->stripe < s->drawendx)
	{
		s->texx = (int)((256 * (s->stripe - (-s->spritewidth /
		2 + s->spritescreenx)) * map->txt[4].i / s->spritewidth)) / 256;
		if (s->transformy > 0 && s->stripe > 0 && s->stripe < map->res_x &&
		s->transformy < map->buff[s->stripe])
		{
			y = s->drawstarty;
			while (y < s->drawendy)
			{
				s->d = y * 256 - map->res_y * 128 + s->spriteheight * 128;
				s->texy = ((s->d * map->txt[4].j) / s->spriteheight) / 256;
				*color = *(unsigned int *)(map->txt[4].addr + (abs(s->texy) *
				map->txt[4].line_length + abs(s->texx) *
				(map->txt[4].bits_per_pixel / 8)));
				if (*color != 0x000000)
					ft_mlx_pixel_put(&map->fps, s->stripe, y, *color);
				y++;
			}
		}
		s->stripe++;
	}
}

void		ft_sprites(t_datas *map)
{
	int		i;
	int		color;
	t_spr	s;

	i = 0;
	get_order(map);
	while (i < map->sprites_nbr)
	{
		spr_calculation(&s, map, i);
		spr_draw(&s, map, &color);
		i++;
	}
}
