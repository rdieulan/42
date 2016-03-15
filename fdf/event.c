/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:53:47 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/15 12:03:01 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hooker(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	else
		printf("unassigned keycode : %d\n", keycode);
	return (0);
}
