/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:35:23 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/29 17:27:32 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

static void	ft_fillmap(char *line, char **line_map)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(line, "-");
	tmp2 = ft_strjoin(*line_map, tmp);
	free(tmp);
	*line_map = tmp2;
}

static int	ft_fill_floor(t_datas *map, t_flags *flags, char **tmp)
{
	int r;
	int g;
	int b;

	r = ft_atoi(tmp[1]);
	g = ft_atoi(tmp[2]);
	b = ft_atoi(tmp[3]);
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
	{
		flags->F = 1;
		map->f_rgb = create_trgb(0, r, g, b);
		printf("floor color = %i\n", map->f_rgb);
		return (0);
	}
	else
		return (-1);
}

static int ft_fill_ceiling(t_datas *map, t_flags *flags, char **tmp)
{
	int r;
	int g;
	int b;

	r = ft_atoi(tmp[1]);
	g = ft_atoi(tmp[2]);
	b = ft_atoi(tmp[3]);
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
	{
		flags->C = 1;
		map->c_rgb = create_trgb(0, r, g, b);
		printf("ceiling color = %i\n", map->c_rgb);
		return (0);
	}
	else
		return (-1);
}

static int	ft_rgb(int *mapclearance, char *line, t_datas *map, t_flags *flags)
{
	char **tmp;
	static int k = 0;

	(*mapclearance)++;
	tmp = ft_splits(line, " ,"); //CONTROLER LE MALLOC
	while (tmp[k])
		k++;
	if (k != 4)
		return (-1);
	if (tmp[0][0] == 'F')
		return (ft_fill_floor(map, flags, tmp));
	else if (tmp[0][0] == 'C')
		return (ft_fill_ceiling(map, flags, tmp));
	else 
		return (-1);
}

static void	ft_fillNO_path(t_datas *map, t_flags *flags, char *str)
{
	flags->NO = 1;
	map->NO_path = ft_strdup(str);
}

static void	ft_fillWE_path(t_datas *map, t_flags *flags, char *str)
{
	flags->WE = 1;
	map->WE_path = ft_strdup(str);
}

static void	ft_fillEA_path(t_datas *map, t_flags *flags, char *str)
{
	flags->EA = 1;
	map->EA_path = ft_strdup(str);
}

static void	ft_fillSO_path(t_datas *map, t_flags *flags, char *str)
{
	flags->SO = 1;
	map->SO_path = ft_strdup(str);
}

static void	ft_fillsprite_path(t_datas *map, t_flags *flags, char *str)
{
	flags->sprite = 1;
	map->sprite_path = ft_strdup(str);
}

static int	ft_filltexture(int *mapclearance, char *line, t_datas *map, t_flags *flags)
{
	char **tmp;
	static int k = 0; //VERIFIEZ SI LEGITIME

	(*mapclearance)++;
	tmp = ft_split(line, ' ');
	while (tmp[k])
		k++;
	if (k != 2)
		return (-1);
	if (tmp[0][0] == 'N' && tmp[0][1] == 'O' && !flags->NO)
		ft_fillNO_path(map, flags, tmp[1]);
	else if (tmp[0][0] == 'W' && tmp[0][1] == 'E' && !flags->WE)
		ft_fillWE_path(map, flags, tmp[1]);
	else if (tmp[0][0] == 'E' && tmp[0][1] == 'A' && !flags->EA)
		ft_fillEA_path(map, flags, tmp[1]);
	else if (tmp[0][0] == 'S' && ((tmp[0][1] == 'O' && !flags->SO) || (!tmp[0][1] && !flags->sprite)))
	{
		if (tmp[0][1] == 'O')
			ft_fillSO_path(map, flags, tmp[1]);
		else
			ft_fillsprite_path(map, flags, tmp[1]);
	}
	else
		return (-1);
	return (0);
}

static int	ft_fillres(int *mapclearance, char *line, t_datas *map, t_flags *flags)
{
	char **tmp;
	static int k = 0;

	(*mapclearance)++;
	tmp = ft_split(line, ' '); //controller les mallocs
	while (tmp[k])
		k++;
	if (k != 3 || (tmp[0][0] == 'R' && tmp[0][1]) || flags->R)
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

static int	ft_fillstruct2(char *line, int i, char **line_map)
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

static int ft_fillstruct(char *line, char **line_map, t_datas *map)
{
	int	i;
	static t_flags flags;
	static int mapclearance = 0;

	i = 0;
	if (mapclearance < 8)
	{
		while(line[i] == ' ')
			i++;
		if (!line[i])
			return (0);
		if (line[i] == 'R')
			return (ft_fillres(&mapclearance, line, map, &flags));
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			return (ft_filltexture(&mapclearance, line, map, &flags));
		else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ') // se calquer sur méthode des textures juste au dessus !
			return (ft_rgb(&mapclearance, line, map, &flags));
		else 
			return (-1);
	}
	else if (mapclearance == 8)
		return(ft_fillstruct2(line, i, line_map));
	else
		return (-1);
}

int	ft_parsor(char *path, t_datas *map)
{
	int fd;
	int a;
	int ret;
	char *line;
	char *line_map;

	line_map = ft_strdup(""); //malloc Donc = check
	fd = open(path, O_RDONLY);
	a = get_next_line(fd,&line);
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
	return(ret);
}
