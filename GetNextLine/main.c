/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:57:05 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/20 15:34:39 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		while (get_next_line(fd, &line))
			printf("sortie ligne : %d : %s\n", i++, line);
	}
	else if (argc == 1)
	{
		while (get_next_line(0, &line))
		{
			ft_putstr(line);
		}
	}
	return (0);
}
