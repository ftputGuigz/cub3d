/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:27:49 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/15 13:27:28 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int map_checklastline(char *lastline, char *upperline)
{
	int i;
	
	i = 0;
	while (lastline[i])
	{
		if (lastline[i] != '1' && lastline[i] != ' ')
			return (-1);
		if (lastline[i] == ' ' && upperline[i] == '0')
			return (-1);
		i++;
	}
	return (0);
}

static int map_checkfirstline(char *firstline, char *underline)
{
	int i;
	
	i = 0;
	while (firstline[i])
	{
		if (firstline[i] != '1' && firstline[i] != ' ')
			return (-1);
		if (firstline[i] == ' ' && underline[i] == '0')
			return (-1);
		i++;
	}
	return (0);
}

static int	map_checkerror(char **map, int k)
{
	int i;
	int ret;
	
	if (k <= 2)
		return (-1);
	while (i <= k && ret != -1)
	{
		if (i == 0)
			ret = map_checkfirstline(map[i], map[i + 1]);
		else if (i == k)
			ret = map_checkfirstline(map[i]);
		else
			ret = map_checklastline(map[i], map[i - 1]);
		i++;
	}	
	return(ret);
}

char **map_parsor(char *line_map)
{
	char **map;
	int k;

	k = 0 ;
	map = ft_split(line_map, '-');
	while (map[k])
	{
		printf("%s\n", map[k]);
		k++;
	}
	if (map_checkerrors(map, k))
	{
		return(NULL);
	}
	return(map);	
}
