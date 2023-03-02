/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:31:14 by msenipek          #+#    #+#             */
/*   Updated: 2022/04/23 16:45:03 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_mover(char *save)
{
	int		i;
	char	*s;
	int		a;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}	
	s = (char *)malloc(sizeof(char) * ft_strlen(save) - i);
	if (!s)
		return (NULL);
	i++;
	a = 0;
	while (save[i])
		s[a++] = save[i++];
	s[a] = '\0';
	free(save);
	return (s);
}

char	*ft_bestline(char *save)
{
	char	*s;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	if (!s)
		return (NULL);
	while (save[i] != '\n' && save[i])
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read_and_save(char *save, int fd)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0 && !has_return(save))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(save, fd);
	if (!save)
		return (NULL);
	line = ft_bestline(save);
	save = ft_mover(save);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int		fd;
	char	*line;
    int i;
	
    i = 0;
	fd = open("get_next_line.c", O_RDONLY);
    while( i < 50)
    {
        line = get_next_line(fd);
        printf("%s", line);
        i++;
    }
}*/
