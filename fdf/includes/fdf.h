/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:22:50 by rdieulan          #+#    #+#             */
/*   Updated: 2016/05/27 19:45:45 by rdieulan         ###   ########.fr       */
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
# define D_WIDTH ((i + 1) * D_SCALE) - (env->matrix[i][j] * 2)
# define D_HEIGHT ((i + j + 1) * D_SCALE)
# define PXL env->pixel_matrix[i][j]
# define PXL_H env->pixel_matrix[i][j+1]
# define PXL_V env->pixel_matrix[i+1][j]
# define X0 env->fx[0]
# define X1 env->fx[1]
# define Y0 env->fy[0]
# define Y1 env->fy[1]


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
	int			*fx;
	int			*fy;
}				t_env;

int		**get_matrix(char *file, t_env *env);
void	graphic_process(t_env *env);
void	draw(t_env *env, t_mlx *mlx);
void	draw_diag_select(t_mlx *mlx, t_env *env);
int		key_hooker(int keycode, t_mlx *mlx);
#endif
