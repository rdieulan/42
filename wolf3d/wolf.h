/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:48:10 by rdieulan          #+#    #+#             */
/*   Updated: 2017/01/02 14:46:44 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"

# define WIN_W 1920
# define WIN_H 1080
# define B_UNIT 64
# define INIT_ANGLE 90
# define INIT_SPEED 20
# define ROTATE_SPEED 10
# define FOV 60
# define XMAP0 (int)((env->posx - mapx) / B_UNIT)
# define XMAP1 (int)((env->posx + mapx) / B_UNIT)
# define YMAP0 (int)((env->posy - mapy) / B_UNIT)
# define YMAP1 (int)((env->posy + mapy) / B_UNIT)

typedef struct	s_env
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bits;
	int			len;
	int			endian;
	char		*title;
	int			**map;
	int			map_memory;
	int			map_size;
	double		step;
	int			col;
	int			speed;
	double		posx;
	double		posy;
	double		rx;
	double		ry;
	double		wx;
	double		wy;
	int			nord;
	int			sud;
	int			est;
	int			ouest;
	double		angle;
	double		ray_angle;
	double		tmp_angle;
	int			red;
	int			blue;
	int			green;
	double		ground_grad;
	int			ground_lim;
	int			error;
}				t_env;

int				key_hooker(int kcode, t_env *env);
int				red_cross(int code, t_env *env);
void			game(t_env *env);
void			ray_set(t_env *env);
void			draw(t_env *env, double x, double y);
void			draw_ground(t_env *env, double x, double y);
void			color_ground(t_env *env, int i);
void			color_sky(t_env *env);
void			color_wall(t_env *env, double dist);
void			set_color_wall_north(t_env *env, double dist);
void			set_color_wall_south(t_env *env, double dist);
void			set_color_wall_west(t_env *env, double dist);
void			set_color_wall_east(t_env *env, double dist);
double			angle_norm(double angle);
void			load_map(char *map, t_env *env);
void			check_info_integrity(char **info, t_env *env);
void			check_line_integrity(char **line, t_env *env);
void			check_player_start(t_env *env);
void			ft_error(int error, t_env *env);
int				motion_notify(int x, int y, t_env *env);
#endif
