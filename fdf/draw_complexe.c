/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:03:26 by rdieulan          #+#    #+#             */
/*   Updated: 2016/05/21 22:42:29 by rdieulan         ###   ########.fr       */
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
	if (Y1 == X1 || Y0 == X0)
		




		coeff_dir = ((float)Y0 - (float)X0) / ((float)Y1 - (float)X1);
	if (X1 > X0)
		while (i < X1 - X0)
			mlx_pixel_put(mlx->ptr, mlx->win, X0 + i++, Y0, 0x00FF00FF);
	else if (X1 < X0)
		while (i < X0 - X1)
			mlx_pixel_put(mlx->ptr, mlx->win, X1 + i++, Y1, 0x00FF0000);
	else if (coeff_dir < 0)
	{
		/*if (X1 - X0 < 0)
			ft_draw_line3(mlx, env, coeff_dir);
		else
			ft_draw_line2(mlx, env, coeff_dir);*/
	}
	else
	{/*
		if (X1 - X0 < 0 && Y1 - Y0 < 0)
			ft_draw_line4(mlx, env, coeff_dir);
		else
			ft_draw_line1(mlx, env, coeff_dir);*/
	}
}
