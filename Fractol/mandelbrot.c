/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:03:39 by rdieulan          #+#    #+#             */
/*   Updated: 2016/07/06 19:00:06 by rdieulan         ###   ########.fr       */
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
	{
		env->blue = 255 - (env->z_r * 100) - (env->c_r * 100);
		printf("blue : %d\n", env->blue);
		draw(env, x, y);
	}
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
	while (x < WIN_H - env->posx)
	{
		y = 0;
		while (y < WIN_W - env->posy)
		{
			mandelbrot(env, x, y);
			y++;
		}
		x++;
	}
}

void	set_mandelbrot(t_env *env, int mod)
{
	if (mod == 0)
	{
		env->x1 = -2.1;
		env->x2 = 0.6;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->red = 0;
		env->green = 0;
		env->blue = 0;
		env->zoom = 200;
		env->it_max = 100;
		env->posx = -50;
		env->posy = 0;
	}
	env->img = mlx_new_image(env->ptr, WIN_W - env->posx, WIN_H - env->posy);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len), &(env->endian));
	mandel_scan(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, env->posx, env->posy);
	mlx_loop(env->ptr);
}
