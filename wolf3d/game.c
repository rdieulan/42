/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:01:21 by rdieulan          #+#    #+#             */
/*   Updated: 2016/10/07 19:31:29 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ray_draw(t_env *env, double dist)
{
	ft_putstr("ray_draw()\n");
	int	i;
	int	height;
	int	wall_start;

	dist = hypot(env->rx * dist, env->ry * dist);
	printf("dist %f\n", dist);
	height = (WIN_W / 2 / tan(FOV / 2) * BLOCK_UNIT) / dist;
	wall_start = (WIN_H - height) / 2;
	i = 0;
	color_sky(env);
	printf("start sky : %d\n", i);
	while (wall_start > 0 && i < wall_start)
		draw(env, env->col, i++);
	printf("start wall : %d / %d\n", i, height);
	color_wall(env);
	while (i < height + wall_start && i < WIN_H)
		draw(env, env->col, i++);
	printf("start ground : %d\n", i);
	color_ground(env);
	while (i < (WIN_H - 1) && i > 0)
		draw(env, env->col, i++);
}

int		is_wall(t_env *env, int i)
{
	//ft_putstr("is_wall()\n");
	int		x;
	int		y;

	env->color = 1;
	x = (int)((env->posx + (env->rx * i)) / BLOCK_UNIT);
	y = (int)((env->posy + (env->ry * i)) / BLOCK_UNIT);
	//printf("map[%d][%d] == %d\n", y, x, env->map[y][x]);
	if (env->map[y] && env->map[y][x] && env->map[y][x] == 1)
		return(1);
	return(0);
}

void	ray_cast(t_env *env)
{
	//printf("check_env()\n");
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
			//printf("WALL !!!\n");
			while (is_wall(env, i) == 1)
				i -= 0.1;
			i += 0.1;
			wall = 1;
			ray_draw(env, i);
		}
		i += 1;
	}
}

void	ray_set(t_env *env)
{
	//ft_putstr("ray_set()\n");
	double	ray_angle;

	env->col = 0;
	ray_angle = env->angle - (FOV / 2);
	env->rx = cos(ray_angle);
	env->ry = sin(ray_angle);
	while (env->col < WIN_W)
	{
		env->rx = cos(ray_angle);
		env->ry = sin(ray_angle);
		ray_cast(env);
		ray_angle += env->step;
		env->col++;
	}
}

void	game(t_env *env)
{
	ray_set(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}
