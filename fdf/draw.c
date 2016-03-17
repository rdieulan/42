/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:53:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/17 19:47:40 by rdieulan         ###   ########.fr       */
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
			mlx_pixel_put(mlx->ptr, mlx->win, D_HEIGHT, D_WIDTH, 0x0000FF00); // VERT
			PXL[0] = D_HEIGHT;
			PXL[1] = D_WIDTH;
			if (i == 2 && j == 11)
				printf("[%d][%d] ==> coord [%d][%d]\n`",i , j, D_HEIGHT, D_WIDTH);
			j++;
		}
		i++;
	}
}

void	draw_bren(t_mlx *mlx, int x1, int x2, int y1, int y2)
{
	int dx;
	int dy;
	int cumul;
	int x;
	int y;

	x = x1;
	y = x2;
	dx = y1 - x1;
	dy = y2 - x2;
	cumul = dx / 2;
	while (x <= y1)
	{
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			y++;
		}
		mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0x00FFFFFF); // BLANC
		//printf("\nDRAW PIXEL [%d].[%d] BLANC\n", x, y);
		x++;
	}
}

void	draw_seg(t_mlx *mlx, int x1, int x2, int y1, int y2)
{
	//if (x1 == 40 && x2 == 220 && y1 == 30 && y2 == 230)
		//printf ("TRACE ORDER [%d][%d] -> [%d][%d]\n", x1, x2, y1, y2);

	if (x1 == y1)
	{
		while (x2 <= y2)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, x1, x2, 0x00FF0000); // ROUGE
			//printf("DRAW PIXEL [%d].[%d] ROUGE\n", x1, x2);
			x2++;
		}
	}
	else if (x2 == y2)
	{
		while (x1 <= y1)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, x1, x2, 0x000000FF); // BLEU
			//printf("DRAW PIXEL [%d].[%d] BLEU\n", x1, x2);
			x1++;
		}
	}
	else
		draw_bren(mlx, x1, x2, y1, y2);
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
			//printf("WHILE j(%d) < y(%d)\n", j, env->y);
			if (j < env->y - 1) // horizontal
			{
				//printf("j(%d) < y(%d) | HORIZONTAL \n", j, env->y);
				draw_seg(mlx, PXL[0], PXL[1], PXL_H[0], PXL_H[1]);
			}
			if (i < env->x - 1) // vertical
			{
				//printf("i(%d) < x(%d) | VERTICAL \n", i, env->x);
				draw_seg(mlx, PXL[0], PXL[1], PXL_V[0], PXL_V[1]);
			}
			j++;
		}
		i++;
	}
}
