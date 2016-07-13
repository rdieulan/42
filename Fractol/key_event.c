/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:42:30 by rdieulan          #+#    #+#             */
/*   Updated: 2016/07/13 15:29:08 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int		key_hooker(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69) // ++ ZOOM
	{
		env->zoom *= 1.1 ;
		env->it_max *= 1.1;
		env->x1 += ((WIN_H / 2) / WIN_W / 2) / env->z_r * 10;
		env->x2 += ((WIN_H / 2) / WIN_W / 2) / env->z_r * 10;
		env->y1 += ((WIN_W / 2) / WIN_H / 2) / env->z_r * 10;
		env->y2 += ((WIN_W / 2) / WIN_H / 2) / env->z_r * 10;
		env->posx -= env->zoom / 10;
		env->posy -= env->zoom / 10;
		printf("limitX : %d\n", WIN_H - env->posx);
		printf("limitY : %d\n", WIN_W - env->posy);
	}
	else if (keycode == 78) // -- ZOOM
	{
		env->zoom /= 1.1;
		env->it_max /= 1.1;
		env->x1 += ((WIN_H / 2) / WIN_W / 2) / env->z_r * 10;
		env->x2 += ((WIN_H / 2) / WIN_W / 2) / env->z_r * 10;
		env->y1 += ((WIN_W / 2) / WIN_H / 2) / env->z_r * 10;
		env->y2 += ((WIN_W / 2) / WIN_H / 2) / env->z_r * 10;
		env->posx += env->zoom / 10;
		env->posy += env->zoom / 10;
		printf("limitX : %d\n", WIN_H - env->posx);
		printf("limitY : %d\n", WIN_W - env->posy);
	}
	else if (keycode == 123)
		env->posx -= 10;
	else if (keycode == 124)
		;
	else if (keycode == 125)
		;
	else if (keycode == 126)
		;
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
