/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenipek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:29:43 by msenipek          #+#    #+#             */
/*   Updated: 2022/04/23 16:48:46 by msenipek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *a)
{
	int	len;

	len = 0;
	while (a && a[len])
		len++;
	return (len);
}

int	has_return(char *save)
{
	int	i;

	if (!save)
		return (0);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*all;
	size_t	i;
	size_t	c;

	if (!s2)
		return (NULL);
	i = 0;
	c = 0;
	all = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!all)
		return (NULL);
	while (s1 && s1[i])
	{
		all[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[c])
		all[i++] = s2[c++];
	all[i] = '\0';
	return (all);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char	a[] = "ömer";	
	char	b[] = "senipek";

	printf("%s", ft_strjoin(a, b));
}*/
