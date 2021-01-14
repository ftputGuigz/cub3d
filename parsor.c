/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:35:23 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/13 23:39:29 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_fillres(char *line, t_map map_datas)
static int	ft_filltexture(char *line, t_map map_datas)
static int	ft_rgb(char *line, t_map map_datas)

int ft_fillstruct(char *line)
{
	int	i;
	int	ret;
	t_map	map_datas;
	static int mapclearance = 0;

	i = 0;
	while(line[i] == ' ')
		i++;
	if (line[i] == 'R')
	{
		ret = ft_fillres(line);
		mapclearance++;
	}
	else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
	{
		ret = ft_filltexture(line);
		mapclearance++;
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		ret = ft_rgb(line);
		mapclearance;
	}
	else 
		ret = -1;

	return (ret);
}

int	ft_parsor(char *path)
{
	int fd;
	int a;
	int ret;
	char *line;

	fd = open(path, O_RDONLY);
	a = get_next_line(fd, &line);
	while (a)
	{
		printf("line = %s\n", line);
		ret = ft_fillstruct(line);
		a = get_next_line(fd, &line);
	}
	close(fd);
	return(ret);
}
