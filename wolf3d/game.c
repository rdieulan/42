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

void	ray_draw(t_env *env, double dist)
{
	int	i;
	int	height;
	
	dist *= cos(env->tmp_angle - env->ray_angle);
	height = 1200 / dist;
	i = 400 - height;
	if (i < 0)
		i = 0;
	color_set(env);
	if (env->shadow == 1)
		shadow_set(env, dist);
	while (i < 400 + height && i < 800 && i >= 0 && env->col < WIN_W)
		draw(env, env->col, i++);
	env->red = 0;
	env->blue = 0;
	env->green = 0;
	while (i < 400 + height + 4 && i < 800)
		draw(env, env->col, i++);
	env->red = 0;
	env->blue = 50;
	env->green = 0;
	while (i < 799 && i > 0 && env->col < 1280)
	{	
		draw(env, env->col, i++);
		if (i % 3 == 0)
			env->blue++;
	}
}

int		is_wall(t_env *env, double i)
{
	double	tmpx;
	double	tmpy;
	int		x;
	int		y;

	env->color = 1;
	tmpx = env->posx + (env->rx * i);
	x = (int)tmpx;
	tmpy = env->posy + (env->ry * i);
	y = (int)tmpy;
	color_wall(env, x, y, i);
	if (env->map[y] && env->map[y][x] && env->map[y][x] == '1')
		return(1);
	return(0);
}

void	check_env(t_env *env)
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
		if (is_wall(env, i) == 1)
		{
			i -= 0.1;
			while (is_wall(env, i) != 1)
				i += 0.001;
			a = 1;
			ray_draw(env, i);
		}
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
		check_env(env);
		ray_angle += M_PI / 6 / WIN_W;
		env->col++;
	}
}

void	game(t_env *env)
{
	ray_set(env);
}
