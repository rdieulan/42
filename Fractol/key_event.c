/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:42:30 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/16 16:45:44 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int		key_hooker(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	else
		printf("unassigned key code = %d\n", keycode);
	return (0);
}
