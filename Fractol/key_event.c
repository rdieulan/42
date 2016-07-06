/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:42:30 by rdieulan          #+#    #+#             */
/*   Updated: 2016/07/06 18:38:20 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int		key_hooker(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69)
	{
		env->zoom += 50;
		env->it_max += 50;
		env->posx -= 100;
		env->posy -= 100;
	}
	else if (keycode == 78)
	{
		env->zoom -= 50;
		env->it_max -= 20;
	}
	else
		printf("unassigned key code = %d\n", keycode);
	mlx_destroy_image(env->ptr, env->img);
	if (ft_strcmp(env->title, "mandelbrot") == 0)
		set_mandelbrot(env, 1);
	else if (ft_strcmp(env->title, "julia") == 0)
		set_julia(env, 1);
	else if (ft_strcmp(env->title, "custom") == 0)
		;
	else
		;
	return (0);
}
