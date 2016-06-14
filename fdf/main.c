* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:59 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/14 14:54:44 by rdieulan         ###   ########.fr       */
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
	env->grad = (int *)malloc(sizeof(int) * 21);
	return (env);
}

void	gradient_init(t_env *env)
{
	env->grad[20] = 0x3EE500;
	env->grad[19] = 0x4EE100;
	env->grad[18] = 0x5FDD00;
	env->grad[17] = 0x70DA00;
	env->grad[16] = 0x80D600;
	env->grad[15] = 0x91D300;
	env->grad[14] = 0xA2CF00;
	env->grad[13] = 0xB2CB00;
	env->grad[12] = 0xC3C800;
	env->grad[11] = 0xD4C400;
	env->grad[10] = 0xE5C100;
	env->grad[9] = 0xE5AE00;
	env->grad[8] = 0xE59B00;
	env->grad[7] = 0xE58800;
	env->grad[6] = 0xE57500;
	env->grad[5] = 0xE56200;
	env->grad[4] = 0xE54F00;
	env->grad[3] = 0xE53C00;
	env->grad[2] = 0xE52900;
	env->grad[1] = 0xE51600;
	env->grad[0] = 0xE50300;
}

int		main(int argc, char **argv)
{
	t_env *env;

	env = env_init(argv[1]);
	gradient_init(env);
	if (argc == 2)
		env->matrix = get_matrix(argv[1], env);
	else if (argc == 1)
	{
		printf("argument missing.\n");
		return (0);
	}
	else
	{
		printf("too many argument.\n");
		return (0);
	}
	graphic_process(env);
	return (0);
}
