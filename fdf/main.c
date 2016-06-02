/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:59 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/02 14:46:47 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env	*env_init(char *title)
{
	t_env *env;
	env = (t_env*)malloc(sizeof(t_env));
	env->fx = (int *)malloc(sizeof(int) * 2);
	env->fy = (int *)malloc(sizeof(int) * 2);
	env->x = 0;
	env->y = 0;
	env->title = title;
	env->scale = D_SCALE;
	env->w_step = W_STEP;
	env->h_step = H_STEP;
	env->depth = DEPTH;
	return (env);
}

int		main(int argc, char **argv)
{
	t_env *env;

	env = env_init(argv[1]);
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
