/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:45:51 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/15 20:39:41 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*env_init(char *title)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->title = title;
	env->angle = INIT_ANGLE;
	env->speed = INIT_SPEED;
	env->step = (double)FOV / WIN_W;
	env->blue = 0;
	env->red = 0;
	env->green = 0;
	env->error = 0;
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
	mlx_hook(env->win, 6, 1l << 0, motion_notify, env);
	mlx_hook(env->win, 17, (1L << 17), red_cross, env);
	mlx_loop(env->ptr);
}

void	check_info_integrity(char **info)
{
	int i;
	int j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		if (info[j] && info[j][i])
		{
			while (info[j][i])
			{
				if (ft_isdigit((int)info[j][i]) == 0)
					ft_error(4);
				i++;
			}
		}
		else
			ft_error(4);
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
		ft_error(2);
	if (i != (env->map_memory - 2))
		ft_error(3);
}

void	get_map_info(char *line, t_env *env)
{
	char	**info;

	info = ft_strsplit(line, ':');
	check_info_integrity(info);
	if (ft_atoi(info[0]) > 1000 || ft_atoi(info[0]) < 0)
		ft_error(9);
	env->map_memory = ft_atoi(info[0]) + 2;
	env->map_size = env->map_memory * B_UNIT;
	env->posx = ((double)(ft_atoi(info[1]) + 1) * B_UNIT) + ((double)B_UNIT / 2);
	env->posy = ((double)(ft_atoi(info[2]) + 1) * B_UNIT) + ((double)B_UNIT / 2);
	env->map = (int **)malloc(sizeof(int *) * env->map_memory);
}

void	trace_edge(t_env *env)
{
	int i;

	i = 0;
	env->map[0] = (int *)malloc(sizeof(int) * env->map_memory);
	env->map[env->map_memory - 1] = (int *)malloc(sizeof(int) * env->map_memory);
	while (i < env->map_memory)
	{
		env->map[0][i] = 1;
		env->map[env->map_memory - 1][i] = 1;
		i++;
	}
}

void	load_map(char *map, t_env *env)
{
	int		fd;
	char	*line;
	char	**tmp;
	int		i;
	int		j;

	i = 1;
	j = 1;
	if ((fd = open(map, O_RDONLY)) != -1)
	{
		if ((get_next_line(fd, &line)) > 0)
		{
			get_map_info(line, env);
			trace_edge(env);
			while (get_next_line(fd, &line) > 0)
			{
				env->map[i] = (int *)malloc(sizeof(int) * env->map_memory);
				tmp = ft_strsplit(line, ' ');
				check_line_integrity(tmp, env);
				env->map[i][0] = 1;
				while (j < env->map_memory - 1)
				{
					env->map[i][j] = ft_atoi(tmp[j - 1]);
					j++;
				}
				env->map[i][env->map_memory - 1] = 1;
				j = 1;
				i++;
			}
			if (i == 0)
				ft_error(5);
			if (i != env->map_memory - 1)
				ft_error(6);
		}
		else
			ft_error(5);
	}
	else
		ft_error(5);
}

void	ft_error(int error)
{
	if (error == 1)
		ft_putstr("Wrong number of argument. Must be 1\n");
	else
	{
		ft_putstr("ERROR : ");
		if (error == 2)
			ft_putstr("MAP LINE : contains incorrect values\n");
		if (error == 3)
			ft_putstr("MAP LINE : incorrect number of values\n");
		if (error == 4)
			ft_putstr("MAP CFG : only positive digit allowed, split ':'\n"
					"FORMAT : (u_int)size:(u_int)spawnX:(u_int)spawnY\n");
		if (error == 5)
			ft_putstr("FILE : incorrect input\n");
		if (error == 6)
			ft_putstr("MAP : incorrect number of line\n");
		if (error == 7)
			ft_putstr("PLAYER : cannot start inside a wall\n");
		if (error == 8)
			ft_putstr("PLAYER : cannot start outside the map\n");
		if (error == 9)
			ft_putstr("MAP CFG : Max size = 1000\n");
	}
	if (error != 0)
		exit(error);
}

void	check_player_start(t_env *env)
{
	int x;
	int y;

	x = env->posx / B_UNIT;
	y = env->posy / B_UNIT;
	if (x >= 0 && x < env->map_memory)
	{
		if (y >= 0 && y < env->map_memory)
		{
			if (env->map[x][y] == 1)
				ft_error(7);
		}
		else
				ft_error(8);
	}
	else
		ft_error(8);
}

double		angle_norm(double angle)
{
	if (angle < 0)
		return (angle + 360);
	else if (angle > 360)
		return (angle - 360);
	else
		return (angle);
}

void		game(t_env *env)
{
		ray_set(env);
		mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2)
	{
		env = env_init(argv[1]);
		load_map(argv[1], env);
		check_player_start(env);
		graphic_init(env);
	}
	else
		ft_error(1);
	return (0);
}
