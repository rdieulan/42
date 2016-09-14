/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:49:25 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 18:12:40 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		m_hooker(int button, int x, int y, t_env *env)
{
	x = y;
	if (button == 5 || button == 7)
		zoom_io(69, env);
	else if (button == 4 || button == 6)
		zoom_io(78, env);
	else
		ft_putnbr(button);
	win_refresh(env);
	return (0);
}
