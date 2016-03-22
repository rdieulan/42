/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:03:26 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/22 18:49:59 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	draw_diag1(t_mlx *mlx, t_env *env, float coef)
{
	printf(" diag 1 || X0,X1[%f|%f] -> Y0,Y1[%f|%f]\n", X0, X1, Y0, Y1);
	float tmpx;
	float tmpy;
	float tmpcoef;

	tmpx = 1;
	tmpy = 1;
	while ((X0 + tmpx) <= Y0)
	{
		tmpcoef = tmpx / tmpy;
		if (tmpcoef > coef)
		{
			//printf("DRAW PIXEL [%f].[%f] BLANC\n", X0 + tmpx, X1 + tmpy);
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + tmpy++, X0 + tmpx, 0x00FFFFFF);
		}
		else
		{
			//printf("DRAW PIXEL [%f].[%f] BLANC\n", X0 + tmpx, X1 + tmpy);
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + tmpy, X0 + tmpx++, 0x00FFFFFF);
		}
	}
}

void	draw_diag2(t_mlx *mlx, t_env *env, float coef)
{
	printf(" diag 2 || X0,X1[%f|%f] -> Y0,Y1[%f|%f]\n", X0, X1, Y0, Y1);
	float tmpx;
	float tmpy;
	float tmpcoef;

	tmpx = 1;
	tmpy = -1;
	while ((X0 + tmpx) <= Y0)
	{
		tmpcoef = tmpx / tmpy;
		if (tmpcoef > coef)
		{
			printf("DRAW PIXEL [%f].[%f] BLANC\n", X0 + tmpx, X1 + tmpy);
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + tmpy, X0 + tmpx++, 0x00FFFFFF);
		}
		else if (tmpcoef < coef)
		{
			printf("DRAW PIXEL [%f].[%f] BLANC\n", X0 + tmpx, X1 + tmpy);
			mlx_pixel_put(mlx->ptr, mlx->win, X1 - tmpy++, X0 + tmpx, 0x00FFFFFF);
		}
		else
		{
			printf("DRAW PIXEL [%f].[%f] BLANC\n", X0 + tmpx, X1 + tmpy);
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + tmpy--, X0 + tmpx++, 0x00FFFFFF);
		}
	}
}

void	axial_swapper(t_env *env)
{
	float tmp;

	tmp = X0;
	X0 = Y0;
	Y0 = tmp;
	tmp = X1;
	X1 = Y1;
	Y1 = tmp;
}

void	draw_diag_select(t_mlx *mlx, t_env *env)
{
	float coef;
	float tmp;

	coef = (Y0 - X0) / (Y1 - X1);
	if (coef > 0)
	{
		if (Y0 < X0)
		{
			axial_swapper(env);
			draw_diag1(mlx, env, coef);
			axial_swapper(env);
		}
		else
			draw_diag1(mlx, env, coef);
	}
	else
	{
		if (Y0 < X0)
		{
			axial_swapper(env);
			draw_diag2(mlx, env, coef);
			axial_swapper(env);
		}
		else
			draw_diag2(mlx, env, coef);
	}
}
