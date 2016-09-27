/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:01:21 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/27 16:59:38 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		is_wall(t_env *env, double i)
{
	double	tmpx;
	double	tmpy;
	int		x;
	int		y;

	env->color = 1;
	tmpx = env->posx + ()
}

void	check_collision(t_env *env)
{
	double	i;
	int		wall;
	int		color;

	i = 0;
	wall = 0;
	color = 0;
	while (env->posx + (env->rx * i) < env->map_size &&
			env->posy + (env->ry * i) < env->map_size &&
			env->posx + (env->rx * i) >= 0 &&
			env->posy + (env->ry * i) >= 0 && wall == 0)
	{
		if ();
	}
}

void	ray_set(t_env *env)
{
	double	ray_angle;
	double	rx;
	double	ry;

	env->col = 0;
	ray_angle = env->angle - (M_PI / 12);
	rx = cos(ray_angle);
	ry = sin(ray_angle);
	while (ray_angle < env->angle + (M_PI / 12))
	{
		rx = cos(ray_angle);
		ry = sin(ray_angle);
		env->rx = rx;
		env->ry = ry;
		env->tmp_angle = ray_angle;
		check_collision(env);
		ray_angle += M_PI / 6 / WIN_W;
		env->col++;
	}
}

void	game(t_env *env)
{
	
}
