/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:41:21 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/28 10:42:16 by gpetit           ###   ########.fr       */
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

static int	main2(char *av1)  //RESPO INIT PARTIE GRAPHIQUE
{
	t_datas map;
	int ret;

	ret = ft_parsor(av1, &map); //CHECKER SI RET = -1;
	if (ret != -1)
		ft_display(&map);
	return (ret);
}

int main(int ac, char **av) //RESPO GESTIOn D'ERREUR
{
	int	check;
	int	fd;

	if (ac != 2)
	{
		printf("Wrong number of arguments. 1 is required.\n");
		return (0);
	}
	if (!ft_checkextension(av[1]))
	{
		printf("Wrong type of file. Only <yourfile.cub> format is accepted.\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot find file.\n");
		return (0);
	}
	close(fd);
	{
		check = main2(av[1]);
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
