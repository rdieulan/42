/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:45:27 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/21 12:22:33 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	color_ground(t_env *env, int i)
{
	env->red = 0;
	env->green = env->ground_grad * (i - env->ground_lim);
	env->blue = 0;
}

void	color_sky(t_env *env)
{
	env->red = 0;
	env->green = 0;
	env->blue = 0;
}

void	color_wall2(t_env *env, int wx, int wy, double dist)
{
	if (wx == env->nord)
		if (wy != env->ouest && wy != env->est)
			set_color_wall_north(env, dist);
	if (wx == env->sud)
		if (wy != env->ouest && wy != env->est)
			set_color_wall_south(env, dist);
	if (wy == env->ouest)
		if (wx != env->nord && wx != env->sud)
			set_color_wall_west(env, dist);
	if (wy == env->est)
		if (wx != env->nord && wx != env->sud)
			set_color_wall_east(env, dist);
}

void	color_wall(t_env *env, double dist)
{
	int	wx;
	int	wy;
	int	modx;
	int	mody;

	wx = (int)(env->wx * B_UNIT);
	wy = (int)(env->wy * B_UNIT);
	modx = wx % B_UNIT;
	mody = wy % B_UNIT;
	if (modx > 0 && modx < 2)
		wx--;
	if (modx > 2)
		wx++;
	if (mody > 0 && mody < 2)
		wy--;
	if (mody > 2)
		wy++;
	color_wall2(env, wx, wy, dist);
}
