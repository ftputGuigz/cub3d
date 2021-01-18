/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:35:23 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/18 21:45:20 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_fillmap(char *line, char **line_map)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(line, "-");
	tmp2 = ft_strjoin(*line_map, tmp);
	free(tmp);
	*line_map = tmp2;
}

/*static int	ft_rgb(char *line, t_datas *map_datas, t_flags *flags)
{
	char **tmp;

	tmp = ft_split(line, ' '); //CONTROLER LE MALLOC
	while (tmp[k])
		k++;
	if (k != 2)
		return (-1);
}*/

static int	ft_filltexture(char *line, t_datas *map_datas, t_flags *flags)
{
	char **tmp;
	int k;

	k = 0;
	tmp = ft_split(line, ' ');
	while (tmp[k])
		k++;
	if (k != 2)
		return (-1);
	if (tmp[0][0] == 'N' && tmp[0][1] == 'O' && !flags->NO)
	{	
		flags->NO = 1;
		map_datas->NO_path = ft_strdup(tmp[1]); //CONTROLER MALLOC
	}
	else if (tmp[0][0] == 'W' && tmp[0][1] == 'E' && !flags->WE)
	{	
		flags->WE = 1;
		map_datas->WE_path = ft_strdup(tmp[1]);
	}
	else if (tmp[0][0] == 'E' && tmp[0][1] == 'A' && !flags->EA)
	{
		flags->EA = 1;
		map_datas->EA_path = ft_strdup(tmp[1]);
	}
	else if (tmp[0][0] == 'S' && ((tmp[0][1] == 'O' && !flags->SO) || (!tmp[0][1] && !flags->sprite)))
	{
		if (tmp[0][1] == 'O')
		{
			flags->SO = 1;
			map_datas->SO_path = ft_strdup(tmp[1]);
		}
		else
		{
			flags->sprite = 1;
			map_datas->sprite_path = ft_strdup(tmp[1]);
		}
	}
	else
		return (-1);
	return (0);
}

static int	ft_fillres(char *line, t_datas *map_datas, t_flags *flags)
{
	char **tmp;
	int k;

	k = 0;
	tmp = ft_split(line, ' '); //controller les mallocs
	while (tmp[k])
		k++;
	if (k != 3 || (tmp[0][0] == 'R' && tmp[0][1]) || flags->R)
		return (-1);
	else
	{
		flags->R = 1;
		map_datas->res_x = ft_atoi(tmp[1]);
		map_datas->res_y = ft_atoi(tmp[2]);
	}
	if (map_datas->res_x <= 0 || map_datas->res_y <= 0)
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

static int ft_fillstruct(char *line, char **line_map, t_datas *map_datas)
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
		{
			mapclearance++;
			return (ft_fillres(line, map_datas, &flags));
		}
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			mapclearance++;
			return (ft_filltexture(line, map_datas, &flags));
		}
		else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
		{
			mapclearance++;
			return (0);
			//return (ft_rgb(line, &map_datas, &flags));
		}
		else 
			return (-1);
	}
	else if (mapclearance == 8)
		return(ft_fillstruct2(line, i, line_map));
	else
		return (-1);
}

int	ft_parsor(char *path, t_datas *map_datas)
{
	int fd;
	int a;
	int ret;
	char *line;
	char *line_map;

	line_map = ft_strdup("");
	fd = open(path, O_RDONLY);
	a = get_next_line(fd,&line);
	ret = 0;
	while (a && ret != -1)
	{
		ret = ft_fillstruct(line, &line_map, map_datas); //controle le remplissage grossier et les datas (espaces etc)
		free(line);
		a = get_next_line(fd, &line);
	}
	free(line);
	if (ret != -1)
		map_datas->map = map_parsor(line_map); //controle les donnees de la MAP de facon detaillee
	free(line_map);
	close(fd);
	if (!map_datas->map)
		ret = -1;
	//free(map_datas->map);//FREE POUR DOUBLE TABLEAU !
	return(ret);
}
