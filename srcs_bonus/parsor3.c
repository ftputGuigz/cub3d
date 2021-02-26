/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:10:15 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 20:12:14 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_fillmap(char *line, char **line_map)
{
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(line, "-");
	tmp2 = ft_strjoin(*line_map, tmp);
	free(tmp);
	*line_map = tmp2;
}

int		ft_fill_floor(t_datas *map, t_flags *flags, char **tmp)
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
		return (0);
	}
	else
		return (-1);
}

int		ft_fill_ceiling(t_datas *map, t_flags *flags, char **tmp)
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
		return (0);
	}
	else
		return (-1);
}

int		ft_rgb(int *mapclearance, char *line, t_datas *map, t_flags *flags)
{
	char	**tmp;
	int		k;

	k = 0;
	(*mapclearance)++;
	tmp = ft_splits(line, " ,"); //CONTROLER LE MALLOC
	while (tmp[k])
		k++;
	if (k != 4 || comma_count(line) != 2 || check_num_fc(tmp))
		return (-1);
	if (tmp[0][0] == 'F' && !flags->F)
		return (ft_fill_floor(map, flags, tmp));
	else if (tmp[0][0] == 'C' && !flags->C)
		return (ft_fill_ceiling(map, flags, tmp));
	else
		return (-1);
}
