/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:59 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/15 16:20:22 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->x = 0;
	env->y = 0;
	env->title = argv[1];
	if (argc == 2)
		env->matrix = get_matrix(argv[1], env);
	else
	{
		printf("argument missing.\n");
		return (0);
	}
	graphic_process(env);
	return (0);
}