/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:53:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/05/31 18:06:47 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel_pattern(t_env *env)
{
	int i;
	int j;

	env->pixel_matrix = (int ***)malloc(sizeof(int **) * (env->x + 1));
	i = 0;
	printf("env->x = %d\n",env->x);
	while (i < env->x)
	{
		j = 0;
		env->pixel_matrix[i] = (int **)malloc(sizeof(int *) * (env->y + 1));
		while (j < env->y)
		{
			PXL = (int *)malloc(sizeof(int) * 2);
			PXL[0] = D_WIDTH;
			PXL[1] = D_HEIGHT;
			//printf("pixel [%d][%d] value [%d][%d]\n", i, j, D_WIDTH, D_HEIGHT);
			j++;
		}
		i++;
	}
	printf("FIN PIXEL PATTERN\n");
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
			printf("|||||||||| NEW TRACE y:%d: x:%d |||||||||||\n", X0, X1);
			if (j < env->y - 1) // horizontal
			{
				Y0 = PXL_H[0];
				Y1 = PXL_H[1];
				printf("	H -> %d:%d\n", Y0, Y1);
				draw_diag_select(env);
			}
			if (i < env->x - 1) // vertical
			{
				Y0 = PXL_V[0];
				Y1 = PXL_V[1];
				printf("	V -> %d:%d\n", Y0, Y1);
				draw_diag_select(env);
			}
			j++;
		}
		i++;
	}
	printf("FIN DRAW\n");
	printf("env->x = %d\n",env->x);
}
