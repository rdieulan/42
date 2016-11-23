/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:02:01 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 03:21:18 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	project(t_vec a, t_vec b)
{
	double t;

	t = dot(b, b);
	if (t)
		return (multiply_vec(b, ((dot(a, b)) / (t))));
	return (a);
}

float	get_normale(t_obj *obj, t_vec raydir)
{
	if (obj->type == SPHERE)
	{
		obj->normale = normalize(sub_vec(obj->inters, obj->pos));
		return (dot(obj->normale, raydir));
	}
	else if (obj->type == CONE || obj->type == CYL)
	{
		obj->normale = normalize(sub_vec(sub_vec(obj->inters, obj->pos),
		project(sub_vec(obj->inters, obj->pos), obj->dir)));
		return (dot(obj->normale, raydir));
	}
	else
	{
		obj->normale = not_vec(obj->dir);
		return (dot(obj->normale, raydir));
	}
}

t_color	lambert(t_color result, t_vec raydir, t_obj *obj)
{
	float	dot;
	t_color	tmp;

	tmp = result;
	dot = get_normale(obj, not_vec(raydir));
	dot = fmax(0, -dot);
	tmp.r *= dot;
	tmp.g *= dot;
	tmp.b *= dot;
	if (tmp.r > result.r)
		tmp.r = result.r;
	if (tmp.g > result.g)
		tmp.g = result.g;
	if (tmp.b > result.b)
		tmp.b = result.b;
	if (tmp.r < result.r * 0.3)
		tmp.r = result.r * 0.3;
	if (tmp.g < result.g * 0.3)
		tmp.g = result.g * 0.3;
	if (tmp.b < result.b * 0.3)
		tmp.b = result.b * 0.3;
	return (tmp);
}

t_color	color_mod(t_color result)
{
	result.r *= 0.3;
	result.g *= 0.3;
	result.b *= 0.3;
	return (result);
}

t_color	shadow(t_vec impact, t_env *e, t_color result, t_obj *obj)
{
	t_vec	raydir;
	t_obj	*tmp;
	float	val;
	float	dist;

	val = 0;
	tmp = e->obj;
	obj->inters = impact;
	dist = get_dist(sub_vec(e->sp_pos, impact));
	raydir = normalize(sub_vec(e->sp_pos, impact));
	while (tmp)
	{
		if (tmp->id != obj->id)
		{
			val = cast_ray(tmp, not_vec(raydir), sub_vec(e->sp_pos, tmp->pos));
			if (val != MAX_FLOAT && val > 0)
			{
				tmp->inters = get_inters(e->sp_pos, raydir, val);
				if (get_dist(sub_vec(e->sp_pos, tmp->inters)) < dist)
					return (color_mod(result));
			}
		}
		tmp = tmp->next;
	}
	return (lambert(result, raydir, obj));
}
