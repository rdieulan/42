/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:03:21 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/14 19:18:46 by rdieulan         ###   ########.fr       */
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
	env->img = mlx_new_image(env->ptr, WIN_W, WIN_H);
	env->addr = mlx_get_data_addr(env->img, &(env->bits), &(env->len), &(env->endian));
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
			set_mandelbrot(env);
		else if (ft_strcmp(argv[1], "julia") == 0)
			set_julia(env);
		else if (ft_strcmp(argv[1], "newton") == 0)
			;//set_newton(env);
		else
			printf("Fractal inconnue\n");
	}
	else
		printf("trop ou trop eu d'arguments\n");
	return (0);
}
