/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 03:21:55 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 06:09:20 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_cam_pos(char **param, t_env *e)
{
	if (param[1] && param[2] && param[3])
	{
		e->cam_pos.x = ft_atoi(param[1]);
		e->cam_pos.y = ft_atoi(param[2]);
		e->cam_pos.z = ft_atoi(param[3]);
		e->secu++;
	}
}

void	get_cam_angle(char **param, t_env *e)
{
	if (param[1] && param[2])
	{
		e->h_angle = ft_atoi(param[1]);
		e->v_angle = ft_atoi(param[2]);
		e->secu++;
	}
}

void	parse_camera(t_env *e, int fd, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	while (i < 2)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (line[0])
		{
			if (ft_strstr(tmp[0], "\tPOS") != NULL)
				get_cam_pos(tmp, e);
			if (ft_strstr(tmp[0], "\tANG") != NULL)
				get_cam_angle(tmp, e);
			i++;
		}
	}
	ft_freecarray_2d(tmp, 2);
	e->secu == 2 ? 0 : exit(1);
}
