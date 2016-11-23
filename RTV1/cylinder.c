/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:48:39 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 02:48:42 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	inter_cylinder(t_obj *obj, t_vec dist, t_vec raydir)
{
	float	disc[6];
	t_vec	tmp;

	tmp = sub_vec(raydir, multiply_vec(obj->dir, dot(raydir, obj->dir)));
	disc[0] = dot(tmp, tmp);
	disc[1] = 2 * dot(sub_vec(raydir, multiply_vec(obj->dir,
					dot(raydir, obj->dir))), sub_vec(dist,
				multiply_vec(obj->dir, dot(dist, obj->dir))));
	tmp = sub_vec(dist, multiply_vec(obj->dir, dot(dist, obj->dir)));
	disc[2] = dot(tmp, tmp) - (obj->rayon * obj->rayon);
	if ((disc[3] = disc[1] * disc[1] - 4 * disc[0] * disc[2]) < 0)
		return (MAX_FLOAT);
	if (disc[3] == 0)
		disc[4] = -disc[1] / (2 * disc[0]);
	else if (disc[3] > 0.0)
	{
		disc[4] = (-disc[1] + sqrtf(disc[3])) / (2 * disc[0]);
		disc[5] = (-disc[1] - sqrtf(disc[3])) / (2 * disc[0]);
		disc[4] = (disc[4] < disc[5]) ? disc[4] : disc[5];
	}
	return (disc[4]);
}
