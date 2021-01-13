/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:35:23 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/13 16:28:13 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_fillstruct(char *line)
{
	t_map map_datas;

	if ()
}

int	main(void)
{
	int fd;
	int a;
	char *line;

	fd = open("map.cub", O_RDONLY);
	a = get_next_line(fd, &line);
	while (a)
	{
		printf("line = %s\n", line);
		
		a = get_next_line(fd, &line);
	}
	close(fd);
	return(0);
}
