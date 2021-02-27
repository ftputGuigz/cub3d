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

int	ft_filltexture(int *mapclearance, t_malloc *m, t_datas *map, t_flags *flags)
{
	char		**tmp;
	int	k;

	k = 0;
	(*mapclearance)++;
	tmp = ft_split(m->line, ' ');
	if (tmp == NULL)
		failed_malloc(m, map);
	while (tmp[k])
		k++;
	if (k != 2)
		return (-1);
	if (tmp[0][0] == 'N' && tmp[0][1] == 'O' && !tmp[0][2] && !flags->NO)
		ft_fill_no_path(m, map, flags, tmp[1]);
	else if (tmp[0][0] == 'W' && tmp[0][1] == 'E' && !tmp[0][2] && !flags->WE)
		ft_fill_we_path(m, map, flags, tmp[1]);
	else if (tmp[0][0] == 'E' && tmp[0][1] == 'A' && !tmp[0][2] && !flags->EA)
		ft_fill_ea_path(m, map, flags, tmp[1]);
	else if (tmp[0][0] == 'S' && ((tmp[0][1] == 'O' && !tmp[0][2] && !flags->SO) || (!tmp[0][1] && !flags->sprite)))
	{
		if (tmp[0][1] == 'O')
			ft_fill_so_path(m, map, flags, tmp[1]);
		else
			ft_fillsprite_path(m, map, flags, tmp[1]);
	}
	else
		return (-1);
	return (0);
}

int	ft_fillres(int *mapclearance, t_malloc *m, t_datas *map, t_flags *flags)
{
	char		**tmp;
	static int	k = 0;

	(*mapclearance)++;
	tmp = ft_split(m->line, ' '); //controller les mallocs
	if (tmp == NULL)
		failed_malloc(m, map);
	while (tmp[k])
		k++;
	if (k != 3 || (tmp[0][0] == 'R' && tmp[0][1]) || flags->R || check_num_res(tmp))
		return (-1);
	else
	{
		flags->R = 1;
		map->res_x = ft_atoi(tmp[1]);
		map->res_y = ft_atoi(tmp[2]);
	}
	if (map->res_x <= 0 || map->res_y <= 0)
		return (-1);
	return (0);
}

int	ft_fillstruct2(t_malloc *m, t_datas *map, int i)
{
	static int mapbegin = 0;
	static int mapend = 0;

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
	int			i;
	static		t_flags flags;
	static int	mapclearance = 0;

	i = 0;
	if (mapclearance < 8)
	{
		while (m->line[i] == ' ')
			i++;
		if (!m->line[i])
			return (0);
		if (m->line[i] == 'R')
			return (ft_fillres(&mapclearance, m, map, &flags));
		else if (m->line[i] == 'N' || m->line[i] == 'S' || m->line[i] == 'W' || m->line[i] == 'E')
			return (ft_filltexture(&mapclearance, m, map, &flags));
		else if ((m->line[i] == 'F' || m->line[i] == 'C') && m->line[i + 1] == ' ')// se calquer sur méthode des textures juste au dessus !
			return (ft_rgb(&mapclearance, m, map, &flags));
		else
			return (-1);
	}
	else if (mapclearance == 8)
		return (ft_fillstruct2(m, map, i));
	else
		return (-1);
}

int	ft_parsor(char *path, t_datas *map)
{
	int		a;
	int		ret;
	t_malloc m;

	init_malloc(&m);
	m.line_map = ft_strdup(""); //malloc Donc = check
	m.fd = open(path, O_RDONLY);
	a = get_next_line(m.fd, &m.line);
	ret = 0;
	while (a && ret != -1)
	{
		ret = ft_fillstruct(&m, map);
		free(m.line);
		a = get_next_line(m.fd, &m.line);
	}
	if (ret != -1)
		ret = map_parsor(&m, map);
	free_malloc(&m);
	return (ret);
}
