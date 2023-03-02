/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:28 by msenipek          #+#    #+#             */
/*   Updated: 2022/08/10 10:59:43 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_first_line(t_map *map)
{
	int	i;

	i = 0;
	while (map->line_cacher[0][i] == '1')
		i++;
	if (i != map->columnnbr - 1)
	{
		freelinecach(map);
		ft_printf("Error\n.Firstline is not true.");
		exit(1);
	}
	i = 0;
	while (map->line_cacher[map->linecount - 1][i] == '1')
		i++;
	if (i != map->columnnbr - 1)
	{
		freelinecach(map);
		ft_printf("Error\n.Lastline is not true.");
		exit(1);
	}
}

void	typecontrol(t_map *map)
{
	int		i;
	char	*line;
	int		c;

	c = 0;
	i = 0;
	while (i < map->linecount - 1)
	{
		line = get_next_line(map->fd);
		c = ft_strlen(line);
		if (c == map->columnnbr)
			free(line);
		else
			freemapsget(map, line);
		i++;
	}
	line = get_next_line(map->fd);
	map->lastlen = ft_strlen(line);
	free(line);
	if (map->lastlen + 1 != map->columnnbr)
		freemaps(map, 3);
}

void	counter_line(t_map *map, char **argv)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(map->fd);
	if (!line)
		freemaps(map, 3);
	map->columnnbr = ft_strlen(line);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(map->fd);
		if (line != NULL)
			map->lastlen = ft_strlen(line);
	}
	map->linecount = i;
	foldercont(map, argv);
	typecontrol(map);
}

void	lineslimits(t_map *map)
{
	int	i;
	int	s;

	i = 1;
	s = 1;
	while (s < map->linecount - 1)
	{
		if (map->line_cacher[i][0] != '1')
		{
			freelinecach(map);
			ft_printf("Error\nLeft wall is not true.");
			exit(1);
		}
		if (map->line_cacher[i][map->columnnbr - 2] != '1')
		{
			freelinecach(map);
			ft_printf("Error\nRight wall is not true.");
			exit(1);
		}
		i++;
		s++;
	}
}

int	whtouch(int keycode, void *map)
{
	t_map	*a;

	a = map;
	if (keycode == 2)
		key_press_r(map);
	if (keycode == 13)
		key_press_u(a);
	if (keycode == 1)
		key_press_d(a);
	if (keycode == 0)
		key_press_l(a);
	if (keycode == 53)
		freemapsmlx(a);
	return (0);
}
