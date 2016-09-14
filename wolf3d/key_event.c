/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:55:57 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 17:02:24 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int key_hooker(int kcode, t_env *env)
{
	if (kcode == 53)
		exit(0);
	printf("keycode = %d\n", kcode);
	free(env->addr);
	env->img = mlx_new_image(env->ptr, WIN_W, WIN_H);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len),
			&(env->endian));
	game(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}
