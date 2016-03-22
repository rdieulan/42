/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:00:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/22 19:02:42 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	graphic_init(t_mlx *mlx, t_env *env)
{
	mlx->w = 1000;//(env->y + 1) * D_SCALE;
	mlx->h = 1000;//(env->x + 1) * D_SCALE;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->w, mlx->h, env->title);
}

void	graphic_process(t_env *env)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	graphic_init(mlx, env);
	draw(env, mlx);
	mlx_key_hook(mlx->win, key_hooker, mlx);
	mlx_loop(mlx->ptr);
}
