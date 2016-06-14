/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:02:26 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/14 18:43:08 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_env *env, float x, float y)
{
	int nb;

	nb = (x * env->bits) / 8 + (y * env->len);
	env->addr[nb] = env->blue;
	env->addr[nb + 1] = env->green;
	env->addr[nb + 2] = env->red;
	env->blue = 0;
	env->green = 0;
	env->red = 0;
}
