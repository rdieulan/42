/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:07:44 by rdieulan          #+#    #+#             */
/*   Updated: 2016/08/03 20:20:16 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

void	custom(t_env *env, double x, double y)
{
	int it;
	double a;
	double b;
	double r;

	a = WIN_H / 2 + env->x1;
	b = WIN_W / 2 + env->y1;
	r = env->zoom / 5;
	it = 0;
	while (sin(a + x) + sin(b + y) != 0 && it < env->it_max)
	{
		a = x * sin(a + y);
		b = x * sin(b + y);
		it++;
	}
	if (it == env->it_max)
		draw(env, x ,y);
	else
	{
		env->blue = it * 100;
		env->green = (it * 255) / env->it_max;
		env->red = (it * 255) / env->it_max;
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
	ft_putstr("custom set\n");
	env->x1 = -2;
	env->y1 = 2;
	env->red = 0;
	env->green = 0;
	env->blue = 0;
	env->zoom = 200;
	env->it_max = 50;
	env->posx = 0;
	env->posy = 0;
	env->img = mlx_new_image(env->ptr, WIN_W - env->posx, WIN_H - env->posy);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len), &(env->endian));
	custom_scan(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	mlx_loop(env->ptr);
}
