/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:45:18 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 06:12:04 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parse_sphere(t_env *e, int fd, char *line)
{
	t_obj	*obj;
	int		i;
	char	**tmp;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = SPHERE;
	i = 0;
	while (i < 3)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (line[0])
		{
			if (ft_strstr(tmp[0], "\tPOS") != NULL)
				get_pos(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tRAY") != NULL)
				get_rayon(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tCOL") != NULL)
				get_color(obj, tmp, e);
			i++;
		}
	}
	ft_freecarray_2d(tmp, 3);
	e->secu == 3 ? 0 : exit(1);
	add_object(e, obj);
}

void		parse_plan(t_env *e, int fd, char *line)
{
	t_obj	*obj;
	int		i;
	char	**tmp;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = PLANE;
	i = 0;
	while (i < 3)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (line[0])
		{
			if (ft_strstr(tmp[0], "\tPOS") != NULL)
				get_pos(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tDIR") != NULL)
				get_dir(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tCOL") != NULL)
				get_color(obj, tmp, e);
			i++;
		}
	}
	ft_freecarray_2d(tmp, 3);
	e->secu == 3 ? 0 : exit(1);
	add_object(e, obj);
}

void		parse_cone(t_env *e, int fd, char *line, int i)
{
	t_obj	*obj;
	char	**tmp;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = CONE;
	while (i < 4)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (line[0])
		{
			if (ft_strstr(tmp[0], "\tPOS") != NULL)
				get_pos(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tDIR") != NULL)
				get_dir(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tANG") != NULL)
				get_angle(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tCOL") != NULL)
				get_color(obj, tmp, e);
			i++;
		}
	}
	e->secu == 4 ? 0 : exit(1);
	add_object(e, obj);
	ft_freecarray_2d(tmp, 4);
}

void		parse_cyl(t_env *e, int fd, char *line, int i)
{
	t_obj	*obj;
	char	**tmp;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = CYL;
	while (i < 4)
	{
		get_next_line(fd, &line);
		tmp = ft_strsplit(line, ':');
		if (line[0])
		{
			if (ft_strstr(tmp[0], "\tPOS") != NULL)
				get_pos(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tRAY") != NULL)
				get_rayon(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tDIR") != NULL)
				get_dir(obj, tmp, e);
			if (ft_strstr(tmp[0], "\tCOL") != NULL)
				get_color(obj, tmp, e);
			i++;
		}
	}
	e->secu == 4 ? 0 : exit(1);
	add_object(e, obj);
	ft_freecarray_2d(tmp, 4);
}

void		parse_light(t_env *e, int fd, char *line)
{
	t_obj	*obj;
	char	**tmp;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->type = SPOT;
	get_next_line(fd, &line);
	tmp = ft_strsplit(line, ':');
	if (line[0])
	{
		if (ft_strstr(tmp[0], "\tPOS") != NULL)
		{
			if (tmp[1] && tmp[2] && tmp[3])
			{
				e->sp_pos.x = ft_atoi(tmp[1]);
				e->sp_pos.y = ft_atoi(tmp[2]);
				e->sp_pos.z = ft_atoi(tmp[3]);
				e->secu++;
			}
		}
	}
	e->secu == 1 ? 0 : exit(1);
	ft_freecarray_2d(tmp, 1);
}
