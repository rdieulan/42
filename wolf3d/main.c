/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:45:51 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 17:45:31 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*env_init(char *title)
{
	t_env *env;
	env = (t_env*)malloc(sizeof(t_env));
	env->title = title;
	env->p_angle = 90;
	return (env);
}

void	graphic_init(t_env *env)
{
	env->ptr = mlx_init();
	env->win = mlx_new_window(env->ptr, WIN_W, WIN_H, env->title);
	env->img = mlx_new_image(env->ptr, WIN_W, WIN_H);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len),
			&(env->endian));
	game(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	mlx_hook(env->win, 2, 1L << 0, key_hooker, env);
	mlx_loop(env->ptr);
}

void	get_map_info(char *line, t_env *env)
{
	char	**info;

	info = ft_strsplit(line, ':');
	env->map_size = ft_atoi(info[0]);
	env->posx = ((double)ft_atoi(info[1]) * BLOCK_UNIT) + (BLOCK_UNIT / 2);
	env->posy = ((double)ft_atoi(info[2]) * BLOCK_UNIT) + (BLOCK_UNIT / 2);
	env->map = (int **)malloc(sizeof(int *) * env->map_size);
}

void	load_map(char *map, t_env *env)
{
	int fd;
	char *line;
	char **tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open(map, O_RDONLY);
	get_next_line(fd, &line);
	get_map_info(line, env);
	while (get_next_line(fd, &line) > 0)
	{
		env->map[i] = (int *)malloc(sizeof(int) * env->map_size);
		tmp = ft_strsplit(line, ' ');
		while (j < env->map_size)
		{
			env->map[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		j = 0;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_env *env;

	if (argc == 2)
	{
		env = env_init(argv[1]);
		load_map(argv[1], env);
		printf("%d:%f:%f:%f\n", env->map_size, env->posx, env->posy, env->p_angle);
		graphic_init(env);
		game(env);
	}
	else
		ft_putstr("error");
	return (0);
}
