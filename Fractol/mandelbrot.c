/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:03:39 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 14:38:38 by rdieulan         ###   ########.fr       */
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
		it += 20;
	}
	if (it == env->it_max)
		draw(env, x, y);
	else
	{
		env->blue = module_light(env->z_r, env->z_i, '+') * it;
		env->green = (it * 255) / env->it_max;
		env->red = (it * 255) / env->it_max;
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

void	set_mandelbrot(t_env *env)
{
	env->x1 = -2.5;
	env->y1 = -2.5;
	env->red = 0;
	env->green = 0;
	env->blue = 0;
	env->zoom = 180;
	env->it_max = 100;
	env->posx = 0;
	env->posy = 0;
	env->img = mlx_new_image(env->ptr, WIN_W - env->posx, WIN_H - env->posy);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len),
			&(env->endian));
	mandel_scan(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}
