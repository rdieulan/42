/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:07:44 by rdieulan          #+#    #+#             */
/*   Updated: 2016/07/06 17:53:34 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	custom(t_env *env, double x, double y)
{
	int		it;
	double	tmp;

	env->c_r = (y / env->zoom) + env->y1;
	env->c_i = (x / env->zoom) + env->x1;
	env->z_r = 0.155;//(y / env->zoom) + env->y1;
	env->z_i = (x / env->zoom) + env->x1;
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

void	custom_scan(t_env *env)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIN_H)
	{
		y = 0;
		while (y < WIN_W)
		{
			custom(env, x, y);
			y++;
		}
		x++;
	}
}

void	set_custom(t_env *env, int mod)
{
	if (mod == 0)
	{
		env->x1 = -2;
		env->x2 = 1;
		env->y1 = -1.6;
		env->y2 = 1;
		env->red = 0;
		env->green = 0;
		env->blue = 0;
		env->zoom = 300;
		env->it_max = 50;
	}
	custom_scan(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	mlx_loop(env->ptr);
}
