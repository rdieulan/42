/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjarross <tjarross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 17:05:06 by tjarross          #+#    #+#             */
/*   Updated: 2016/11/23 03:34:19 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_VEC_H
# define LIB_VEC_H

# include <math.h>

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

t_vec			normalize(t_vec v);
float			dot(t_vec v1, t_vec v2);
float			get_dist(t_vec v);
t_vec			rot(t_vec v, float hor_angle, float vert_angle);
t_vec			multiply_vec(t_vec v, float n);
t_vec			sub_vec(t_vec v1, t_vec v2);
t_vec			add_vec(t_vec v1, t_vec v2);
t_vec			div_vec(t_vec v1, float n);
t_vec			dot_div(t_vec v1, t_vec v2);
t_vec			not_vec(t_vec v);
t_vec			get_inters(t_vec origin, t_vec raydir, float t);
t_vec			product_vec(t_vec v1, t_vec v2);

#endif
