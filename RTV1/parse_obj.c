/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:45:18 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 03:28:26 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parse_sphere(t_env *e, int fd)
{
	t_obj	*obj;
	int		i;
	char	*line;
	char	**tmp;

	line = NULL;
	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = SPHERE;
	i = 0;
	while (i < 3)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (ft_strstr(tmp[0], "\tPOS") != NULL)
			get_pos(obj, tmp);
		if (ft_strstr(tmp[0], "\tRAY") != NULL)
			obj->rayon = ft_atoi(tmp[1]);
		if (ft_strstr(tmp[0], "\tCOL") != NULL)
			get_color(obj, tmp);
		i++;
	}
	add_object(e, obj);
}

void		parse_plan(t_env *e, int fd)
{
	t_obj	*obj;
	int		i;
	char	*line;
	char	**tmp;

	line = NULL;
	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = PLANE;
	i = 0;
	while (i < 3)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (ft_strstr(tmp[0], "\tPOS") != NULL)
			get_pos(obj, tmp);
		if (ft_strstr(tmp[0], "\tDIR") != NULL)
			get_dir(obj, tmp);
		if (ft_strstr(tmp[0], "\tCOL") != NULL)
			get_color(obj, tmp);
		i++;
	}
	add_object(e, obj);
}

void		parse_cone(t_env *e, int fd)
{
	t_obj	*obj;
	int		i;
	char	*line;
	char	**tmp;

	line = NULL;
	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = CONE;
	i = 0;
	while (i < 4)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (ft_strstr(tmp[0], "\tPOS") != NULL)
			get_pos(obj, tmp);
		if (ft_strstr(tmp[0], "\tDIR") != NULL)
			get_dir(obj, tmp);
		if (ft_strstr(tmp[0], "\tANG") != NULL)
			obj->angle = ft_atoi(tmp[1]);
		if (ft_strstr(tmp[0], "\tCOL") != NULL)
			get_color(obj, tmp);
		i++;
	}
	add_object(e, obj);
}

void		parse_cyl(t_env *e, int fd)
{
	t_obj	*obj;
	int		i;
	char	*line;
	char	**tmp;

	line = NULL;
	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = CYL;
	i = 0;
	while (i < 4)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (ft_strstr(tmp[0], "\tPOS") != NULL)
			get_pos(obj, tmp);
		if (ft_strstr(tmp[0], "\tRAY") != NULL)
			obj->rayon = ft_atoi(tmp[1]);
		if (ft_strstr(tmp[0], "\tDIR") != NULL)
			get_dir(obj, tmp);
		if (ft_strstr(tmp[0], "\tCOL") != NULL)
			get_color(obj, tmp);
		i++;
	}
	add_object(e, obj);
}

void		parse_light(t_env *e, int fd)
{
	t_obj	*obj;
	char	*line;
	char	**tmp;

	line = NULL;
	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = SPOT;
	get_next_line(fd, &line);
	tmp = ft_strsplit(line, ':');
	if (ft_strstr(tmp[0], "\tPOS") != NULL)
	{
		e->sp_pos.x = ft_atoi(tmp[1]);
		e->sp_pos.y = ft_atoi(tmp[2]);
		e->sp_pos.z = ft_atoi(tmp[3]);
	}
}
