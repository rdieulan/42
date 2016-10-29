/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:55:57 by rdieulan          #+#    #+#             */
/*   Updated: 2016/10/29 19:14:45 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		secu(t_env *env, int kcode)
{
	double	mapx;
	double	mapy;

	if (kcode == 0 || kcode == 2)
	{
		mapx = cos(env->angle * M_PI / 180) * env->speed;
		mapy = sin(env->angle * M_PI / 180) * env->speed;
		if (kcode == 0)
			return (env->map[XMAP0][YMAP1]);
		else
			return (env->map[XMAP1][YMAP0]);
	}
	else
	{
		mapx = cos(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
		mapy = sin(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
		if (kcode == 1)
			return (env->map[XMAP0][YMAP1]);
		else
			return (env->map[XMAP1][YMAP0]);
	}
}

void	arrowkey(int kcode, t_env *env)
{
	if (kcode == 0 && secu(env, kcode) == 0)
	{
		env->posx -= cos(env->angle * M_PI / 180) * env->speed;
		env->posy += sin(env->angle * M_PI / 180) * env->speed;
	}
	if (kcode == 2 && secu(env, kcode) == 0)
	{
		env->posx += cos(env->angle * M_PI / 180) * env->speed;
		env->posy -= sin(env->angle * M_PI / 180) * env->speed;
	}
	if (kcode == 1 && secu(env, kcode) == 0)
	{
		env->posx -= cos(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
		env->posy += sin(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
	}
	if (kcode == 13 && secu(env, kcode) == 0)
	{
		env->posx += cos(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
		env->posy -= sin(angle_norm(env->angle - 90) * M_PI / 180) * env->speed;
	}
}

void	rotate(int kcode, t_env *env)
{
	if (kcode == 12)
		env->angle -= ROTATE_SPEED;
	if (kcode == 14)
		env->angle += ROTATE_SPEED;
}

int		key_hooker(int kcode, t_env *env)
{
	if (kcode == 53)
		exit(0);
	else if (kcode == 0 || kcode == 1 || kcode == 2 || kcode == 13)
		arrowkey(kcode, env);
	else if (kcode == 12 || kcode == 14)
		rotate(kcode, env);
	free(env->addr);
	env->img = mlx_new_image(env->ptr, WIN_W, WIN_H);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len),
			&(env->endian));
	game(env);
	return (0);
}
