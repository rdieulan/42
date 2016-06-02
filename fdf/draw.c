/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:53:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/02 19:22:18 by rdieulan         ###   ########.fr       */
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
			PXL[0] = D_WIDTH;
			PXL[1] = D_HEIGHT;
			j++;
		}
		i++;
	}
}

int		color_value(int value)
{
	if (value == 0)
		return (0x00FF00);
	else if (value > 0)
		return (0x0000FF);
	else
		return (0xFF0000);
}

void	color_select(int start, int end, t_env *env)
{
	env->c_start = color_value(start);
	env->c_end = color_value(end);
}

int		color_gradient(t_env *env)
{
	if (env->c_start > env->c_end)
		env->gradient_step = (env->c_start - env->c_end) / (env->nbstep * 100);
	else if (env->c_start < env->c_end)
		env->gradient_step = (env->c_end - env->c_start) / (env->nbstep * 100);
	else
		env->gradient_step = 0;
	env->color = env->c_start + (env->gradient_step * env->actual_step);
	env->actual_step++;
	return (env->color);
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
			X0 = PXL[0];
			X1 = PXL[1];
			if (j < env->y - 1) // horizontal
			{
				Y0 = PXL_H[0];
				Y1 = PXL_H[1];
				color_select(MATRIX[i][j] * DP, MATRIX[i][j+1] * DP, env);
				draw_diag_select(env);
			}
			if (i < env->x - 1) // vertical
			{
				Y0 = PXL_V[0];
				Y1 = PXL_V[1];
				color_select(MATRIX[i][j] * DP, MATRIX[i+1][j] * DP, env);
				draw_diag_select(env);
			}
			j++;
		}
		i++;
	}
}
