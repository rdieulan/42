/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:01:43 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 06:11:51 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"
# include "libvec/include/lib_vec.h"
# include <math.h>
# include <fcntl.h>

# define WIN_W 700
# define WIN_H 500
# define FOV 120
# define SPEED 300
# define SPHERE 1
# define PLANE 2
# define CONE 3
# define CYL 4
# define SPOT 5
# define MAX_FLOAT 3.402823E+38F

typedef struct	s_color
{
	float			r;
	float			g;
	float			b;
}				t_color;

typedef struct	s_graph
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bits;
	int		len;
	int		endian;
	char	*title;
}				t_graph;

typedef struct	s_env
{
	struct s_graph	*graph;
	struct s_obj	*obj;
	t_vec			cam_pos;
	t_vec			sp_pos;
	float			h_angle;
	float			v_angle;
	int				oid;
	int				secu;
}				t_env;

typedef struct	s_obj
{
	int				id;
	int				type;
	t_vec			pos;
	float			angle;
	float			rayon;
	t_vec			dir;
	t_vec			normale;
	t_vec			inters;
	t_color			color;
	struct s_obj	*next;
}				t_obj;

void			draw(t_env *e, float x, float y, t_color color);
void			ray_tracing(t_env *e);
void			start_color(t_env *e);
void			point_color(t_env *e);
void			init_obj(char *file, t_env *e);
int				key_hooker(int kcode, t_env *e);
int				red_cross(int code, t_env *e);
void			parse_camera(t_env *e, int fd, char *line);
void			parse_sphere(t_env *e, int fd, char *line);
void			parse_plan(t_env *e, int fd, char *line);
void			parse_light(t_env *e, int fd, char *line);
void			parse_cone(t_env *e, int fd, char *line, int i);
void			parse_cyl(t_env *e, int fd, char *line, int i);
void			get_pos(t_obj *obj, char **param, t_env *e);
void			get_color(t_obj *obj, char **param, t_env *e);
void			get_dir(t_obj *obj, char **param, t_env *e);
void			get_rayon(t_obj *obj, char **param, t_env *e);
void			get_angle(t_obj *obj, char **param, t_env *e);
void			add_object(t_env *e, t_obj *obj);
float			inter_cone(t_obj *obj, t_vec dist, t_vec raydir);
float			inter_plane(t_obj *obj, t_vec dist, t_vec raydir);
float			inter_sphere(t_obj *obj, t_vec dist, t_vec raydir);
float			inter_cylinder(t_obj *obj, t_vec dist, t_vec raydir);
float			cast_ray(t_obj *tmp, t_vec raydir, t_vec dist);
t_color			shadow(t_vec impact, t_env *e, t_color result, t_obj *obj);
#endif
