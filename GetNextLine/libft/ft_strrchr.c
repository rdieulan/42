/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:06:46 by rdieulan          #+#    #+#             */
/*   Updated: 2015/12/08 15:00:28 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	c2;
	int		i;

	c2 = (char)c;
	str = (char*)s;
	i = ft_strlen(s);
	while (i >= 0 && str[i] != c2)
		i--;
	if (i < 0)
		return (0);
	else
		return (&str[i]);
}
