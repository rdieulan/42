/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:29:18 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/22 19:23:51 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		display(char **stk, char **line, int fd, int i)
{
	*line = ft_strsub(stk[fd], 0, i);
	stk[fd] = ft_strsub(stk[fd], i + 1, ft_strlen(stk[fd]) - i);
	return (1);
}

int		display_last(char **stk, char **line, int fd, int i)
{
	*line = ft_strsub(stk[fd], 0, i);
	stk[fd][0] = 0;
	ft_strdel(&stk[fd]);
	return (1);
}

int		reading(char **stk, char *buf, char **line, int fd)
{
	int	i;
	int	ret;

	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > -1)
	{
		if (ret > 0)
		{
			stk[fd] = ft_strjoin(stk[fd], ft_strsub(buf, 0, BUFF_SIZE));
			buf = ft_memset(buf, '\0', BUFF_SIZE);
		}
		if (ret == 0 && stk[fd][0] == 0)
			return (0);
		while (stk[fd][i])
		{
			if (stk[fd][i] == '\n' || stk[fd][i] == '\0')
				return (display(stk, line, fd, i));
			i++;
		}
		if (i > 0 && ret == 0)
			return (display_last(stk, line, fd, i));
	}
	return (2);
}

int		get_next_line(int const fd, char **line)
{
	static char **stk;
	char		*buf;
	int			i;

	if (fd < 0 || !line)
		return (-1);
	buf = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buf)
		return (-1);
	if (!stk)
	{
		stk = (char **)ft_memalloc(sizeof(char *) * 100);
		if (!stk)
			return (-1);
	}
	if (!stk[fd])
		stk[fd] = "";
	if ((i = reading(stk, buf, line, fd)) != 2)
		return (i);
	ft_strdel(&buf);
	return (-1);
}
