/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:41:21 by gpetit            #+#    #+#             */
/*   Updated: 2021/01/19 16:58:59 by gpetit           ###   ########.fr       */
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
	t_datas map_datas;
	
	t_mlx mlx;
	t_img minimap;

	int ret;

	ret = ft_parsor(av1, &map_datas);
	mlx.ptr = mlx_init();
	mlx.wdw = mlx_new_window(mlx.ptr, map_datas.res_x, map_datas.res_y, "Guigz's Cub3d");
	minimap.img = mlx_new_image(mlx.ptr, map_datas.res_x, map_datas.res_y);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel, &minimap.line_length, &minimap.endian);
	mlx_loop (mlx.ptr);
	return (ret);
}

int main(int ac, char **av) //RESPO GESTIOn D'ERREUR
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
