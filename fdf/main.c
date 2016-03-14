/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:59 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/14 18:38:27 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	int		**matrix;
	t_mlx	*mlx;
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	printf("env initialized.\n");
	printf("env x = %d\nenv y = %d\n", env->x, env->y);
	if (argc == 2)
	{
		matrix = get_matrix(argv[1], env);
		printf("matrix[2][2] = %d.\n", matrix[2][2]);
	}
	else
	{
		printf("argument missing.\n");
		return (0);
	}
	printf("env x = %d\nenv y = %d\n", env->x, env->y);
	graphic_process(env);
	return (0);
}
