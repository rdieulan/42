/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:42:30 by rdieulan          #+#    #+#             */
/*   Updated: 2016/08/08 15:46:49 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_io(int kcode, t_env *env)
{
	if (kcode == 69)
	{
		env->zoom *= 1.1;
		env->it_max *= 1.1;
		env->x1 += ((WIN_H / 2) / WIN_W / 2) / env->z_r * 100;
		env->y1 += ((WIN_W / 2) / WIN_H / 2) / env->z_r * 100;
		env->posx -= env->zoom / 10;
		env->posy -= env->zoom / 10;
	}
	else
	{
		env->zoom /= 1.1;
		env->it_max /= 1.1;
		env->x1 += ((WIN_H / 2) / WIN_W / 2) / env->z_r * 100;
		env->y1 += ((WIN_W / 2) / WIN_H / 2) / env->z_r * 100;
		env->posx += env->zoom / 10;
		env->posy += env->zoom / 10;
	}
}

void	arrowkey(int kcode, t_env *env)
{
	if (kcode == 123)
		env->posx -= env->zoom / 10;
	else if (kcode == 124)
		env->posx += env->zoom / 10;
	else if (kcode == 125)
		env->posy += env->zoom / 10;
	else
		env->posy -= env->zoom / 10;
}

void	itmod(int kcode, t_env *env)
{
	if (kcode == 116)
		env->it_max *= 1.1;
	else if (kcode == 121)
		env->it_max /= 1.1;
}

void	win_refresh(t_env *env)
{
	mlx_destroy_image(env->ptr, env->img);
	env->img = mlx_new_image(env->ptr, WIN_W - env->posx, WIN_H - env->posy);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len),
			&(env->endian));
	if (ft_strcmp(env->title, "mandelbrot") == 0)
		mandel_scan(env);
	else if (ft_strcmp(env->title, "julia") == 0)
		julia_scan(env);
	else
		custom_scan(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, env->posx,
			env->posy);
}

int		key_hooker(int kcode, t_env *env)
{
	if (kcode == 53)
		exit(0);
	else if (kcode == 69 || kcode == 78)
		zoom_io(kcode, env);
	else if (kcode == 123 || kcode == 124 || kcode == 125 || kcode == 126)
		arrowkey(kcode, env);
	else if (kcode == 116 || kcode == 121)
		itmod(kcode, env);
	else
		;
	win_refresh(env);
	return (0);
}
