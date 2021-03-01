/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:27:49 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/28 14:26:40 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	start_position(t_datas *map, int j, int k)
{
	map->player.start = map->map[k][j];
	get_angle(map);
	map->player.x = j;
	map->player.y = k;
	map->map[k][j] = '0';
}

static void	register_map_datas(t_datas *map)
{
	static int	i = 0;
	int			j;
	int			k;
	static char	position[] = "NSEW";

	k = 0;
	while (map->map[k])
	{
		j = 0;
		while (map->map[k][j])
		{
			if (ft_strchr(position, map->map[k][j]))
				start_position(map, j, k);
			if (map->map[k][j] == '2')
				map->sprites_nbr++;
			j++;
		}
		if (j > i)
			i = j;
		k++;
	}
	map->columns = i;
	map->lines = k;
}

static void	sprites_x_y(t_datas *map, int k, int j, int *n)
{
	map->spr[*n].x = j;
	map->spr[*n].y = k;
	map->spr_ordr[*n] = *n;
	(*n)++;
}

static int	register_sprites(t_malloc *m, t_datas *map)
{
	int			j;
	int			k;
	static int	n = 0;

	k = 0;
	map->spr = malloc(sizeof(t_sprite) * map->sprites_nbr);
	map->spr_ordr = malloc(sizeof(int) * map->sprites_nbr);
	if (!map->spr || !map->spr_ordr)
		failed_malloc(m, map);
	while (map->map[k])
	{
		j = 0;
		while (map->map[k][j])
		{
			if (map->map[k][j] == '2')
				sprites_x_y(map, k, j, &n);
			j++;
		}
		k++;
	}
	return (0);
}

static void	map_correction(t_datas *map)
{
	int k;
	int i;
	char *tmp;
	char *tmp2;

	k = 0;
	while (map->map[k])
	{
		if ((int)(ft_strlen(map->map[k])) < map->columns)
		{
			tmp = malloc(sizeof(char) * (map->columns + 1));
			i = 0;
			while (i < map->columns)
				tmp[i++] = ' ';
			tmp[map->columns] = '\0';
			tmp2 = map->map[k];
			map->map[k] = ft_strjoin(tmp2, tmp);
			free(tmp2);
			free(tmp);
		}
		k++;
	}
}

int			map_parsor(t_malloc *m, t_datas *map)
{
	static int	k = 0;
	int			ret;

	map->map = ft_split(m->line_map, '-');
	if (!map->map)
		failed_malloc(m, map);
	while (map->map[k])
		k++;
	if (map_checkerror(map->map, k))
		return (-1);
	else
	{
		register_map_datas(map);
		ret = register_sprites(m, map);
		map_correction(map);
		if (ret)
			return (-1);
	}
	return (0);
}
