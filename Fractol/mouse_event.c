/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:49:25 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 15:12:58 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		m_hooker(int button, t_env *env)
{
	ft_putnbr(button);
	ft_putstr(" : MOUSE\n");
	ft_putstr(env->title);
//	ft_putnbr((int)env->zoom);
//	ft_putchar('\n');
//	if (button == 5 || button == 7)
//		zoom_io(69, env);
//	else if (button == 4 || button == 6)
//		zoom_io(78, env);
//	else
//		ft_putnbr(button);
	ft_putstr("BEFORE REFRESH\n");
//	*win_refresh(env);
	return (0);
}
