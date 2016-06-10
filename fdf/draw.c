/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:53:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/10 17:00:35 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel_pattern(t_env *env)
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
			PXL = (int *)malloc(sizeof(int) * 2);
			PXL[0] = (i + 1) * env->scale - (MATRIX[i][j] * env->depth)
				+ env->w_step;
			PXL[1] = ((i + j + 1) * env->scale) + env->h_step;
			j++;
		}
		i++;
	}
}

void	color_select(int start, int end, t_env *env)
{
	if (start == 0)
		env->color_start = 10;
	else if (start <= -10)
		env->color_start = 0;
	else if (start < 0)
		env->color_start = 10 - start;
	else if (start >= 10)
		env->color_start = 20;
	else
		env->color_start = 10 + start;
	if (end == 0)
		env->color_end = 10;
	else if (end <= -10)
		env->color_end = 0;
	else if (end < 0)
		env->color_end = 10 - end;
	else if (end >= 10)
		env->color_end = 20;
	else
		env->color_end = 10 + end;
}

int		color_gradient(t_env *env)
{
	int color;

	if (env->color_start > env->color_end)
		env->grad_step = -env->nbstep / (env->color_start - env->color_end);
	else if (env->color_start < env->color_end)
		env->grad_step = env->nbstep / (env->color_end - env->color_start);
	else
		return (env->grad[(int)env->color_start]);
	color = env->color_start + (env->actual_step / env->grad_step) + 0.5;
	if (env->actual_step < env->nbstep)
		env->actual_step++;
	return (env->grad[color]);
}

void	to_diag(t_env *env, int i, int j)
{
	X0 = PXL[0];
	X1 = PXL[1];
	if (j < env->y - 1)
	{
		Y0 = PXL_H[0];
		Y1 = PXL_H[1];
		color_select(MATRIX[i][j] * DP, MATRIX[i][j + 1] * DP, env);
		draw_diag_select(env);
	}
	if (i < env->x - 1)
	{
		Y0 = PXL_V[0];
		Y1 = PXL_V[1];
		color_select(MATRIX[i][j] * DP, MATRIX[i + 1][j] * DP, env);
		draw_diag_select(env);
	}
}

void	draw(t_env *env)
{
	int i;
	int j;

	draw_pixel_pattern(env);
	i = 0;
	while (i < env->x)
	{
		j = 0;
		while (j < env->y)
		{
			to_diag(env, i, j);
			j++;
		}
		i++;
	}
}
