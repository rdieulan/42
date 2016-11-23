/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:48:15 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 05:23:09 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	cast_ray(t_obj *tmp, t_vec raydir, t_vec dist)
{
	float t;

	t = MAX_FLOAT;
	if (tmp->type == CONE)
		t = inter_cone(tmp, dist, raydir);
	else if (tmp->type == PLANE)
		t = inter_plane(tmp, dist, raydir);
	else if (tmp->type == SPHERE)
		t = inter_sphere(tmp, dist, raydir);
	else
		t = inter_cylinder(tmp, dist, raydir);
	return (t);
}

void	apply_vector(t_env *e, t_vec raydir, int x, int y)
{
	t_obj	*tmp;
	t_obj	*result;
	float	value;
	float	min;
	t_color	color;

	min = MAX_FLOAT;
	tmp = e->obj;
	while (tmp)
	{
		value = cast_ray(tmp, raydir, sub_vec(e->cam_pos, tmp->pos));
		if (value < min && value >= 0)
		{
			min = value;
			result = tmp;
		}
		tmp = tmp->next;
	}
	if (min != MAX_FLOAT)
	{
		color = result->color;
		color = shadow(get_inters(e->cam_pos, raydir, min), e, color, result);
		draw(e, x, y, color);
	}
}

void	ray_tracing(t_env *e)
{
	int		x;
	int		y;
	t_vec	raydir;

	x = 0;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			raydir.z = (WIN_H / (2 * tan((float)FOV / 2)));
			raydir.x = x - (WIN_W / 2);
			raydir.y = y - (WIN_H / 2);
			raydir = rot(raydir, e->h_angle, e->v_angle);
			apply_vector(e, normalize(raydir), x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->graph->ptr, e->graph->win, e->graph->img, 0, 0);
	mlx_hook(e->graph->win, 2, 1L << 0, key_hooker, e);
	mlx_hook(e->graph->win, 17, (1L << 17), red_cross, e);
	mlx_loop(e->graph->ptr);
}
