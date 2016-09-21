/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:24:02 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/21 18:15:46 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"

# define WIN_H 800
# define WIN_W 800

typedef struct	s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bits;
	int			len;
	int			endian;
	double		zoom;
	double		it_max;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			red;
	int			green;
	int			blue;
	char		*title;
	int			posx;
	int			posy;
}				t_env;

void			event_start(t_env *env);
void			draw(t_env *env, double x, double y);
void			set_mandelbrot(t_env *env);
void			mandel_scan(t_env *env);
void			set_julia(t_env *env);
void			julia_scan(t_env *env);
void			set_custom(t_env *env);
void			custom_scan(t_env *env);
double			module_light(double x, double y, char sign);
int				key_hooker(int kcode, t_env *env);
int				m_hooker(int button, int x, int y, t_env *env);
int				motion_notify(int x, int y, t_env *env);
void			win_refresh(t_env *env);
void			zoom_io(int kcode, int x, int y, t_env *env);

#endif
