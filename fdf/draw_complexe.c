/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_complexe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:03:26 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/10 16:35:16 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		ft_draw_line1(t_env *env, float coeff_dir)
{
	float	i;
	float	j;
	float	tmp;

	i = 1;
	j = 1;
	env->nbstep = hypot(Y0 - X0, Y1 - X1);
	while ((X0 + j <= Y0 || X1 + i <= Y1) && X1 + i <= WSZ && X0 + j <= MENU)
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(MLX->ptr, MLX->win, X1 + i++, X0 + j, COLOR);
		else
			mlx_pixel_put(MLX->ptr, MLX->win, X1 + i, X0 + j++, COLOR);
	}
}

void		ft_draw_line2(t_env *env, float coeff_dir)
{
	float	i;
	float	j;
	float	tmp;

	j = -1;
	i = 1;
	env->nbstep = hypot(Y0 - X0, Y1 - X1);
	while ((X0 + j >= Y0 || X1 + i <= Y1) && X1 + i <= WSZ && X0 + j <= MENU)
	{
		tmp = j / i;
		if (tmp >= coeff_dir)
			mlx_pixel_put(MLX->ptr, MLX->win, X1 + i, X0 + j--, COLOR);
		else
			mlx_pixel_put(MLX->ptr, MLX->win, X1 + i++, X0 + j, COLOR);
	}
}

void		draw_diag_select(t_env *env)
{
	int		i;
	float	coeff_dir;

	i = 0;
	env->actual_step = 0;
	coeff_dir = 0;
	if (Y1 == X1)
		while (i <= (env->nbstep = Y0 - X0) && Y0 + i <= HSZ)
			mlx_pixel_put(MLX->ptr, MLX->win, Y1, Y0 + i++, COLOR);
	else if (Y0 == X0)
		while (i <= (env->nbstep = Y1 - X1) && X1 + i <= WSZ && X0 < MENU)
			mlx_pixel_put(MLX->ptr, MLX->win, X1 + i++, X0, COLOR);
	else
	{
		coeff_dir = ((float)Y0 - (float)X0) / ((float)Y1 - (float)X1);
		if (coeff_dir > 0)
			ft_draw_line1(env, coeff_dir);
		else
			ft_draw_line2(env, coeff_dir);
	}
}
