/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:03:39 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/14 19:24:02 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *env, double x, double y)
{
	int		it;
	double	tmp;

	env->c_r = (x / env->zoom) + env->x1;
	env->c_i = (y / env->zoom) + env->y1;
	env->z_r = 0;
	env->z_i = 0;
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

void	mandel_scan(t_env *env)
{
	double	x;
	double	y;

	x = 0;
	while (x < env->image_x)
	{
		y = 0;
		while (y < env->image_y)
		{
			mandelbrot(env, x, y);
			y++;
		}
		x++;
	}
}

void	set_mandelbrot(t_env *env)
{
	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->red = 0;
	env->green = 0;
	env->blue = 0;
	env->zoom = 400;
	env->it_max = 100;
	env->image_x = (env->x2 - env->x1) * env->zoom;
	env->image_y = (env->y2 - env->y1) * env->zoom;
	mandel_scan(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	mlx_loop(env->ptr);
}
