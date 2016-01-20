/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:54:07 by rdieulan          #+#    #+#             */
/*   Updated: 2016/01/18 15:43:48 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;

	cp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (cp == NULL)
		return (NULL);
	ft_strcpy(cp, s1);
	return (cp);
}
