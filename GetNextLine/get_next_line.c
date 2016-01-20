/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:29:18 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/20 20:55:00 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*void	*static_join(char **stock, char *buf, int fd)
{
	int	i;

	i = 0;
	stock[fd] = (char *)malloc(sizeof(char) * ft_strlen(stock[fd]) + 
			ft_strlen(buf));
	while (stock[fd][i])
		i++;
	while (buf[]
}*/

int		get_next_line(int const fd, char **line)
{
	static char **stock;
	char		buf[BUFF_SIZE + 1];
	int			i;

	if (!stock)
	{
		stock = (char **)ft_memalloc(sizeof(char *) * 100);
		stock[fd] = "";
	}
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		stock[fd] = ft_strjoin(stock[fd], buf);
		printf("stockage >> %s\n", stock[fd]);
	}
	if (i < 0 || !line)
		return (-1);
	i = 0;
	while (stock[fd][i])
	{
		if (stock[fd][i] == '\n' || stock[fd][i] == '\0')
		{
			*line = ft_strsub(stock[fd], 0, i);
			stock[fd] = ft_strsub(stock[fd], i + 1, ft_strlen(stock[fd]) - i);
			return (1);
		}
		i++;
	}
	if (i > 0)
	{
		*line = ft_strsub(stock[fd], 0, i);
		stock[fd][0] = 0;
		return (1);
	}
	return (0);
}
