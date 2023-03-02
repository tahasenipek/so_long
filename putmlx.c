/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:28 by msenipek          #+#    #+#             */
/*   Updated: 2022/08/09 17:33:40 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putmaps(t_map *map)
{
	char		*totalline;
	int			i;
	int			c;
	char		*temp;
	int			line;

	c = 0;
	line = 0;
	totalline = ft_calloc(sizeof(char), ((map->columnnbr \
	* (map->linecount - 1)) + map->lastlen + 1));
	while (line++ < map->linecount)
	{
		temp = get_next_line(map->fd);
		i = 0;
		while (i != map->columnnbr)
			totalline[c++] = temp[i++];
		free(temp);
	}
	map->line_cacher = ft_split((const char *)totalline, '\n');
	if (!map->line_cacher)
	{
		free(totalline);
		freemaps(map, 3);
	}
	free(totalline);
}

void	sendsome(t_map *map, char *line, int count, int i)
{
	while (count < map->columnnbr - 2)
	{
		if (line[count] == '1')
		{
			mlx_put_image_to_window (map->mlx, map->win, \
			map->wallend, count * 64, i * 64);
		}
		if (line[count] == '0')
			mlx_put_image_to_window(map->mlx, map->win, \
			map->zerospic, count * 64, i * 64);
		if (line[count] == 'C')
			mlx_put_image_to_window(map->mlx, map->win, \
			map->target, count * 64, i * 64);
		if (line[count] == 'E')
			mlx_put_image_to_window(map->mlx, map->win, \
				map->finally, count * 64, i * 64);
		if (line[count] == 'P')
		{
			mlx_put_image_to_window(map->mlx, map->win, \
				map->brad, count * 64, i * 64);
				map->count = count;
				map->i = i;
		}
			count++;
	}
}

void	ft_putallloc(t_map *map)
{
	int		c;
	char	*line;
	int		count;
	int		i;

	i = 1;
	c = 1;
	count = 1;
	line = get_next_line(map->fd);
	while (c <= map->linecount - 2)
	{
		free(line);
		line = get_next_line(map->fd);
		sendsome(map, line, count, i);
		i++;
		count = 1;
		c++;
	}
	free(line);
	close(map->fd);
}

void	ft_putpic(t_map *map)
{
	int	i;

	i = 0;
	ft_totalmlx(map);
	ft_filecont(map);
	ft_putallloc(map);
	while (i <= map->columnnbr - 2)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->wallend, i * 64, 0);
		mlx_put_image_to_window(map->mlx, map->win, map->wallend, \
		i * 64, (map->linecount - 1) * 64);
		i++;
	}
	i = 1;
	while (i < (map->linecount - 1))
	{
		mlx_put_image_to_window(map->mlx, map->win, map->wallend, 0, i * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->wallend, \
		(map->columnnbr - 2) * 64, i * 64);
		i++;
	}
	mlx_hook(map->win, 2, 1L << 0, whtouch, map);
	mlx_hook(map->win, 17, 0, on_destroy, map);
	mlx_loop(map->mlx);
}

void	ft_controller(t_map *map)
{
	ft_first_line(map);
	lineslimits(map);
	ft_charchecker(map);
}
