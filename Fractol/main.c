/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:03:21 by rdieulan          #+#    #+#             */
/*   Updated: 2016/07/06 18:30:15 by rdieulan         ###   ########.fr       */
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

void	graphic_init(t_env *env)
{
	env->ptr = mlx_init();
	env->win = mlx_new_window(env->ptr, WIN_W, WIN_H, env->title);
	mlx_hook(env->win, 2, 1L << 0, key_hooker, env);
	mlx_mouse_hook(env->win, mouse_hooker, env);
}

double	module_light(double x, double y, char sign)
{
	if (sign == '+')
		return ((x * x) + (y * y));
	else if (sign == '-')
		return ((x * x) - (y * y));
	else
		return (-1);
}

int		main(int argc, char **argv)
{
	t_env *env;

	if (argc == 2)
	{
		env = env_init(argv[1]);
		graphic_init(env);
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			set_mandelbrot(env, 0);
		else if (ft_strcmp(argv[1], "julia") == 0)
			set_julia(env, 0);
		else if (ft_strcmp(argv[1], "custom") == 0)
			set_custom(env, 0);
		else
			ft_putstr("Fractal inconnue\n");
	}
	else
		ft_putstr("trop ou trop eu d'arguments\n");
	return (0);
}
