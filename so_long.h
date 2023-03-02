/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <msenipek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:53:44 by msenipek          #+#    #+#             */
/*   Updated: 2022/08/09 18:22:57 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define    SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdio.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct s_map
{
	int		fd;
	int		lastlen;
	int		linecount;
	char	**line_cacher;
	int		columnnbr;
	int		countdown;
	int		player;
	int		coin;
	int		exit;
	int		ft_count;
	int		step;
	int		zerocount;
	int		onecount;
	int		count;
	int		i;
	void	*mlx;
	void	*brad;
	void	*win;
	int		charright;
	int		chardown;
	void	*wallend;
	void	*target;
	void	*finally;
	void	*zerospic;
}	t_map;

size_t	ft_strlengnl(const char *a);
int		has_return(char *save);
char	*ft_strjoingnl(char *s1, const char *s2);
char	*get_next_line(int fd);
void	freelinecach(t_map *map);
void	freemapsmlx(t_map *map);
void	earlyfree(t_map *map);
void	freemapsget(t_map *map, char *line);
void	freemaps(t_map *map, int i);
void	ft_first_line(t_map *map);
void	typecontrol(t_map *map);
void	counter_line(t_map *map, char **argv);
void	lineslimits(t_map *map);
void	ft_putmaps(t_map *map);
void	ft_totalmlx(t_map *map);
void	freemapsmlx0(t_map *map);
void	key_press_r(t_map *a);
void	key_press_u(t_map *a);
void	key_press_d(t_map *a);
void	key_press_l(t_map *a);
int		whtouch(int keycode, void *map);
void	ft_putallloc(t_map *map);
int		on_destroy(t_map *map);
void	ft_filecont(t_map *map);
void	ft_putpic(t_map *map);
void	ft_charchecker(t_map *map);
void	ft_controller(t_map *map);
void	ft_bererror(void);
void	foldercont(t_map *map, char **argv);

#endif
