/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:53:47 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/02 14:31:38 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	depth(int keycode, t_env *env)
{
	if (keycode == 116)
		env->depth += 1;
	else
		env->depth -= 1;
}

void	zoom(int keycode, t_env *env)
{
	if (keycode == 69)
	{
		env->scale += 5;
		env->h_step += 5;
		env->w_step += 5;
	}
	else
	{
		env->scale -= 5;
		env->h_step -= 5;
		env->w_step -= 5;
	}
}

void	move(int keycode, t_env *env)
{
	if (keycode == 123)
		env->h_step += env->scale;
	else if (keycode == 124)
		env->h_step -= env->scale;
	else if (keycode == 125)
		env->w_step -= env->scale;
	else
		env->w_step += env->scale;
}

int		key_hooker(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69 || keycode == 78)
		zoom(keycode, env);
	else if (keycode >= 123 && keycode <= 126)
		move(keycode, env);
	else if (keycode == 116 || keycode == 121)
		depth(keycode, env);
	else
		printf("unassigned keycode : %d\n", keycode);
	mlx_clear_window(MLX->ptr, MLX->win);
	draw(env);
	return (0);
}
