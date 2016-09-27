/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 15:46:35 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/27 14:59:03 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		motion_notify(int x, int y, t_env *env)
{
	if (ft_strcmp("julia", env->title) == 0)
	{
		mlx_destroy_image(env->ptr, env->img);
		env->c_r = ((double)x + 750) / 2000;
		env->c_i = ((double)y + 750) / 2000;
		set_julia(env);
	}
	return (0);
}
