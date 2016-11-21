/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:45:51 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/21 12:23:21 by rdieulan         ###   ########.fr       */
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

double	angle_norm(double angle)
{
	if (angle < 0)
		return (angle + 360);
	else if (angle > 360)
		return (angle - 360);
	else
		return (angle);
}

void	game(t_env *env)
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
