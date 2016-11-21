/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:35:47 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/21 12:22:50 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error2(int error)
{
	if (error == 6)
		ft_putstr("MAP : incorrect number of line\n");
	else if (error == 7)
		ft_putstr("PLAYER : cannot start inside a wall.\n");
	else if (error == 8)
		ft_putstr("PLAYER : cannot start ouside the map.\n");
	else
		ft_putstr("MAP CFG : Max size = 1000\n");
	exit(error);
}

void	ft_error(int error)
{
	ft_putstr("ERROR : ");
	if (error > 5)
		ft_error2(error);
	else
	{
		if (error == 1)
			ft_putstr("Wrong number of argument. Must be 1.\n");
		else if (error == 2)
			ft_putstr("MAP LINE : contains incorrect values.\n");
		else if (error == 3)
			ft_putstr("MAP LINE : incorrect number of values.\n");
		else if (error == 4)
			ft_putstr("MAP CFG : Wrong map header format !\n"
					"FORMAT : (u_int)size:(u_int)spawnX:(u_int)spawnY\n");
		else
			ft_putstr("FILE : incorrect input.\n");
		exit(error);
	}
}
