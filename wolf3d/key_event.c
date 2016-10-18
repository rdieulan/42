/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:55:57 by rdieulan          #+#    #+#             */
/*   Updated: 2016/10/18 16:04:56 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	arrowkey(int kcode, t_env *env)
{
	if (kcode == 123 && env->posx < env->map_size)
		env->posx += 1;
	else if (kcode == 124 && env->posx < env->map_size)
		env->posx -= 1;
	else if (kcode == 125 && env->posy < env->map_size)
	{
		env->posx -= cos(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
		env->posy -= sin(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;

	}
	else if (kcode == 126 && env->posy < env->map_size)
	{
		env->posx += cos(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
		env->posy += sin(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
	}
	else
		;
	printf("NEW POS : %f | %f\n", env->posx, env->posy);
}

void	rotate(int kcode, t_env *env)
{
	if (kcode == 12)
		env->angle -= 1;
	else if (kcode == 14)
		env->angle += 1;
	else
		;
}

int		key_hooker(int kcode, t_env *env)
{
	if (kcode == 53)
		exit(0);
	else if (kcode >= 123 && kcode <= 126)
		arrowkey(kcode, env);
	else if (kcode == 12 || kcode == 14)
		rotate(kcode, env);
	else
		printf("keycode = %d\n", kcode);
	free(env->addr);
	env->img = mlx_new_image(env->ptr, WIN_W, WIN_H);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len),
			&(env->endian));
	game(env);
	return (0);
}
