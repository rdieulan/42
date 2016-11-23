/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 03:21:55 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 03:25:02 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_camera(t_env *e, int fd)
{
	char	*line;
	char	**tmp;
	int		i;

	i = 0;
	line = NULL;
	while (i < 2)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (ft_strstr(tmp[0], "\tPOS") != NULL)
		{
			e->cam_pos.x = ft_atoi(tmp[1]);
			e->cam_pos.y = ft_atoi(tmp[2]);
			e->cam_pos.z = ft_atoi(tmp[3]);
		}
		if (ft_strstr(tmp[0], "\tANG") != NULL)
		{
			e->h_angle = ft_atoi(tmp[1]);
			e->v_angle = ft_atoi(tmp[2]);
		}
		i++;
	}
}
