/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:53:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/16 16:34:14 by rdieulan         ###   ########.fr       */
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
			PXL = (int *)malloc(sizeof(int) * 2);
			mlx_pixel_put(mlx->ptr, mlx->win, D_HEIGHT, D_WIDTH, 0x0000FFFF);
			PXL[0] = D_WIDTH;
			PXL[1] = D_HEIGHT;
			j++;
		}
		i++;
	}
}

void	draw_horizontal(t_env *env, t_mlx *mlx, int i, int j)
{
	int o;
	int h;
	int e;
	int pxl_tmp;

	e = PXL_H[0] - PXL_H[0];
	o = e * 2;
	h = (PXL_H[1] - PXL[1]) * 2;

	printf("%d : ", i);
	printf ("draw horizontal. [%d][%d] -> [%d][%d]\n", PXL[0], PXL[1], PXL_H[0], PXL_H[1]);

	while (PXL[0] <= PXL_H[0])
	{
		mlx_pixel_put(mlx->ptr, mlx->win, PXL[0], pxl_tmp, 0x0000FF00);
		PXL[0]++;
		if ((e -= (h)) <= 0)
		{
			pxl_tmp++;
			e += o;
		}
	}
}

void	draw_vertical(t_env *env, t_mlx *mlx, int i, int j)
{
	int o;
	int v;
	int e;
	int pxl_tmp;

	pxl_tmp = PXL[1];
	e = PXL_V[0] - PXL_V[0];
	o = e * 2;
	v = (PXL_V[1] - PXL[1]) * 2;

	printf("%d : ", i);
	printf ("draw vertical. [%d][%d] -> [%d][%d]\n", PXL[0], PXL[1], PXL_V[0], PXL_V[1]);

	while (PXL[0] <= PXL_V[0])
	{
		mlx_pixel_put(mlx->ptr, mlx->win, PXL[0], pxl_tmp, 0x0000FF00);
		PXL[0]++;
		if ((e -= (v)) <= 0)
		{
			pxl_tmp++;
			e += o;
		}
	}
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
				;
				//draw_horizontal(env, mlx, i, j);
			if (i != (env->x - 1))
				draw_vertical(env, mlx, i, j);
			j++;
		}
		i++;
	}
}
