/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefunc1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:28 by msenipek          #+#    #+#             */
/*   Updated: 2022/08/09 18:22:12 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_map *map)
{
	freemapsmlx(map);
	return (0);
}

void	ft_filecont(t_map *map)
{
	if (!(map->brad) || !(map->win) || \
	!(map->mlx) || !(map->wallend) || !(map->target) || !(map->zerospic) || \
	!(map->finally))
	{
		ft_printf("Error\nThere is not XPM file.");
		freemapsmlx(map);
	}
}

void	foldercont(t_map *map, char **argv)
{
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
}

void	freemapsget(t_map *map, char *line)
{
	free(line);
	ft_printf("Error\nGet_next_line function returned NULL or\n\
	The map is wrong.\n");
	earlyfree(map);
}

void	ft_bererror(void)
{
	ft_printf("Error\nBer Error..");
	exit(1);
}
