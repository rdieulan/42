/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:03:26 by rdieulan          #+#    #+#             */
/*   Updated: 2016/05/27 20:59:08 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		ft_draw_line1(t_mlx *mlx, t_env *env, float coeff_dir)
{
	float	i;
	float	j;
	float	tmp;

	i = 1;
	j = 1;
	while (X0 + j < X1 || Y0 + i < Y1)
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(mlx->ptr, mlx->win, X0 + j, Y0 + i++, 0x00FFFFFF);
		else
			mlx_pixel_put(mlx->ptr, mlx->win, X0 + j++, Y0 + i, 0x00FFFFFF);
	}
}

void		ft_draw_line2(t_mlx *mlx, t_env *env, float coeff_dir)
{
	float	i;
	float	j;
	float	tmp;

	j = -1;
	i = 1;
	while (X1 + j > X0 || Y1 + i < Y0)
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + j--, Y1 + i, 0x00FFFFFF);
		else
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + j, Y1 + i++, 0x00FFFFFF);
	}
}

void		ft_draw_line3(t_mlx *mlx, t_env *env, float coeff_dir)
{
	float	i;
	float	j;
	float	tmp;

	j = -1;
	i = 1;
	while (X0 + j > X1 || Y0 + i < Y1)
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(mlx->ptr, mlx->win, X0 + j--, Y0 + i, 0x00FFFFFF);
		else
			mlx_pixel_put(mlx->ptr, mlx->win, X0 + j, Y0 + i++, 0x00FFFFFF);
	}
}

void		ft_draw_line4(t_mlx *mlx, t_env *env, float coeff_dir)
{
	float	i;
	float	j;
	float	tmp;

	i = 1;
	j = 1;
	while (X1 + j < X0 || Y1 + i < Y0)
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + j, Y1 + i++, 0x00FFFFFF);
		else
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + j++, Y1 + i, 0x00FFFFFF);
	}
}

void	draw_diag_select(t_mlx *mlx, t_env *env)
{
	int i;
	float coeff_dir;

	i = 0;
	coeff_dir = 0;
	//printf("diag select. X0 = %d, X1 = %d, Y0 = %d, Y1 = %d\n", X0, X1, Y0, Y1);
	if (Y1 == X1)
	{
		printf("Drawing Vertical\n");
		while (i < Y0 - X0)
		{
			printf("Drawing %d:%d\n", Y0, Y1 + i);
			mlx_pixel_put(mlx->ptr, mlx->win, Y1 + i++, Y0, 0x00FF00FF);
		}
	}
	else if (Y0 == X0)
	{
		printf("Drawing horizontal\n");
		while (i < Y1 - X1)
		{
			printf("Drawing %d:%d\n", X0, X1 + i);
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + i++, X0, 0x00FF0000);// RED
		}
	}
	else
	{
		coeff_dir = ((float)Y0 - (float)X0) / ((float)Y1 - (float)X1);
		printf("coeff calculated = %f\n", coeff_dir);
		/*if (coeff_dir > 0)
		{
			if (Y1 - X1 > 0)
			{
				printf("drawing diag 1\n");
				ft_draw_line1(mlx, env, coeff_dir);
			}
			else
			{
				printf("drawing diag 2\n");
				ft_draw_line2(mlx, env, coeff_dir);
			}
		}
		else
		{
			if (Y1 - X1 > 0)
			{
				printf("drawing diag 3\n");
				ft_draw_line3(mlx, env, coeff_dir);
			}
			else
			{
				printf("drawing diag 4\n");
				ft_draw_line4(mlx, env, coeff_dir);
			}
		}*/
	}
}
