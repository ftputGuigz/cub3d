/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:41:21 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/11 11:58:29 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_checkextension(char *str)
{
	int z;

	z = ft_strlen(str);
	if (z >= 4 && str[z - 1] == 'b' && str[z - 2] == 'u' && str[z - 3] == 'c' && str[z - 4] == '.')
		return (1);
	else
		return (0);
	
}

static int	flag_check(char *str)
{
	int ret;
	int len;

	len = ft_strlen(str);
	ret = ft_strncmp(str, "--save", 6);
	if (ret != 0 || len != 6)
		return (1);
	else
		return (0);
}

static int	main2(int ac, char *av1)  //RESPO INIT PARTIE GRAPHIQUE
{
	t_datas map;
	int ret;

	initialize_struct(&map);
	if (ac == 3)
		map.bmp = 1;
	ret = ft_parsor(av1, &map); //CHECKER SI RET = -1;
	if (LINUX)
		screen_size_linux(&map);
	else
		screen_size_macos(&map);
	if (ret != -1)
		ret = ft_display(&map);
	return (ret);
}

int main(int ac, char **av) //RESPO GESTIOn D'ERREUR
{
	int	check;
	int	fd;
	char buff[2];

	if (ac == 2 || ac == 3)
	{
		if (!ft_checkextension(av[1]))
		{
			printf("Wrong type of file. Only [yourfile.cub] format is accepted.\n");
			return (0);
		}
		if (ac == 3 && flag_check(av[2]))
		{
			printf("Wrong argument. Only ./cub3D [yourmap.cub] --save is accepted");
			return (0);
		}
	}
	else
	{
		printf("Wrong number of arguments. 1 is required.\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || read(fd, buff, 1) < 0)
	{
		printf("Cannot find file.\n");
		return (0);
	}
	close(fd);
	{
		check = main2(ac, av[1]);
		if (check == -1)
		{
			printf("Error\n");
			printf("Your <*.cub> file is not valid.\n");
			return (0);
		}
		else
			printf("datas correctes");
	}
	return (0);
}
