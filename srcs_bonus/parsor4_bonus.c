/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:16:09 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/25 15:16:11 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_comma_start_end(char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == 'F' || line[i] == 'C'))
		i++;
	if (line[i] == ',')
		return (-1);
	i = ft_strlen(line) - 1;
	while (i >= 0 && line[i] == ' ')
		i--;
	if (line[i] == ',')
		return (-1);
	return (0);
}

int		check_num_fc(char **tmp)
{
	int i;
	int j;

	j = 1;
	while (j <= 3)
	{
		i = 0;
		while (tmp[j][i])
		{
			if (tmp[j][i] < '0' || tmp[j][i] > '9')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int		check_num_res(char **tmp)
{
	int i;
	int j;

	j = 1;
	while (j <= 2)
	{
		i = 0;
		while (tmp[j][i])
		{
			if (tmp[j][i] < '0' || tmp[j][i] > '9')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int		comma_count(char *line)
{
	int	comma;
	int	i;
	int j;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			comma++;
			j = i + 1;
			while (line[j] && line[j] == ' ')
				j++;
			if (line[j] == ',')
				return (-1);
		}
		i++;
	}
	return (comma);
}

void	init_double_array(t_malloc *m, t_datas *map)
{
	free_tmp(m);
	m->tmp = ft_split(m->line, ' ');
	if (m->tmp == NULL)
		failed_malloc(m, map);
}
