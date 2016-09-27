/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:02:26 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/27 15:26:51 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	event_start(t_env *env)
{
	mlx_hook(env->win, 2, 1L << 0, key_hooker, env);
	mlx_mouse_hook(env->win, m_hooker, env);
	mlx_hook(env->win, 6, 1L << 0, motion_notify, env);
	mlx_loop(env->ptr);
}

void	draw(t_env *env, double x, double y)
{
	int	nb;

	nb = (x * env->bits) / 8 + (y * env->len);
	env->addr[nb] = env->blue;
	env->addr[nb + 1] = env->green;
	env->addr[nb + 2] = env->red;
	env->blue = 0;
	env->green = 0;
	env->red = 0;
}

void	custom_color(t_env *env, int x, int y, int it)
{
	env->green = (int)(env->z_r * 100) % 200;
	env->blue = (int)(env->z_r * 120) % 200;
	env->red = 200;
	draw(env, x, y);
}

void	mandel_color(t_env *env, int x, int y, int it)
{
	env->blue = module_light(env->z_r, env->z_i, '-') * it;
	env->red = (env->it_max / 255) * it;
	env->green = (env->it_max / 255) * it;
	draw(env, x, y);
}
