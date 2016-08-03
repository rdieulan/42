/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:42:30 by rdieulan          #+#    #+#             */
/*   Updated: 2016/08/03 19:34:14 by rdieulan         ###   ########.fr       */
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
		env->x1 += ((WIN_H / 2) / WIN_W / 2) / env->z_r * 100;
		env->y1 += ((WIN_W / 2) / WIN_H / 2) / env->z_r * 100;
		env->posx -= env->zoom / 10;
		env->posy -= env->zoom / 10;
	}
	else if (keycode == 78) // -- ZOOM
	{
		env->zoom /= 1.1;
		env->it_max /= 1.1;
		env->x1 += ((WIN_H / 2) / WIN_W / 2) / env->z_r * 100;
		env->y1 += ((WIN_W / 2) / WIN_H / 2) / env->z_r * 100;
		env->posx += env->zoom / 10;
		env->posy += env->zoom / 10;
	}
	else if (keycode == 123)
		env->posx -= env->zoom / 10;
	else if (keycode == 124)
		env->posx += env->zoom / 10;
	else if (keycode == 125)
		env->posy += env->zoom / 10;
	else if (keycode == 126)
		env->posy -= env->zoom / 10;
	else if (keycode == 116)
		env->it_max *= 1.1;
	else if (keycode == 121)
		env->it_max /= 1.1;
	else
		printf("unassigned key code = %d\n", keycode);
	mlx_destroy_image(env->ptr, env->img);
	env->img = mlx_new_image(env->ptr, WIN_W - env->posx, WIN_H - env->posy);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len), &(env->endian));
	if (ft_strcmp(env->title, "mandelbrot") == 0)
		mandel_scan(env);
	else if (ft_strcmp(env->title, "julia") == 0)
		julia_scan(env);
	else if (ft_strcmp(env->title, "custom") == 0)
		custom_scan(env);
	else
		;
	mlx_put_image_to_window(env->ptr, env->win, env->img, env->posx, env->posy);
	return (0);
}
