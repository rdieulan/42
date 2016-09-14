/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:01:21 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 18:02:14 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ray_set(t_env *env)
{
	double	start;
	double	ray_angle;
	double	proj_dist;
	int		col;

	proj_dist = (PROJ_W / 2) / tan(FOV / 2);
	ray_angle = FOV / PROJ_W;
	start = env->p_angle + (FOV / 2);
	col = 0;
	while (col < PROJ_W)
	{
		//ray_cast to the wall
		//record distance
		//add ray_angle
	}
}

void	game(t_env *env)
{

}
