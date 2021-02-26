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

int	ft_filltexture(int *mapclearance, char *line, t_datas *map, t_flags *flags)
{
	char		**tmp;
	int	k;

	k = 0;
	(*mapclearance)++;
	tmp = ft_split(line, ' ');
	while (tmp[k])
		k++;
	if (k != 2)
		return (-1);
	if (tmp[0][0] == 'N' && tmp[0][1] == 'O' && !tmp[0][2] && !flags->NO)
		ft_fill_no_path(map, flags, tmp[1]);
	else if (tmp[0][0] == 'W' && tmp[0][1] == 'E' && !tmp[0][2] && !flags->WE)
		ft_fill_we_path(map, flags, tmp[1]);
	else if (tmp[0][0] == 'E' && tmp[0][1] == 'A' && !tmp[0][2] && !flags->EA)
		ft_fill_ea_path(map, flags, tmp[1]);
	else if (tmp[0][0] == 'S' && ((tmp[0][1] == 'O' && !tmp[0][2] && !flags->SO) || (!tmp[0][1] && !flags->sprite)))
	{
		if (tmp[0][1] == 'O')
			ft_fill_so_path(map, flags, tmp[1]);
		else
			ft_fillsprite_path(map, flags, tmp[1]);
	}
	else
		return (-1);
	return (0);
}

int	ft_fillres(int *mapclearance, char *line, t_datas *map, t_flags *flags)
{
	char		**tmp;
	static int	k = 0;

	(*mapclearance)++;
	tmp = ft_split(line, ' '); //controller les mallocs
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

int	ft_fillstruct2(char *line, int i, char **line_map)
{
	static int mapbegin = 0;
	static int mapend = 0;

	if (!mapbegin && !mapend)
	{
		if (line[i])
		{
			ft_fillmap(line, line_map);
			mapbegin = 1;
		}
		return (0);
	}
	if (mapbegin && !mapend)
	{
		if (line[i])
			ft_fillmap(line, line_map);
		else
			mapend = 1;
		return (0);
	}
	if (line[i])
		return (-1);
	return (0);
}

int	ft_fillstruct(char *line, char **line_map, t_datas *map)
{
	int			i;
	static		t_flags flags;
	static int	mapclearance = 0;

	i = 0;
	if (mapclearance < 8)
	{
		while (line[i] == ' ')
			i++;
		if (!line[i])
			return (0);
		if (line[i] == 'R')
			return (ft_fillres(&mapclearance, line, map, &flags));
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			return (ft_filltexture(&mapclearance, line, map, &flags));
		else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')// se calquer sur méthode des textures juste au dessus !
			return (ft_rgb(&mapclearance, line, map, &flags));
		else
			return (-1);
	}
	else if (mapclearance == 8)
		return (ft_fillstruct2(line, i, line_map));
	else
		return (-1);
}

int	ft_parsor(char *path, t_datas *map)
{
	int		fd;
	int		a;
	int		ret;
	char	*line;
	char	*line_map;

	line_map = ft_strdup(""); //malloc Donc = check
	fd = open(path, O_RDONLY);
	a = get_next_line(fd, &line);
	ret = 0;
	while (a && ret != -1)
	{
		ret = ft_fillstruct(line, &line_map, map); //controle le remplissage grossier et les datas (espaces etc)
		free(line);
		a = get_next_line(fd, &line);
	}
	free(line);
	if (ret != -1)
		ret = map_parsor(line_map, map); //controle les donnees de la MAP de facon detaillee
	free(line_map);
	close(fd);
	return (ret);
}
