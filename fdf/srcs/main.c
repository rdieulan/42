/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:19:59 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/02 18:42:50 by rdieulan         ###   ########.fr       */
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
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	k = 0;
	matrix_line = NULL;
	tmp = NULL;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			j = 0;
			while (str[i] != ' ')
			{
				tmp[j] = str[i];
				j++;
				i++;
			}
			matrix_line[k++] = ft_atoi(tmp);
		}
	}
	env->y = k - 1;
	return (matrix_line);
}

int		**get_matrix(int fd, t_env *env)
{
	int		**matrix;
	char	*line;
	int		i;

	i = 0;
	matrix = NULL;
	while (get_next_line(fd, &line) > -1)
	{
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
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		matrix = get_matrix(fd, env);
	}
	else
		return (0);
	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	gui_init(mlx, env->x, env->y, "FENETRE");
}
