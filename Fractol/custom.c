/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:07:44 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 18:19:46 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	custom(t_env *env, double x, double y)
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
		env->z_r = fabs(module_light(env->z_r, env->z_i, '-') + env->c_r);
		env->z_i = fabs((2 * env->z_i * tmp) + env->c_i);
		it += 20;
	}
	if (it >= env->it_max)
		draw(env, x, y);
	else
	{
		env->green = fabs(module_light(env->z_r, env->z_i, '-')) * it;
		env->blue = module_light(env->z_r, env->z_i, '+') * it;
		env->red = 200;
		draw(env, x, y);
	}
}

void	custom_scan(t_env *env)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIN_H - env->posx)
	{
		y = 0;
		while (y < WIN_W - env->posy)
		{
			custom(env, x, y);
			y++;
		}
		x++;
	}
}

void	set_custom(t_env *env)
{
	env->x1 = -2.5;
	env->y1 = -2.5;
	env->red = 0;
	env->green = 0;
	env->blue = 0;
	env->zoom = 200;
	env->it_max = 100;
	env->posx = 0;
	env->posy = 0;
	env->ptr = mlx_init();
	env->win = mlx_new_window(env->ptr, WIN_W, WIN_H, env->title);
	env->img = mlx_new_image(env->ptr, WIN_W - env->posx, WIN_H - env->posy);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len),
			&(env->endian));
	custom_scan(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}
