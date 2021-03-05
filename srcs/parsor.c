/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:35:23 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 19:37:26 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_filltexture(int *mapclearance, t_malloc *m, t_datas *map, t_flags *flg)
{
	int	k;

	k = 0;
	(*mapclearance)++;
	init_double_array(m, map);
	while (m->tmp[k])
		k++;
	if (k != 2)
		return (-1);
	if (m->tmp[0][0] == 'N' && m->tmp[0][1] == 'O' && !m->tmp[0][2] && !flg->no)
		ft_fill_no_path(m, map, flg, m->tmp[1]);
	else if (m->tmp[0][0] == 'W' && m->tmp[0][1] == 'E' && !m->tmp[0][2] &&
	!flg->we)
		ft_fill_we_path(m, map, flg, m->tmp[1]);
	else if (m->tmp[0][0] == 'E' && m->tmp[0][1] == 'A' && !m->tmp[0][2] &&
	!flg->ea)
		ft_fill_ea_path(m, map, flg, m->tmp[1]);
	else if (m->tmp[0][0] == 'S' && m->tmp[0][1] == 'O' && !m->tmp[0][2] &&
	!flg->so)
		ft_fill_so_path(m, map, flg, m->tmp[1]);
	else if (m->tmp[0][0] == 'S' && !m->tmp[0][1] && !flg->sprite)
		ft_fillsprite_path(m, map, flg, m->tmp[1]);
	else
		return (-1);
	return (0);
}

int	ft_fillres(int *mapclearance, t_malloc *m, t_datas *map, t_flags *flg)
{
	static int	k = 0;

	(*mapclearance)++;
	free_tmp(m);
	m->tmp = ft_split(m->line, ' ');
	if (m->tmp == NULL)
		failed_malloc(m, map);
	while (m->tmp[k])
		k++;
	if (k != 3 || (m->tmp[0][0] == 'R' && m->tmp[0][1]) || flg->r ||
	check_num_res(m->tmp))
		return (-1);
	else
	{
		flg->r = 1;
		map->res_x = ft_atoi(m->tmp[1]);
		map->res_y = ft_atoi(m->tmp[2]);
	}
	if (map->res_x <= 0 || map->res_y <= 0)
		return (-1);
	return (0);
}

int	ft_fillstruct2(t_malloc *m, t_datas *map, int i, int mapclearance)
{
	static int mapbegin = 0;
	static int mapend = 0;

	if (mapclearance != 8)
		return (-1);
	if (!mapbegin && !mapend)
	{
		if (m->line[i])
		{
			ft_fillmap(m, map);
			mapbegin = 1;
		}
		return (0);
	}
	if (mapbegin && !mapend)
	{
		if (m->line[i])
			ft_fillmap(m, map);
		else
			mapend = 1;
		return (0);
	}
	if (m->line[i])
		return (-1);
	return (0);
}

int	ft_fillstruct(t_malloc *m, t_datas *map)
{
	int				i;
	static t_flags	flg;
	static int		mapclearance = 0;

	i = 0;
	if (mapclearance < 8)
	{
		while (m->line[i] == ' ')
			i++;
		if (!m->line[i])
			return (0);
		if (m->line[i] == 'R')
			return (ft_fillres(&mapclearance, m, map, &flg));
		else if (m->line[i] == 'N' || m->line[i] == 'S' || m->line[i] == 'W' ||
		m->line[i] == 'E')
			return (ft_filltexture(&mapclearance, m, map, &flg));
		else if ((m->line[i] == 'F' || m->line[i] == 'C') &&
		m->line[i + 1] == ' ')
			return (ft_rgb(&mapclearance, m, map, &flg));
		else
			return (-1);
	}
	else
		return (ft_fillstruct2(m, map, i, mapclearance));
}

int	ft_parsor(char *path, t_datas *map)
{
	int			a;
	int			ret;
	t_malloc	m;

	init_malloc(&m);
	m.line_map = ft_strdup("");
	m.fd = open(path, O_RDONLY);
	if (!m.line_map || m.fd < 0)
		failed_malloc(&m, map);
	a = get_next_line(m.fd, &m.line);
	ret = 0;
	while (a == 1)
	{
		ret = ft_fillstruct(&m, map);
		free(m.line);
		a = get_next_line(m.fd, &m.line);
	}
	if (ret != -1 && a != -1)
		ret = map_parsor(&m, map);
	if (a == -1)
		failed_reading(&m, map);
	free_malloc(&m);
	return (ret);
}
