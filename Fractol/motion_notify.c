/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 15:46:35 by rdieulan          #+#    #+#             */
/*   Updated: 2016/07/27 20:27:15 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		motion_notify(int x, int y, t_env *env)
{
	if (ft_strcmp("julia", env->title) == 0)
	{
		env->c_r = ((double)x + 750) / 2000;
		env->c_i = ((double)y + 750) / 2000;
		env->img = mlx_new_image(env->ptr, WIN_W - env->posx, WIN_H - env->posy);
		env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len), &(env->endian));
		julia_scan(env);
		mlx_put_image_to_window(env->ptr, env->win, env->img, env->posx, env->posy);
	}
	return (0);
}
