/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:18:13 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/14 19:32:29 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_env *env, double x, double y)
{
	int		it;
	double	tmp;

	env->c_r = 0.285;
	env->c_i = 0.01;
	env->z_r = (x / env->zoom) + env->x1;
	env->z_i = (y / env->zoom) + env->y1;
	it = 0;
	while ((module_light(env->z_r, env->z_i, '+') < 4) && it < env->it_max)
	{
		tmp = env->z_r;
		env->z_r = module_light(env->z_r, env->z_i, '-') + env->c_r;
		env->z_i = (2 * env->z_i * tmp) + env->c_i;
		it++;
	}
	if (it == env->it_max)
		draw(env, x, y);
	else
	{
		env->blue = (it * 255) / env->it_max;
		draw(env, x, y);
	}
}

void	julia_scan(t_env *env)
{
	double	x;
	double	y;

	x = 0;
	while (x < env->image_x)
	{
		y = 0;
		while (y < env->image_y)
		{
			julia(env, x, y);
			y++;
		}
		x++;
	}
}

void	set_julia(t_env *env)
{
	env->x1 = -1;
	env->x2 = 1;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->red = 0;
	env->green = 0;
	env->blue = 0;
	env->zoom = 400;
	env->it_max = 60;
	env->image_x = (env->x2 - env->x1) * env->zoom;
	env->image_y = (env->y2 - env->y1) * env->zoom;
	julia_scan(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	mlx_loop(env->ptr);
}

