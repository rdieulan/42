/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:03:21 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 15:15:07 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*env_init(char *title)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->title = title;
	return (env);
}

void		graphic_init(t_env *env)
{
	env->ptr = mlx_init();
	env->win = mlx_new_window(env->ptr, WIN_W, WIN_H, env->title);
}

double		module_light(double x, double y, char sign)
{
	if (sign == '+')
		return ((x * x) + (y * y));
	else if (sign == '-')
		return ((x * x) - (y * y));
	else
		return (-1);
}

int			main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2)
	{
		env = env_init(argv[1]);
		graphic_init(env);
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			set_mandelbrot(env);
		else if (ft_strcmp(argv[1], "julia") == 0)
			set_julia(env);
		else if (ft_strcmp(argv[1], "custom") == 0)
			set_custom(env);
		else
			ft_putstr("Usage : ./fractol [julia | mandelbrot | custom].\n");
	}
	else
		ft_putstr("Wrong number of parameter ( must be 1 ).\n");
	mlx_mouse_hook(env->win, m_hooker, env);
	mlx_hook(env->win, 2, 1L << 0, key_hooker, env);
	mlx_hook(env->win, 6, 1L << 0, motion_notify, env);
	mlx_loop(env->ptr);
	return (0);
}
