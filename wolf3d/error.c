/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:35:47 by rdieulan          #+#    #+#             */
/*   Updated: 2017/01/02 14:37:16 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error2(int error, t_env *env)
{
	if (error == 6)
		ft_putstr("MAP : incorrect number of line\n");
	if (error == 7)
		ft_putstr("PLAYER : cannot start inside a wall.\n");
	if (error == 8)
		ft_putstr("PLAYER : cannot start ouside the map.\n");
	if (error == 9)
		ft_putstr("MAP CFG : Max size = 1000\n");
	if (env != NULL)
	{
		ft_freeiarray_2d(env->map, env->map_memory);
		free(env);
		env = NULL;
	}
	exit(error);
}

void	ft_error(int error, t_env *env)
{
	if (error != 0)
		ft_putstr("ERROR : ");
	if (error > 5)
		ft_error2(error, env);
	else
	{
		if (error == 1)
			ft_putstr("Wrong number of argument. Must be 1.\n");
		if (error == 2)
			ft_putstr("MAP LINE : contains incorrect values.\n");
		if (error == 3)
			ft_putstr("MAP LINE : incorrect number of values.\n");
		if (error == 4)
			ft_putstr("MAP CFG : Wrong map header format !\n"
					"FORMAT : (u_int)size:(u_int)spawnX:(u_int)spawnY\n");
		if (error == 5)
			ft_putstr("FILE : incorrect input.\n");
		if (env != NULL)
		{
			ft_freeiarray_2d(env->map, env->map_memory);
			free(env);
			env = NULL;
		}
		exit(error);
	}
}
