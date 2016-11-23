/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:12:35 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 06:12:19 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	find_obj(int fd, char *line, t_env *e)
{
	if (ft_strstr(line, "CAM:") != NULL)
		parse_camera(e, fd, line);
	if (ft_strstr(line, "SPH:") != NULL)
		parse_sphere(e, fd, line);
	if (ft_strstr(line, "PLA:") != NULL)
		parse_plan(e, fd, line);
	if (ft_strstr(line, "CON:") != NULL)
		parse_cone(e, fd, line, 0);
	if (ft_strstr(line, "CYL:") != NULL)
		parse_cyl(e, fd, line, 0);
	if (ft_strstr(line, "SPOT:") != NULL)
		parse_light(e, fd, line);
	free(line);
}

void	init_obj(char *file, t_env *e)
{
	int		fd;
	char	*line;
	int		ret;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			e->secu = 0;
			ft_isascii(line[0]) == 1 ? 0 : exit(1);
			find_obj(fd, line, e);
		}
		if (!line || !line[0] || ret < 0)
			exit(1);
	}
	else
		exit(0);
}

void	add_object(t_env *e, t_obj *obj)
{
	t_obj	*tmp;

	tmp = e->obj;
	obj->id = e->oid;
	if (e->oid == 0)
	{
		e->obj = obj;
		obj->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
		obj->next = NULL;
	}
	e->oid++;
}
