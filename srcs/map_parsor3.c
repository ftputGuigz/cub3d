/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsor3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:55:07 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/28 20:55:17 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			map_checkerror(char **map, int k)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (k <= 2)
		return (-1);
	while (i < k && ret != -1)
	{
		if (primary_check(map[i], k - 1))
			return (-1);
		if (i == 0)
			ret = map_checkfirstline(map[i], map[i + 1]);
		else if (i == k - 1)
			ret = map_checklastline(map[i], map[i - 1]);
		else
			ret = map_checkmiddleline(map[i], map[i - 1], map[i + 1]);
		i++;
	}
	return (ret);
}

void		get_angle(t_datas *map)
{
	if (map->player.start == 'N')
	{
		map->player.angle = 3 * M_PI_2;
		map->player.ortho = 0;
	}
	if (map->player.start == 'S')
	{
		map->player.angle = M_PI_2;
		map->player.ortho = M_PI;
	}
	if (map->player.start == 'E')
	{
		map->player.angle = 0;
		map->player.ortho = M_PI_2;
	}
	if (map->player.start == 'W')
	{
		map->player.angle = M_PI;
		map->player.ortho = 3 * M_PI_2;
	}
}

static void	map_correction2(t_malloc *m, t_datas *map, int k)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = malloc(sizeof(char) * (map->columns + 1));
	if (!tmp)
		failed_malloc(m, map);
	i = 0;
	while (i < map->columns)
		tmp[i++] = ' ';
	tmp[map->columns] = '\0';
	tmp2 = map->map[k];
	map->map[k] = ft_strjoin(tmp2, tmp);
	if (!map->map[k])
		failed_malloc(m, map);
	free(tmp2);
	free(tmp);	
}

void		map_correction(t_malloc *m, t_datas *map)
{
	int		k;

	k = 0;
	while (map->map[k])
	{
		if ((int)(ft_strlen(map->map[k])) < map->columns)
			map_correction2(m, map, k);
		k++;
	}
}
