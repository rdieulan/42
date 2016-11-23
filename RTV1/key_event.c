/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:55:57 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 02:53:36 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	angle_rot(int kcode, t_env *e)
{
	if (kcode == 126)
		e->h_angle += M_PI / 12;
	if (kcode == 125)
		e->h_angle -= M_PI / 12;
	if (kcode == 124)
		e->v_angle += M_PI / 12;
	if (kcode == 123)
		e->v_angle -= M_PI / 12;
}

void	move(int kcode, t_env *e)
{
	if (kcode == 2)
		e->cam_pos.x += SPEED;
	if (kcode == 0)
		e->cam_pos.x -= SPEED;
	if (kcode == 13)
		e->cam_pos.z += SPEED;
	if (kcode == 1)
		e->cam_pos.z -= SPEED;
}

int		key_hooker(int kcode, t_env *e)
{
	if (kcode == 53)
		exit(0);
	else if (kcode == 123 || kcode == 124 || kcode == 125 || kcode == 126)
		angle_rot(kcode, e);
	else if (kcode == 0 || kcode == 1 || kcode == 2 || kcode == 13)
		move(kcode, e);
	else if (kcode == 12 || kcode == 14)
		;
	ft_strdel(&e->graph->addr);
	e->graph->img = mlx_new_image(e->graph->ptr, WIN_W, WIN_H);
	e->graph->addr = mlx_get_data_addr(e->graph->img, &(e->graph->bits),
			&(e->graph->len), &(e->graph->endian));
	ray_tracing(e);
	return (0);
}
