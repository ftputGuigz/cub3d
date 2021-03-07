/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:41:21 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/24 15:37:42 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_checkextension(char *str)
{
	int z;

	z = ft_strlen(str);
	if (z >= 4 && str[z - 1] == 'b' && str[z - 2] == 'u' && str[z - 3] == 'c' &&
	str[z - 4] == '.')
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

static void	check_args(int ac, char **av)
{
	if (ac == 2 || ac == 3)
	{
		if (!ft_checkextension(av[1]))
		{
			printf("Wrong type of file. ");
			printf("Only [yourfile.cub] format is accepted.\n");
			exit(0);
		}
		if (ac == 3 && flag_check(av[2]))
		{
			printf("Wrong argument. ");
			printf("Only ./cub3D [yourmap.cub] --save is accepted.\n");
			exit(0);
		}
	}
	else
	{
		printf("Wrong number of arguments. 1 is required.\n");
		exit(0);
	}
}

static int	main2(int ac, char *av1, t_datas *map)
{
	int		ret;

	initialize_struct(map);
	if (ac == 3)
		map->bmp = 1;
	ret = ft_parsor(av1, map);
	if (ret == -1)
		return (ret);
	map->mlx.ptr = mlx_init();
	screen_size(map);
	ret = ft_display(map);
	return (ret);
}

int			main(int ac, char **av)
{
	t_datas map;
	int		check;
	int		fd;
	char	buff[2];

	check_args(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || read(fd, buff, 1) < 0)
	{
		printf("Cannot find file.\n");
		if (fd != -1)
			close(fd);
		return (0);
	}
	close(fd);
	check = main2(ac, av[1], &map);
	if (check == -1)
	{
		printf("Error\n");
		printf("Your <*.cub> file is not valid.\n");
		ft_exit(&map);
	}
	else
		printf("Too Far.");
	return (0);
}
