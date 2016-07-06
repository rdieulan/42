/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:49:25 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/16 17:24:32 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hooker(int button, t_env *env)
{
	if (button == 1)
		printf("plop\n");
	else
		printf("unassigned mouse button = %d\n", button);
	return (0);
}
