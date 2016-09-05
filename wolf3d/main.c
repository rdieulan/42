/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:45:51 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/05 16:11:52 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*env_init(char *title)
{
	t_env *env;
	env = (t_env*)malloc(sizeof(t_env));
	env->title = title;
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

int main(int argc, char **argv)
{
	t_env *env;

	if (argc == 2)
	{
		env = env_init(argv[1]);
		graphic_init(env);
	}
	else
		ft_putstr("error");
	return (0);
}
