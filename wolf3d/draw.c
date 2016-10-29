/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:24:44 by rdieulan          #+#    #+#             */
/*   Updated: 2016/10/29 19:16:12 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw(t_env *env, double x, double y)
{
	int	nb;

	nb = (x * env->bits) / 8 + (y * env->len);
	if (nb > 0)
	{
		env->addr[nb] = env->blue;
		env->addr[nb + 1] = env->green;
		env->addr[nb + 2] = env->red;
	}
}
