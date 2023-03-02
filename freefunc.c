/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:28 by msenipek          #+#    #+#             */
/*   Updated: 2022/08/10 11:27:43 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freelinecach(t_map *map)
{
	int	i;

	i = 0;
	while (map->line_cacher && map->line_cacher[i])
	{
		free(map->line_cacher[i]);
		i++;
	}
	free(map->line_cacher);
	free(map);
}

void	freemapsmlx(t_map *map)
{
	int	i;

	i = 0;
	while (map->line_cacher && map->line_cacher[i] != NULL)
		free(map->line_cacher[i++]);
	free(map->line_cacher);
	if (map->zerospic)
		mlx_destroy_image(map->mlx, map->zerospic);
	if (map->finally)
		mlx_destroy_image(map->mlx, map->finally);
	if (map->target)
		mlx_destroy_image(map->mlx, map->target);
	if (map->wallend)
		mlx_destroy_image(map->mlx, map->wallend);
	if (map->brad)
		mlx_destroy_image(map->mlx, map->brad);
	mlx_destroy_window(map->mlx, map->win);
	mlx_clear_window(map->mlx, map->win);
	close(map->fd);
	exit(1);
}

void	freemapsmlx0(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("%d KM\n", ++map->step);
	while (map->line_cacher && map->line_cacher[i] != NULL)
		free(map->line_cacher[i++]);
	free(map->line_cacher);
	if (map->zerospic)
		mlx_destroy_image(map->mlx, map->zerospic);
	if (map->finally)
		mlx_destroy_image(map->mlx, map->finally);
	if (map->target)
		mlx_destroy_image(map->mlx, map->target);
	if (map->wallend)
		mlx_destroy_image(map->mlx, map->wallend);
	if (map->brad)
		mlx_destroy_image(map->mlx, map->brad);
	mlx_destroy_window(map->mlx, map->win);
	mlx_clear_window(map->mlx, map->win);
	close(map->fd);
	exit(0);
}

void	earlyfree(t_map *map)
{
	free(map);
	close(map->fd);
	exit(1);
}

void	freemaps(t_map *map, int i)
{
	if (i == 3)
	{
		ft_printf("Error\nGet_next_line function returned NULL or\n\
		The map is wrong.\n");
		earlyfree(map);
	}	
}
