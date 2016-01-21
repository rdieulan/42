/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:29:18 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/21 19:26:42 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int const fd, char **line)
{
	static char **stock;
	char		*buf;
	int			i;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buf)
		return (-1);
	if (!stock)
	{
		stock = (char **)ft_memalloc(sizeof(char *) * 100);
		if (!stock)
			return (-1);
	}
	if (!stock[fd])
		stock[fd] = "";
	while ((ret = read(fd, buf, BUFF_SIZE)) > -1)
	{
		if (ret > 0)
		{
			stock[fd] = ft_strjoin(stock[fd], ft_strsub(buf, 0 ,BUFF_SIZE));
			buf = ft_memset(buf, '\0', BUFF_SIZE);
		}
		if (ret == 0 && stock[fd][0] == 0)
			return (0);
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
		if (i > 0 && ret == 0)
		{
			*line = ft_strsub(stock[fd], 0, i);
			stock[fd][0] = 0;
			return (1);
		}
	}
	if (ret == -1)
		return (-1);
	return (0);
}
