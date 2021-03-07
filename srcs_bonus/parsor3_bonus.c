/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:10:15 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 20:12:14 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_fillmap(t_malloc *m, t_datas *map)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(m->line, "-");
	if (!tmp)
		failed_malloc(m, map);
	tmp2 = m->line_map;
	m->line_map = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
	if (!m->line_map)
		failed_malloc(m, map);
}

int		ft_fill_floor(t_datas *map, t_flags *flg, char **tmp)
{
	int r;
	int g;
	int b;

	r = ft_atoi(tmp[1]);
	g = ft_atoi(tmp[2]);
	b = ft_atoi(tmp[3]);
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
	{
		flg->f = 1;
		map->f_rgb = create_trgb(0, r, g, b);
		return (0);
	}
	else
		return (-1);
}

int		ft_fill_ceiling(t_datas *map, t_flags *flg, char **tmp)
{
	int r;
	int g;
	int b;

	r = ft_atoi(tmp[1]);
	g = ft_atoi(tmp[2]);
	b = ft_atoi(tmp[3]);
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
	{
		flg->c = 1;
		map->c_rgb = create_trgb(0, r, g, b);
		return (0);
	}
	else
		return (-1);
}

int		ft_rgb(int *mapclearance, t_malloc *m, t_datas *map, t_flags *flg)
{
	int		k;

	k = 0;
	(*mapclearance)++;
	free_tmp(m);
	m->tmp = ft_splits(m->line, " ,");
	if (!m->tmp)
		failed_malloc(m, map);
	while (m->tmp[k])
		k++;
	if (k != 4 || comma_count(m->line) != 2 || check_num_fc(m->tmp) ||
	check_comma_start_end(m->line))
		return (-1);
	if (m->tmp[0][0] == 'F' && !flg->f)
		return (ft_fill_floor(map, flg, m->tmp));
	else if (m->tmp[0][0] == 'C' && !flg->c)
		return (ft_fill_ceiling(map, flg, m->tmp));
	else
		return (-1);
}
