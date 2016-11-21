/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:23:17 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/21 12:23:15 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_map_info(char *line, t_env *env)
{
	char	**info;

	info = ft_strsplit(line, ':');
	check_info_integrity(info);
	if (ft_atoi(info[0]) > 1000 || ft_atoi(info[0]) < 0)
		ft_error(9);
	env->map_memory = ft_atoi(info[0]) + 2;
	env->map_size = env->map_memory * B_UNIT;
	env->posx = ((double)(ft_atoi(info[1]) + 1) * B_UNIT) +
				((double)B_UNIT / 2);
	env->posy = ((double)(ft_atoi(info[2]) + 1) * B_UNIT) +
				((double)B_UNIT / 2);
	env->map = (int**)malloc(sizeof(int*) * env->map_memory);
}

void	trace_edge(t_env *env)
{
	int	i;

	i = 0;
	env->map[0] = (int*)malloc(sizeof(int) * env->map_memory);
	env->map[env->map_memory - 1] = (int*)malloc(sizeof(int) * env->map_memory);
	while (i < env->map_memory)
	{
		env->map[0][i] = 1;
		env->map[env->map_memory - 1][i] = 1;
		i++;
	}
}

int		load_line(t_env *env, char *line, int count)
{
	int		j;
	char	**tmp;

	j = 1;
	env->map[count] = (int*)malloc(sizeof(int) * env->map_memory);
	tmp = ft_strsplit(line, ' ');
	check_line_integrity(tmp, env);
	env->map[count][0] = 1;
	while (j < env->map_memory - 1)
	{
		env->map[count][j] = ft_atoi(tmp[j - 1]);
		j++;
	}
	env->map[count][env->map_memory - 1] = 1;
	j = 1;
	count++;
	return (count);
}

void	load_map(char *map, t_env *env)
{
	int		fd;
	char	*line;
	int		count;

	count = 1;
	if ((fd = open(map, O_RDONLY)) != -1)
	{
		if ((get_next_line(fd, &line)) > 0)
		{
			get_map_info(line, env);
			trace_edge(env);
			while (get_next_line(fd, &line) > 0)
				count = load_line(env, line, count);
			if (count == 0)
				ft_error(5);
			if (count != env->map_memory - 1)
				ft_error(6);
		}
		else
			ft_error(5);
	}
	else
		ft_error(5);
}
