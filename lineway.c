/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineway.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:11:28 by msenipek          #+#    #+#             */
/*   Updated: 2022/08/10 11:26:35 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_totalmlx(t_map *map)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, (map->columnnbr - 1) * 64, \
	map->linecount * 64, "so_long");
	map->brad = mlx_xpm_file_to_image(map->mlx, "tesla.xpm", &w, &h);
	map->wallend = mlx_xpm_file_to_image(map->mlx, "build.xpm", &w, &h);
	map->target = mlx_xpm_file_to_image(map->mlx, "people.xpm", &w, &h);
	map->finally = mlx_xpm_file_to_image(map->mlx, "target.xpm", &w, &h);
	map->zerospic = mlx_xpm_file_to_image(map->mlx, "road.xpm", &w, &h);
}

void	key_press_r(t_map *a)
{
	if (a->line_cacher[a->i][a->count + 1] != '1')
	{
		if (a->line_cacher[a->i][a->count + 1] == 'C')
		{
			ft_printf("%d KM\n", ++a->step);
			mlx_put_image_to_window(a->mlx, a->win, \
			a->zerospic, a->count * 64, a->i * 64);
			a->line_cacher[a->i][a->count + 1] = '0';
			a->line_cacher[a->i][a->count] = '0';
			mlx_put_image_to_window(a->mlx, a->win, \
			a->brad, ++a->count * 64, a->i * 64);
			a->coin--;
		}
		else if (a->line_cacher[a->i][a->count + 1] == '0')
		{
			ft_printf("%d KM\n", ++a->step);
			a->line_cacher[a->i][a->count] = '0';
			mlx_put_image_to_window(a->mlx, a->win, \
			a->zerospic, a->count * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, \
			a->brad, ++a->count * 64, a->i * 64);
		}
		else if (a->line_cacher[a->i][a->count + 1] == 'E' && a->coin == 0)
			freemapsmlx0(a);
	}
}

void	key_press_u(t_map *a)
{
	if (a->line_cacher[a->i - 1][a->count] != '1')
	{
		if (a->line_cacher[a->i - 1][a->count] == 'C')
		{
			ft_printf("%d KM\n", ++a->step);
			mlx_put_image_to_window(a->mlx, a->win, \
			a->zerospic, a->count * 64, a->i * 64);
			a->line_cacher[a->i - 1][a->count] = '0';
			a->line_cacher[a->i][a->count] = '0';
			mlx_put_image_to_window(a->mlx, a->win, \
			a->brad, a->count * 64, --a->i * 64);
			a->coin--;
		}
		else if (a->line_cacher[a->i - 1][a->count] == '0')
		{
			ft_printf("%d KM\n", ++a->step);
			a->line_cacher[a->i][a->count] = '0';
			mlx_put_image_to_window(a->mlx, a->win, \
			a->zerospic, a->count * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, \
			a->brad, a->count * 64, --a->i * 64);
		}
		else if (a->line_cacher[a->i - 1][a->count] == 'E' && a->coin == 0)
			freemapsmlx0(a);
	}
}

void	key_press_d(t_map *a)
{
	if (a->line_cacher[a->i + 1][a->count] != '1')
	{
		if (a->line_cacher[a->i + 1][a->count] == 'C')
		{
			ft_printf("%d KM\n", ++a->step);
			mlx_put_image_to_window(a->mlx, a->win, \
			a->zerospic, a->count * 64, a->i * 64);
			a->line_cacher[a->i + 1][a->count] = '0';
			a->line_cacher[a->i][a->count] = '0';
			mlx_put_image_to_window(a->mlx, a->win, \
			a->brad, a->count * 64, ++a->i * 64);
			a->coin--;
		}
		else if (a->line_cacher[a->i + 1][a->count] == '0')
		{
			ft_printf("%d KM\n", ++a->step);
			a->line_cacher[a->i][a->count] = '0';
			mlx_put_image_to_window(a->mlx, a->win, \
			a->zerospic, a->count * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, \
			a->brad, a->count * 64, ++a->i * 64);
		}
		else if (a->line_cacher[a->i + 1][a->count] == 'E' && a->coin == 0)
			freemapsmlx0(a);
	}
}

void	key_press_l(t_map *a)
{
	if (a->line_cacher[a->i][a->count - 1] != '1')
	{
		if (a->line_cacher[a->i][a->count - 1] == 'C')
		{
			ft_printf("%d KM\n", ++a->step);
			mlx_put_image_to_window(a->mlx, a->win, a->zerospic, \
			a->count * 64, a->i * 64);
			a->line_cacher[a->i][a->count - 1] = '0';
			a->line_cacher[a->i][a->count] = '0';
			mlx_put_image_to_window(a->mlx, a->win, a->brad, \
			--a->count * 64, a->i * 64);
			a->coin--;
		}
		else if (a->line_cacher[a->i][a->count - 1] == '0')
		{
			ft_printf("%d KM\n", ++a->step);
			a->line_cacher[a->i][a->count] = '0';
			mlx_put_image_to_window(a->mlx, a->win, a->zerospic, \
			a->count * 64, a->i * 64);
			mlx_put_image_to_window(a->mlx, a->win, a->brad, \
			--a->count * 64, a->i * 64);
		}
		else if (a->line_cacher[a->i][a->count - 1] == 'E' && a->coin == 0)
			freemapsmlx0(a);
	}
}
