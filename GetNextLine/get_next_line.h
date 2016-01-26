/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 20:13:00 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/26 20:20:42 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE = 32
# include "libft/libft.h"

typedef	struct		s_file
{
	int				fd;
	char			*stock;
	struct s_stock	*next;
}					t_file;

int	get_next_line(const int fd, char **line);

#endif
