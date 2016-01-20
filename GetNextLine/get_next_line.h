/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:21:22 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/20 16:57:36 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2000

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

int		get_next_line(int const fd, char **line);

#endif
