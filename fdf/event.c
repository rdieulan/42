/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:53:47 by rdieulan          #+#    #+#             */
/*   Updated: 2016/05/31 18:15:29 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hooker(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69)
		env->scale += 5;
	else if (keycode == 78)
		env->scale -= 5;
	else
		printf("unassigned keycode : %d\n", keycode);
	mlx_clear_window(MLX->ptr, MLX->win);
	draw(env);
	return (0);
}
