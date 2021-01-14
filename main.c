/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:41:21 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/13 23:39:24 by gpetit           ###   ########.fr       */
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

int main(int ac, char **av)
{
	int check;

	if (ac != 2)
	{
		printf("Wrong number of arguments. 1 is required.\n");
		return(0);
	}
	else if (!ft_checkextension(av[1]))
	{
		printf("Wrong type of file. Only <yourfile.cub> format is accepted.\n");
		return(0);
	}
	else //RAJOUTER CONDITION PATH absolu !
	{
		*check = ft_parsor(av[1]);
		if (check == -1)
		{
			printf("Error\n");
			printf("Your <*.cub> file is not valid.\n");
			return (0);
		}
		else
			printf("Parsing en cours de codage :) ");
	}
	return (0);
}
