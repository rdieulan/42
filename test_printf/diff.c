/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:37:26 by rdieulan          #+#    #+#             */
/*   Updated: 2016/02/15 18:06:34 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/libft/includes/libft.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		ret;
	int		buff_size;
	char	*str1;
	char	*str2;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * buff_size);
	buff_size = 100;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);

	while ((ret = read(fd1, buf, buff_size)))
	{
		str1 = ft_strjoin(str1, ft_strsub(buf, 0, buff_size));
		buf = ft_memset(buf, '\0', buff_size);
	}
	while ((ret = read(fd2, buf, buff_size)))
	{
		str2 = ft_strjoin(str2, ft_strsub(buf, 0, buff_size));
		buf = ft_memset(buf, '\0', buff_size);
	}
	if (ft_strcmp(str1, str2) == 0)
		ft_putstr("OK");
	else
		ft_putstr("ERROR");
	return (0);
}
