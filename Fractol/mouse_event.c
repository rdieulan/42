/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:49:25 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/21 15:36:15 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		m_hooker(int button, int x, int y, t_env *env)
{
	if (button == 5 || button == 7)
		zoom_io(69, x, y, env);
	else if (button == 4 || button == 6)
		zoom_io(78, x, y, env);
	else
		ft_putnbr(button);
	win_refresh(env);
	return (0);
}
