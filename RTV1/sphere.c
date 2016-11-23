/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:49:27 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 02:54:39 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	inter_sphere(t_obj *obj, t_vec dist, t_vec raydir)
{
	float disc[6];

	disc[0] = (raydir.x * raydir.x) + (raydir.y * raydir.y) +
		(raydir.z * raydir.z);
	disc[1] = 2.0 * ((raydir.x * dist.x) + (raydir.y * dist.y) +
			(raydir.z * dist.z));
	disc[2] = (dist.x * dist.x) + (dist.y * dist.y) + (dist.z * dist.z)
		- (obj->rayon * obj->rayon);
	if ((disc[3] = (disc[1] * disc[1]) - (4 * disc[0] * disc[2])) < 0)
		return (MAX_FLOAT);
	if (disc[3] == 0)
		disc[4] = -disc[1] / (2 * disc[0]);
	else if (disc[3] > 0)
	{
		disc[4] = (-disc[1] + sqrtf(disc[3])) / (2 * disc[0]);
		disc[5] = (-disc[1] - sqrtf(disc[3])) / (2 * disc[0]);
		disc[4] = (disc[4] < disc[5]) ? disc[4] : disc[5];
	}
	return (disc[4]);
}
