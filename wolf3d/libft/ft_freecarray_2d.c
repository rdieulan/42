/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freecarray_2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:14:13 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/21 17:34:10 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_freecarray_2d(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_strdel(&tab[i++]);
	ft_strdel(tab);
}
