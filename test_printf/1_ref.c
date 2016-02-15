/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:43:05 by rdieulan          #+#    #+#             */
/*   Updated: 2016/02/15 18:14:37 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/libft/includes/libft.h"
#include <stdio.h>
#include <fcntl.h>

int		simple_string_no_opt()
{
	printf("coucou\n");
	return (0);
}

int		main(void)
{
	simple_string_no_opt();
	return (0);
}
