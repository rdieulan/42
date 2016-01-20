/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:29:18 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/20 15:34:36 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int const fd, char **line)
{
	static char **stock;
	char		buf[BUFF_SIZE + 1];
	int			i;
	int			ret;

	i = 0;
	if (!line || fd < 0)
		return (-1);
	if ((ret = read(fd, buf, BUFF_SIZE) > 0))
	{
		if (!stock)
			stock = (char **)ft_memalloc(sizeof(char *) * 100);
		stock[fd] = ft_strjoin(stock[fd], buf);
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
	}
	else if (ret == 0)
	{
		*line = ft_strdup(stock[fd]);
		return (0);
	}
	else if (ret == -1)
		return (-1);
}
