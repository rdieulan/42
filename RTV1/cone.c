/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:48:52 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 02:51:54 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	inter_cone(t_obj *obj, t_vec dist, t_vec raydir)
{
	float	disc[6];
	t_vec	tmp;

	tmp = sub_vec(multiply_vec(obj->dir, dot(raydir, obj->dir)), raydir);
	disc[0] = pow(cos(obj->angle), 2) * dot(tmp, tmp)
		- pow(sin(obj->angle), 2) * pow(dot(raydir, obj->dir), 2);
	disc[1] = 2.0 * pow(cos(obj->angle), 2) * dot(sub_vec(raydir,
	multiply_vec(obj->dir, dot(raydir, obj->dir))), sub_vec(dist,
	multiply_vec(obj->dir, dot(dist, obj->dir)))) - 2.0 * pow(sin(obj->angle),
	2) * dot(raydir, obj->dir) * dot(dist, obj->dir);
	tmp = sub_vec(dist, multiply_vec(obj->dir, dot(dist, obj->dir)));
	disc[2] = pow(cos(obj->angle), 2) * dot(tmp, tmp) - (sin(obj->angle)
			* sin(obj->angle)) * pow(dot(dist, obj->dir), 2);
	disc[3] = (disc[1] * disc[1]) - (4 * disc[0] * disc[2]);
	if (disc[3] < 0)
		return (MAX_FLOAT);
	if (disc[3] == 0)
		disc[4] = -disc[1] / (2 * disc[0]);
	if (disc[3] > 0)
	{
		disc[4] = (-disc[1] + sqrtf(disc[3])) / (2 * disc[0]);
		disc[5] = (-disc[1] - sqrtf(disc[3])) / (2 * disc[0]);
		disc[4] = (disc[4] < disc[5]) ? disc[4] : disc[5];
	}
	return (disc[4]);
}
