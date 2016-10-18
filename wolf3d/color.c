/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:45:27 by rdieulan          #+#    #+#             */
/*   Updated: 2016/10/18 17:23:17 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	color_ground(t_env *env)
{
	env->red = 0;
	env->green = 255;
	env->blue = 0;
}

void	color_sky(t_env *env)
{
	env->red = 0;
	env->green = 0;
	env->blue = 255;
}

void	color_wall(t_env *env)
{
	int	wx;
	int	wy;
	int	modx;
	int	mody;

	wx = (int)(env->wx * B_UNIT);
	wy = (int)(env->wy * B_UNIT);
	modx = wx % B_UNIT;
	mody = wy % B_UNIT;
	//printf("modulo Y : %d\n", mody);
	//printf("pre limX : %d\n", wx);
	//printf("pre limY : %d\n", wy);
	if (modx > 0 && modx < 2)
		wx--;
	if (modx > 2)
		wx++;
	if (mody > 0 && mody < 2)
		wy--;
	if (mody > 2)
		wy++;

	env->blue = 0;
	env->red = 0;
	env->green = 0;

	//printf("color limX : %d |NS. %d:%d\n", wx, env->nord, env->sud);
	//printf("color limY : %d |OE. %d:%d\n", wy, env->ouest, env->est);
	if (wx == env->nord)
	{
		if (wy != env->ouest && wy != env->est)
			env->red = 50;
	}
	else if (wx == env->sud)
	{
		if (wy != env->ouest && wy != env->est)
			env->red = 100;
	}
	else if (wy == env->ouest)
	{
		if (wx != env->nord && wx != env->sud)
			env->red = 150;
	}
	else if (wy == env->est)
	{
		if (wx != env->nord && wx != env->sud)
			env->red = 200;
	}
	else
		;
	//printf("COLOR : %d\n", env->red);
}
