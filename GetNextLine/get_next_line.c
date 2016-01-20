/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:29:18 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/20 17:19:04 by rdieulan         ###   ########.fr       */
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
	if (!stock)
		stock = (char **)ft_memalloc(sizeof(char *) * 100);
	while ((ret = read(fd, buf, BUFF_SIZE)) > -1)
	{
		printf("ret1 = %d\n", ret);
		stock[fd] = ft_strjoin(stock[fd], buf);
		while (stock[fd][i])
		{
			if (stock[fd][i] == '\n' || stock[fd][i] == '\0')
			{
				*line = ft_strsub(stock[fd], 0, i);
				stock[fd] = ft_strsub(stock[fd], i + 1, ft_strlen(stock[fd]) - i);
				printf("stock[fd] = %s\n", stock[fd]);
				return (1);
			}
			i++;
		}
	}
	if (ret == -1)
	{
		printf("ret2 = %d\n", ret);
		return (-1);
	}
	printf("ret3 = %d\n", ret);
	printf("stock[fd] = %s\n", stock[fd]);
	if (!stock[fd])
		return (0);
	else
	{
		*line = ft_strdup(stock[fd]);
		return (1);
	}
}
