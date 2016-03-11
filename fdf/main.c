/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:59 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/11 21:47:38 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	gui_init(t_mlx *mlx, int x, int y, char *title)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, x, y, title);
}

void	env_init(t_env *env)
{
	env->x = 0;
	env->y = 0;
}

/*void	do_key_press(void *win, t_mlx *mlx, unsigned key)
{
	if (key == 53)
		exit(0);
}*/

int		*str_to_int_tab(char *str, t_env *env)
{
	int		*matrix_line;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(str, ' ');
	while (tmp[i] != NULL)
		i++;
	matrix_line = (int *)malloc(sizeof(int) * i);
	while (tmp[i] != NULL)
	{
		printf("BOUCLE CONVERSION STR -> INT");
		matrix_line[i] = ft_atoi(tmp[i]);
		printf("matrix[%d] = %d\n", i, matrix_line[i]);
		i++;
	}
	return (matrix_line);
}

int		**get_matrix(int fd, t_env *env)
{
	int		**matrix;
	char	*line;
	int		i;
	int ln;

	i = 0;
	ln = 100; /* calculer nombre de lignes */
	matrix = (int **)malloc(sizeof(int *) * ln);
	while (get_next_line(fd, &line) > 0)
	{
		printf("BOUCLE GET_MATRIX\n");
		matrix[i] = str_to_int_tab(line, env);
		i++;
	}
	env->x = i - 1;
	return (matrix);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		**matrix;
	t_mlx	*mlx;
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env_init(env);
	printf("env initialized.\n");
	printf("env x = %d\nenv y = %d\n", env->x, env->y);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("fd value = %d\n", fd);
		matrix = get_matrix(fd, env);
		printf("matrix[0][0] = %d.\n", matrix[0][0]);
	}
	else
	{
		printf("argument missing.\n");
		return (0);
	}
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	gui_init(mlx, env->x, env->y, "FENETRE");
	return (0);
}
