/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:13:47 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/20 17:18:59 by rdieulan         ###   ########.fr       */
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

	if (!line || fd < 0)
		return (-1);
	if (!stock)
		stock = (char **)ft_memalloc(sizeof(char *) * 100);
	if (!stock[fd])
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			
		}
	}
	else
}
