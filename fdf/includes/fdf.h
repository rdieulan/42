/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:22:50 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/02 18:36:49 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	char		*title;
}				t_mlx;

typedef struct	s_env
{
	int			x;
	int			y;
}				t_env;
#endif
