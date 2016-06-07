/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:11:52 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/07 19:25:11 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		*str_int_to_tab(char *str, t_env *env)
{
	int		*matrix_line;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(str, ' ');
	while (tmp[i] != NULL)
		i++;
	env->y = i;
	matrix_line = (int *)malloc(sizeof(int) * i--);
	while (i >= 0)
	{
		matrix_line[i] = ft_atoi(tmp[i]);
		i--;
	}
	return (matrix_line);
}

int		line_counter(char *file, t_env *env)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		i++;
	env->x = i;
	return (i);
}

int		**get_matrix(char *file, t_env *env)
{
	int		**matrix;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	matrix = (int **)malloc(sizeof(int *) * line_counter(file, env));
	while (get_next_line(fd, &line) > 0)
		matrix[i++] = str_int_to_tab(line, env);
	return (matrix);
}
