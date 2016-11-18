/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:01:21 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/15 18:57:47 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ray_draw(t_env *env, double dist)
{
	int	i;
	int	height;
	int	wall_start;

	dist *= cos((env->angle - env->ray_angle) * M_PI / 180);
	height = ((WIN_W / 2) / tan((FOV / 2) * M_PI / 180)) * (B_UNIT / dist);
	wall_start = (WIN_H - height) / 2;
	i = 0;
	color_sky(env);
	while (wall_start > 0 && i < wall_start)
		draw(env, env->col, i++);
	color_wall(env, dist);
	while (i < height + wall_start && i < WIN_H)
		draw(env, env->col, i++);
	env->ground_grad = (255 / (double)((WIN_H - i)));
	env->ground_lim = height + wall_start;
	while (i < (WIN_H - 1))
		draw_ground(env, env->col, i++);
}

int		is_wall(t_env *env, double i)
{
	double	x;
	double	y;

	x = ((env->posx + (env->rx * i)) / B_UNIT);
	y = ((env->posy + (env->ry * i)) / B_UNIT);
	if (env->map[(int)x] && env->map[(int)x][(int)y]
			&& env->map[(int)x][(int)y] == 1)
	{
		env->nord = (int)x * B_UNIT;
		env->sud = ((int)x + 1) * B_UNIT;
		env->ouest = (int)y * B_UNIT;
		env->est = ((int)y + 1) * B_UNIT;
		env->wx = x;
		env->wy = y;
		return (1);
	}
	return (0);
}

void	ray_cast(t_env *env)
{
	double	i;
	int		wall;

	i = 0;
	wall = 0;
	while (env->posx + (env->rx * i) < env->map_size &&
			env->posy + (env->ry * i) < env->map_size &&
			env->posx + (env->rx * i) >= 0 &&
			env->posy + (env->ry * i) >= 0 && wall == 0)
	{
		if (is_wall(env, i) == 1)
		{
			while (is_wall(env, i) == 1)
				i -= 0.01;
			i += 0.01;
			wall = 1;
			ray_draw(env, i);
		}
		i += 1;
	}
}

void	ray_set(t_env *env)
{
	env->col = 0;
	env->ray_angle = angle_norm(env->angle - ((double)FOV / 2));
	env->rx = sin(env->ray_angle * M_PI / 180);
	env->ry = cos(env->ray_angle * M_PI / 180);
	while (env->col < WIN_W)
	{
		ray_cast(env);
		env->ray_angle = angle_norm(env->ray_angle + env->step);
		env->rx = sin(env->ray_angle * M_PI / 180);
		env->ry = cos(env->ray_angle * M_PI / 180);
		env->col++;
	}
}
