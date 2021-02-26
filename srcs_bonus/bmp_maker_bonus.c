/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:59:55 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/22 10:59:56 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		bmp_header(int fd, t_datas *map)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * map->res_x * map->res_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &map->res_x, 4);
	write(fd, &map->res_y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &map->fps.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

static void	bmp_pixels(int fd, t_datas *map)
{
	int		x;
	int		y;
	char	*color;

	y = map->res_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < map->res_x)
		{
		 	color = map->fps.addr + (y * map->fps.line_length + x * (map->fps.bits_per_pixel / 8));
			write(fd, &(*(unsigned int*)color), 4);
			x++;
		}
		y--;
	}
}

void		make_bmp(t_datas *map)
{
	int fd;

	fd = open("img.bmp", O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
	if (fd >= 0)
	{
		bmp_header(fd, map);
		bmp_pixels(fd, map);
		map->bmp = 0;
	}
	else
		printf("error Fd is null");
	close(fd);
	exit (0);  //CLOSE PROPREMENT ET NETTOYER A COUP DE FREE ET DE MALLOC
}