/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:48:10 by rdieulan          #+#    #+#             */
/*   Updated: 2016/09/14 17:50:38 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"

# define WIN_W 1920
# define WIN_H 1080
# define BLOCK_UNIT 100
# define FOV 60
# define PROJ_W 320
# define PROJ_H 200

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
	int			map_size;
	double		posx;
	double		posy;
	double		p_angle;
}				t_env;

int				key_hooker(int kcode, t_env *env);
void			game(t_env *env);

#endif
