/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:24:02 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/14 19:22:56 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

# define WIN_H 1000
# define WIN_W 1200

typedef struct	s_env
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bits;
	int		len;
	int		endian;
	double	zoom;
	int		it_max;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	image_x;
	double	image_y;
	int		red;
	int		green;
	int		blue;
	char	*title;
}				t_env;

void	draw(t_env *env, float x, float y);
void	set_mandelbrot(t_env *env);
void	set_julia(t_env *env);
double	module_light(double x, double y, char sign);
//void	set_julia(t_env *env);
//void	set_newton(t_env *env);

#endif
