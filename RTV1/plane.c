/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:49:07 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 02:52:49 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		inter_plane(t_obj *obj, t_vec dist, t_vec raydir)
{
	float t;

	t = -(dist.x * obj->dir.x + dist.y * obj->dir.y + dist.z * obj->dir.z)
	/ (raydir.x * obj->dir.x + raydir.y * obj->dir.y + raydir.z * obj->dir.z);
	return (t >= 0 ? t : MAX_FLOAT);
}
