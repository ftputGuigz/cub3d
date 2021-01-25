/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:27:49 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/20 15:01:07 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_surroundings(char a, char b, char c, char d)
{
	if (a == ' ' || b == ' ' || c == ' ' || d == ' ')
		return (1);
	else
		return (0);
}

static int map_checkmiddleline(char *middleline, char *upperline, char *underline)
{
	int i;
	int start;
	int end;
	char sensitive[] = "02NSEW";

	i = 0;
	while (middleline[i] == ' ')
		i++;
	start = i;
	while (middleline[i])
		i++;
	end = i - 1;
	while (middleline[end] == ' ')
		end--;
	if (middleline[start] != '1' || middleline[end] != '1')
		return (-1);
	while (start < end)
	{
		if (ft_strchr(sensitive, middleline[start]) && check_surroundings(middleline[start - 1], middleline[start + 1], upperline[start], underline[start]))
			return (-1);
		start++;
	}
	return (0);
}

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

static int	primary_check(char *str, int k)
{
	char autorized[] = " 012NSEW";
	char letters[] = "NSEW";
	static int letter = 0;
	static int line = 0;
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(autorized, str[i]))
			return (-1);
		if (ft_strchr(letters, str[i]) && letter)
			return (-1);
		if (ft_strchr(letters, str[i]) && !letter)
			letter = 1;
		i++;
	}
	line++;
	if (letter != 1 && line == k)
		return (-1);
	return (0);
}

static int	map_checkerror(char **map, int k)
{
	int i;
	int ret;

	i = 0;
	if (k <= 2)
		return (-1);
	while (i < k && ret != -1)
	{
		if (primary_check(map[i], k - 1))
			return (-1);
		if (i == 0)
			ret = map_checkfirstline(map[i], map[i + 1]);
		else if (i == k - 1)
			ret = map_checklastline(map[i], map[i - 1]);
		else
			ret = map_checkmiddleline(map[i], map[i - 1], map[i + 1]);
		i++;
	}	
	return(ret);
}

static void	register_map_datas(t_datas *map)
{
	static int i = 0;
	int j;
	int k;
	char position[] = "NSEW";

	k = 0;
	while (map->map[k])
	{
		printf("%s\n", map->map[k]);
		j = 0;
		while (map->map[k][j])
		{
			if (ft_strchr(position, map->map[k][j]))
			{
				map->player.start = map->map[k][j];
				map->player.x = j;
				map->player.y = k;
			}
			j++;
		}
		if (j > i)
			i = j;
		k++;
	}
	map->columns = i;
	map->lines = k;
	printf("lignes = %d\n", map->lines);
	printf("colonnes = %d\n", map->columns);
	printf("direction de depart : %c\n", map->player.start);
	printf("position start.x = %d\n", map->player.x);
	printf("position start.y = %d\n", map->player.y);
}

int	map_parsor(char *line_map, t_datas *map)
{
	static int k = 0;

	map->map = ft_split(line_map, '-');
	while (map->map[k])
		k++;
	if (map_checkerror(map->map, k)) //ATTENTION LIBERATION DE MEMOIRE A EFFECTUER
		return (-1);
	else
		register_map_datas(map);
	return(0);
}
