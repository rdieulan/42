/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:13:26 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/21 14:50:36 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_info_integrity(char **info, t_env *env)
{
	int	i;
	int	j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		if (info[j] && info[j][i])
		{
			while (info[j][i])
			{
				if (ft_isdigit((int)info[j][i]) == 0)
					ft_error(4, env);
				i++;
			}
		}
		else
			ft_error(4, env);
		j++;
	}
}

void	check_line_integrity(char **line, t_env *env)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i][0] != '1' && line[i][0] != '0') || line[i][1])
			env->error = 1;
		i++;
	}
	if (env->error == 1)
		ft_error(2, env);
	if (i != (env->map_memory - 2))
		ft_error(3, env);
}

void	check_player_start(t_env *env)
{
	int	x;
	int	y;

	x = env->posx / B_UNIT;
	y = env->posy / B_UNIT;
	if (x >= 0 && x < env->map_memory)
	{
		if (y >= 0 && y < env->map_memory)
		{
			if (env->map[x][y] == 1)
				ft_error(7, env);
		}
		else
			ft_error(8, env);
	}
	else
		ft_error(8, env);
}
