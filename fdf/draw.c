/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:53:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/15 17:24:16 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel_pattern(t_env *env, t_mlx *mlx)
{
	int i;
	int j;

	env->pixel_matrix = (int ***)malloc(sizeof(int **) * (env->x + 1));
	i = 0;
	while (i < env->x)
	{
		j = 0;
		env->pixel_matrix[i] = (int **)malloc(sizeof(int *) * (env->y + 1));
		while (j < env->y)
		{
			env->pixel_matrix[i][j] = (int *)malloc(sizeof(int) * 2);
			mlx_pixel_put(mlx->ptr, mlx->win, D_HEIGHT, D_WIDTH, 0x0000FFFF);
			env->pixel_matrix[i][j][0] = D_HEIGHT;
			env->pixel_matrix[i][j][1] = D_WIDTH;
			j++;
		}
		i++;
	}
}

void	draw_horizontal(t_env *env, t_mlx *mlx)
{
	;
}

void	draw_vertical(t_env *env, t_mlx *mlx)
{
	;
}

void	draw(t_env *env, t_mlx *mlx)
{
	int i;
	int j;

	draw_pixel_pattern(env, mlx);
	i = 0;
	while (i < env->x)
	{
		j = 0;
		while (j < env->y)
		{
			if (j != (env->y - 1))
				draw_horizontal(env, mlx);
			if (i != (env->x - 1))
				draw_vertical(env, mlx);
			j++;
		}
		i++;
	}
}
