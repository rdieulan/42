/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:00:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/02 14:10:35 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	graphic_init(t_env *env)
{
	MLX->w = 2560;//(env->y + 1) * D_SCALE;
	MLX->h = 1420;//(env->x + 1) * D_SCALE;
	MLX->ptr = mlx_init();
	MLX->win = mlx_new_window(MLX->ptr, MLX->w, MLX->h, env->title);
}

void	graphic_process(t_env *env)
{
	MLX = (t_mlx*)malloc(sizeof(t_mlx));
	graphic_init(env);
	mlx_hook(MLX->win, 2, 1L << 0, key_hooker, env);
	draw(env);
	mlx_loop(MLX->ptr);
}
