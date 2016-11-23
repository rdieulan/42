/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:12:35 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 02:50:22 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_obj(char *file, t_env *e)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (get_next_line(fd, &line) > 0)
	{
		printf("\n");
		if (ft_strstr(line, "CAM:") != NULL)
			parse_camera(e, fd);
		if (ft_strstr(line, "SPH:") != NULL)
			parse_sphere(e, fd);
		if (ft_strstr(line, "PLA:") != NULL)
			parse_plan(e, fd);
		if (ft_strstr(line, "CON:") != NULL)
			parse_cone(e, fd);
		if (ft_strstr(line, "CYL:") != NULL)
			parse_cyl(e, fd);
		if (ft_strstr(line, "SPOT:") != NULL)
			parse_light(e, fd);
	}
	printf("OBJECTS INITIALIZED.\n");
}

void	add_object(t_env *e, t_obj *obj)
{
	t_obj	*tmp;

	tmp = e->obj;
	obj->id = e->oid;
	printf("start adding object\n");
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
	printf("object ADDED : ID = %d\n", e->oid);
	e->oid++;
}
