/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:35:23 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/14 22:13:12 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static int	ft_fillres(char *line, t_map map_datas)
//static int	ft_filltexture(char *line, t_map map_datas)
//static int	ft_rgb(char *line, t_map map_datas)

static char *ft_fillmap(char *line, char *line_map)
{
	char *tmp;
	char *tmp2;
	static int first_line = 0;

	if (!first_line)
	{
		first_line = 1;
		line_map = ft_strjoin(line, "-");
	}
	else
	{
		tmp = ft_strjoin(line, "-");
		tmp2 = line_map;
		line_map = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
	}
	printf("line map vaut %s\n", line_map);
	return (line_map);
}

static int ft_fillstruct(char *line, char *line_map)
{
	int	i;
	//t_map	map_datas;
	static int mapclearance = 0;
	static int mapbegin = 0;

	i = 0;
	if (mapclearance < 8)
	{
		while(line[i] == ' ')
			i++;
		if (line[i] == '\n')
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
	printf("i = |%d|", i);
	if (mapclearance == 8 && line[i] == '\n' && !mapbegin)
	{
		printf("la");
		return (0);
	}
	else if (mapclearance == 8 && line[i] == '\n' && mapbegin)
	{	
		printf("ici");
		return (-1);
	}
	else
	{
		printf("surtout la");
		mapbegin = 1;
		line_map = ft_fillmap(line, line_map);
		return (0);
	}
}

int	ft_parsor(char *path)
{
	int fd;
	int a;
	int ret;
	char *line;
	char *line_map;

	line_map = NULL;
	fd = open(path, O_RDONLY);
	a = get_next_line(fd, &line);
	while (a)
	{
		printf("line = %s\n", line);
		ret = ft_fillstruct(line, line_map);
		free(line);
		a = get_next_line(fd, &line);
	}
	free(line);
	free(line_map);
	close(fd);
	return(ret);
}
