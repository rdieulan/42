/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 12:45:27 by rdieulan          #+#    #+#             */
/*   Updated: 2016/10/11 18:57:16 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	color_ground(t_env *env)
{
	env->red = 0;
	env->green = 150;
	env->blue = 0;
}

void	color_sky(t_env *env)
{
	env->red = 0;
	env->green = 0;
	env->blue = 150;
}

void	color_wall(t_env *env)
{
	double	x;
	double	y;
	double	cx;
	double	cy;

	env->blue = 0;
	env->red = 0;
	env->green = 0;
	x = env->wx * BLOCK_UNIT;
	y = env->wy * BLOCK_UNIT;
	cx = x - (((int)env->wx + 1) * BLOCK_UNIT);
	cy = y - (((int)env->wy + 1) * BLOCK_UNIT);
	printf("%f | %f\n", x, y);
	if ((int)x % BLOCK_UNIT == 0 && (int)y % BLOCK_UNIT == 0)
		printf("BLACK [%d]: {%f:%f}\n",env->col, x, y);
	else
	{
		printf("COLOR [%d]: (%f)\n",env->col, env->ray_angle);
		if (cx >= -1 && cx <= 1)
		{
			printf("CX = %f  ", cx);
			if (env->posx >= x)
			{
				printf("RED\n");
				env->red = 255;
			}
			else
			{
				printf("BLUE\n");
				env->blue = 255;
			}
		}
		else if (cy >= -1 && cx <= 1)
		{
			printf("CY = %f  ", cy);
			if (env->posy >= y)
			{
				printf("GREEN\n");
				env->green = 255;
			}
			else
			{
				printf("YELLOW\n");
				env->red = 255;
				env->green = 255;
			}
		}
		else
			;
	}
}
