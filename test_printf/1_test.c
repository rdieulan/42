/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tested.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:54:32 by rdieulan          #+#    #+#             */
/*   Updated: 2016/02/15 18:14:50 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include <stdio.h>

int	simple_string_no_opt()
{
	ft_printf("coucou\n");
	return (0);
}

int	main(void)
{
	simple_string_no_opt();
	return (0);
}
