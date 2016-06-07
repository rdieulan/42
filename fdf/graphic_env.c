/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:00:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/07 19:20:54 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	graphic_init(t_env *env)
{
	MLX->w = 1000;
	MLX->h = 1000;
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
