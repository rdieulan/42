/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:45:27 by rdieulan          #+#    #+#             */
/*   Updated: 2016/10/29 19:17:20 by rdieulan         ###   ########.fr       */
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

void	set_color_wall_north(t_env *env, double dist)
{
	env->red = 255 / (1 + (dist / 500));
	env->green = 228 / (1 + (dist / 500));
	env->blue = 1;
}

void	set_color_wall_south(t_env *env, double dist)
{
	env->red = 190 / (1 + (dist / 500));
	env->green = 30 / (1 + (dist / 500));
	env->blue = 1;
}

void	set_color_wall_west(t_env *env, double dist)
{
	env->red = 255 / (1 + (dist / 500));
	env->green = 1;
	env->blue = 238 / (1 + (dist / 500));
}

void	set_color_wall_east(t_env *env, double dist)
{
	env->red = 255 / (1 + (dist / 500));
	env->green = 105 / (1 + (dist / 500));
	env->blue = 1;
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
