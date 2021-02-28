/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsor2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:42:04 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/28 20:42:06 by gpetit           ###   ########.fr       */
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

int			map_checkmiddleline(char *middleline, char *upperline,
char *underline)
{
	int			i;
	int			start;
	int			end;
	static char	sensitive[] = "02NSEW";

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
		if (ft_strchr(sensitive, middleline[start]) &&
		check_surroundings(middleline[start - 1], middleline[start + 1],
		upperline[start], underline[start]))
			return (-1);
		start++;
	}
	return (0);
}

int			map_checklastline(char *lastline, char *upperline)
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

int			map_checkfirstline(char *firstline, char *underline)
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

int			primary_check(char *str, int k)
{
	static char	autorized[] = " 012NSEW";
	static char	letters[] = "NSEW";
	static int	letter = 0;
	static int	line = 0;
	int			i;

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
