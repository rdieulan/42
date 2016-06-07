/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:22:50 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/07 19:30:12 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/includes/libft.h"

# define D_SCALE 10
# define W_STEP 30
# define H_STEP 30
# define DEPTH 2
# define MATRIX env->matrix
# define DP env->depth
# define PXL env->pixel_matrix[i][j]
# define PXL_H env->pixel_matrix[i][j+1]
# define PXL_V env->pixel_matrix[i+1][j]
# define X0 env->fx[0]
# define X1 env->fx[1]
# define Y0 env->fy[0]
# define Y1 env->fy[1]
# define MLX env->mlx
# define COLOR color_gradient(env)

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	int				w;
	int				h;
}					t_mlx;

typedef struct		s_env
{
	struct s_mlx	*mlx;
	int				x;
	int				y;
	char			*title;
	int				scale;
	int				**matrix;
	int				***pixel_matrix;
	int				*fx;
	int				*fy;
	int				w_step;
	int				h_step;
	int				depth;
	int				nbstep;
	int				actual_step;
	float			grad_step;
	int				*grad;
	int				color;
	float			color_start;
	float			color_end;
}					t_env;

int					**get_matrix(char *file, t_env *env);
void				graphic_process(t_env *env);
void				draw(t_env *env);
void				draw_diag_select(t_env *env);
int					key_hooker(int keycode, t_env *env);
int					color_gradient(t_env *env);
#endif
