/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:41:35 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/21 12:22:39 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
