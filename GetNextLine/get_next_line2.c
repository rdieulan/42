/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:13:47 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/20 18:40:58 by rdieulan         ###   ########.fr       */
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
	while (stock[fd])
	{
		if (stock[fd][i] == '\n' || stock[fd][i] == '\0')
		{
			*line = ft_strsub(stock[fd], 0 , i);
			stock[fd] = ft_strsub(stock[fd], i + 1, ft_strlen(stock[fd]) - i);
			return (1);
		}
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			
		}
	}
	else
}
