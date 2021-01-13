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
	int i;
	const char[] = "R"
	t_map map_datas;

	i = 0;
	while(line[i] == ' ')
		i++;
	if (line[i] == 'R' || line[i])
	else
		return ;
}

int	ft_parsor(char *path)
{
	int fd;
	int a;
	char *line;

	fd = open("map.cub", O_RDONLY);
	a = get_next_line(fd, &line);
	while (a)
	{
		printf("line = %s\n", line);
		ft_fillstruct
		a = get_next_line(fd, &line);
	}
	close(fd);
	return(0);
}
