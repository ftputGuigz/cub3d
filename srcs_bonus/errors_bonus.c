/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:18:23 by gpetit            #+#    #+#             */
/*   Updated: 2021/02/28 20:18:26 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	failed_reading(t_malloc *m, t_datas *map)
{
	write(1, "Error during reading.\n", 22);
	free_malloc(m);
	ft_exit(map);
}

void	failed_malloc(t_malloc *m, t_datas *map)
{
	write(1, "Malloc related issue. Aborting.\n", 32);
	free_malloc(m);
	ft_exit(map);
}
