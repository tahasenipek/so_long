/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:28 by msenipek          #+#    #+#             */
/*   Updated: 2022/08/10 11:22:46 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extention(char *str)
{
	int		i;
	int		c;
	char	*old;

	i = 0;
	old = str;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	c = i;
	if (*--str == 'r')
		i++;
	if (*--str == 'e')
		i++;
	if (*--str == 'b')
		i++;
	if (*--str == '.')
		i++;
	if (c + 4 != i || ft_strlen(old) <= 4 || \
	(ft_strlen(old) >= 4 && *--str == '.'))
		ft_bererror();
}

void	freesomedo(t_map *map)
{
	if (map->player + map->coin + map->exit + map->onecount + \
	map->zerocount != ((map->linecount - 2) * (map->columnnbr - 2) - 1))
		map->player = 0;
	if (map->player != 1 || map->exit <= 0 || map->coin <= 0)
	{
		freelinecach(map);
		ft_printf("Error. CHAR CHECK\n");
		exit(1);
	}
}

void	sendersome(t_map *map, int i, int c)
{
	map->chardown = i * 64;
	map->charright = c * 64;
	map->player++;
}

void	ft_charchecker(t_map *map)
{
	int	i;
	int	c;

	i = 1;
	c = 1;
	while (map->line_cacher[i][c] && c != map->columnnbr - 1 \
	&& i != map->linecount - 1)
	{
		if (map->line_cacher[i][c] == 'P')
			sendersome(map, i, c);
		if (map->line_cacher[i][c] == 'C')
			map->coin++;
		if (map->line_cacher[i][c] == 'E')
			map->exit++;
		if (map->line_cacher[i][c] == '1')
			map->onecount++;
		if (map->line_cacher[i][c] == '0')
			map->zerocount++;
		c++;
		if (c == map->columnnbr - 2)
			i++;
		if (c == map->columnnbr - 2)
			c = 0;
	}
	freesomedo(map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\nArgument is error.");
		exit(1);
	}
	extention(argv[1]);
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		exit(1);
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd < 0)
	{
		free(map);
		exit(1);
	}
	counter_line(map, argv);
	foldercont(map, argv);
	ft_putmaps(map);
	ft_controller(map);
	foldercont(map, argv);
	ft_putpic(map);
}
