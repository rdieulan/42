/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:22:50 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/17 19:47:42 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define D_SCALE 20
# define D_WIDTH (i * D_SCALE) + D_SCALE - env->matrix[i][j]
# define D_HEIGHT (j * D_SCALE) + D_SCALE - env->matrix[i][j]
# define PXL env->pixel_matrix[i][j]
# define PXL_H env->pixel_matrix[i][j+1]
# define PXL_V env->pixel_matrix[i+1][j]


typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			w;
	int			h;
}				t_mlx;

typedef struct	s_env
{
	int			x;
	int			y;
	char		*title;
	int			**matrix;
	int			***pixel_matrix;
}				t_env;

int		**get_matrix(char *file, t_env *env);
void	graphic_process(t_env *env);
void	draw(t_env *env, t_mlx *mlx);
int		key_hooker(int keycode, t_mlx *mlx);
#endif
