/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:35:23 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/16 19:48:02 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static int	ft_fillres(char *line, t_map map_datas)
//static int	ft_filltexture(char *line, t_map map_datas)
//static int	ft_rgb(char *line, t_map map_datas)

static void	ft_fillmap(char *line, char **line_map)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(line, "-");
	tmp2 = ft_strjoin(*line_map, tmp);
	free(tmp);
	*line_map = tmp2;
}

static int ft_fillstruct(char *line, char **line_map)
{
	int	i;
	//t_map	map_datas;
	static int mapclearance = 0;
	static int mapbegin = 0;
	static int mapend = 0;

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
			return (0);
			//return (ft_fillres(line));
		}
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			mapclearance++;
			return(0);
			//return (ft_filltexture(line));
		}
		else if (line[i] == 'F' || line[i] == 'C')
		{
			mapclearance++;
			return(0);
			//return (ft_rgb(line));
		}
		else 
			return (-1);
	}
	if (mapclearance == 8)
	{
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
		if (mapbegin && mapend)
		{
			if (line[i])
				return (-1);
			return (0);
		}
	}
	return (0);
}

int	ft_parsor(char *path)
{
	int fd;
	int a;
	int ret;
	char *line;
	char *line_map;
	char **map;

	line_map = ft_strdup("");
	fd = open(path, O_RDONLY);
	a = get_next_line(fd, &line);
	ret = 0;
	map = NULL;
	while (a && ret != -1)
	{
		ret = ft_fillstruct(line, &line_map); //controle le remplissage grossier et les datas (espaces etc)
		free(line);
		a = get_next_line(fd, &line);
	}
	free(line);
	if (ret != -1)
		map = map_parsor(line_map); //controle les donnees de la MAP de facon detaillee
	free(line_map);
	close(fd);
	if (!map)
		ret = -1;
	free(map);//FREE POUR DOUBLE TABLEAU !
	return(ret);
}
