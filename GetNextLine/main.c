/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:57:05 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/21 19:13:00 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*int			main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		if (get_next_line(fd, &line))
			printf("affichage : %s\n", line);
	}
	else if (argc == 1)
	{
		while (get_next_line(0, &line))
		{
			ft_putstr(line);
		}
	}
	return (0);
}*/

int				main(int argc, char **argv)
{
	int			fd1;
	int			fd2;
	char		*line;

	if (argc)
		;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);

	if (get_next_line(fd1, &line))
		printf("fd%d : %s\n", fd1, line);
	if (get_next_line(fd2, &line))
		printf("fd%d : %s\n", fd2, line);
	if (get_next_line(fd1, &line))
		printf("fd%d : %s\n", fd1, line);
	if (get_next_line(fd2, &line))
		printf("fd%d : %s\n", fd2, line);
	return (0);
}
