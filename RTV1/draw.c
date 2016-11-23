/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 13:24:44 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/22 22:14:02 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw(t_env *e, float x, float y, t_color color)
{
	int	nb;

	nb = (x * e->graph->bits) / 8 + (y * e->graph->len);
	if (nb > 0)
	{
		e->graph->addr[nb] = color.b;
		e->graph->addr[nb + 1] = color.g;
		e->graph->addr[nb + 2] = color.r;
	}
}
