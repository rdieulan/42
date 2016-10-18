/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:01:21 by rdieulan          #+#    #+#             */
/*   Updated: 2016/10/18 15:59:56 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double	angle_norm(double angle)
{
	if (angle < 0)
		return (angle + 360);
	else if (angle > 360)
		return (angle - 360);
	else
		return (angle);
}

void	ray_draw(t_env *env, double dist)
{
	int	i;
	int	height;
	int	wall_start;

	//printf("%f : %f\n", env->rx, env->ry);
	dist *= cos((env->angle - env->ray_angle) * M_PI / 180);//(env->posx - env->wx) + (env->posy - env->wy);
	//dist = dist * cos(fabs(env->angle - env->ray_angle) * M_PI / 180);
	printf("dist %f\n", dist);
	height = BLOCK_UNIT / dist * ((WIN_W / 2) / tan((FOV / 2) * M_PI / 180));
	printf("height : %d\n\n", height);
	wall_start = (WIN_H - height) / 2;
	i = 0;
	color_sky(env);
	//printf("start sky : %d\n", i);
	while (wall_start > 0 && i < wall_start)
		draw(env, env->col, i++);
	//printf("start wall : %d / %d\n", i, height);
	color_wall(env);
	while (i < height + wall_start && i < WIN_H)
		draw(env, env->col, i++);
	//printf("start ground : %d\n", i);
	color_ground(env);
	while (i < (WIN_H - 1) && i > 0)
		draw(env, env->col, i++);
}

int		is_wall(t_env *env, int i)
{
	double	x;
	double	y;

	x = ((env->posx + (env->rx * i)) / BLOCK_UNIT);
	y = ((env->posy + (env->ry * i)) / BLOCK_UNIT);
	if (env->map[(int)x] && env->map[(int)x][(int)y] && env->map[(int)x][(int)y] == 1)
	{
		printf("FOUND WALL[%d][%d] @ {%f:%f}\n", (int)x, (int)y, x * BLOCK_UNIT, y * BLOCK_UNIT);
		env->nord = (int)x * BLOCK_UNIT;
		env->sud = ((int)x + 1) * BLOCK_UNIT;
		env->ouest = (int)y * BLOCK_UNIT;
		env->est = ((int)y + 1) * BLOCK_UNIT;
		env->wx = x;
		env->wy = y;
		return(1);
	}
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
			while (is_wall(env, i) == 1)
				i -= 0.001;
			i += 0.001;
			wall = 1;
			ray_draw(env, i);
		}
		i += 1;
	}
}

void	ray_set(t_env *env)
{
	//ft_putstr("ray_set()\n");

	env->col = 0;
	env->ray_angle = angle_norm(env->angle - ((double)FOV / 2));
	env->rx = sin(env->ray_angle * M_PI / 180);
	env->ry = cos(env->ray_angle * M_PI / 180);
	while (env->col < WIN_W)
	{
		//printf("\nRAY ANGLE = %f\n", env->ray_angle);
		ray_cast(env);
		env->ray_angle = angle_norm(env->ray_angle + env->step);
		env->rx = sin(env->ray_angle * M_PI / 180);
		env->ry = cos(env->ray_angle * M_PI / 180);
		env->col++;
	}
}

void	game(t_env *env)
{
	ray_set(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}
