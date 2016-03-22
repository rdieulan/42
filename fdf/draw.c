/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:53:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/22 18:55:24 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel_pattern(t_env *env, t_mlx *mlx)
{
	int i;
	int j;

	env->pixel_matrix = (float ***)malloc(sizeof(float **) * (env->x + 1));
	i = 0;
	while (i < env->x)
	{
		j = 0;
		env->pixel_matrix[i] = (float **)malloc(sizeof(float *) * (env->y + 1));
		while (j < env->y)
		{
			PXL = (float *)malloc(sizeof(float) * 2);
			PXL[0] = (float)D_WIDTH;
			PXL[1] = (float)D_HEIGHT;
			j++;
		}
		i++;
	}
}

void	draw_seg(t_mlx *mlx, t_env *env)
{
	float tmpx0;
	float tmpx1;

	tmpx0 = X0;
	tmpx1 = X1;
	if (X0 == Y0)
	{
		//printf(" vertical\n");
		while (tmpx1 <= Y1)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, tmpx1, X0, 0x00FF0000); // ROUGE
		//	printf("DRAW PIXEL [%f].[%f] ROUGE\n", X0, tmpx1);
			tmpx1++;
		}
	}
	else if (X1 == Y1)
	{
		//printf(" horizontal\n");
		while (tmpx0 <= Y0)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, X1, tmpx0, 0x00FF00FF); // ROSE
		//	printf("DRAW PIXEL [%f].[%f] ROSE\n", tmpx0, X1);
			tmpx0++;
		}
	}
	else
		draw_diag_select(mlx, env);
}

void	draw(t_env *env, t_mlx *mlx)
{
	int i;
	int j;

	draw_pixel_pattern(env, mlx);
	i = 0;
	while (i < env->x)
	{
		//printf("LINE %d :    [x1][x2] -> [y1][y2]\n", i);
		j = 0;
		while (j < env->y)
		{
			X0 = PXL[0];
			X1 = PXL[1];
			if (j < env->y - 1) // horizontal
			{
				Y0 = PXL_H[0];
				Y1 = PXL_H[1];
				//printf("HORIZONTAL TRACE ORDER [%d][%d] -> [%d][%d] : [%f][%f] -> [%f][%f]", i, j, i, j + 1, X0, X1, Y0, Y1);
				draw_seg(mlx, env);
			}
			if (i < env->x - 1) // vertical
			{
				Y0 = PXL_V[0];
				Y1 = PXL_V[1];
				//printf("VERTICAL TRACE ORDER [%d][%d] -> [%d][%d] : [%f][%f] -> [%f][%f]", i, j, i + 1, j, X0, X1, Y0, Y1);
				draw_seg(mlx, env);
			}
			j++;
		}
		i++;
	}
}
