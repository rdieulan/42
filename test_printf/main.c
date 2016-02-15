/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:43:05 by rdieulan          #+#    #+#             */
/*   Updated: 2016/02/15 14:44:06 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#define	CMP	ft_strcmp

int		simple_string_no_opt()
{
	char	buf1[10];
	char	buf2[10];

	printf("coucou");
	read(1, buf1, 10);
	ft_putchar('c');
	ft_printf("coucou");
	read(1, buf2, 10);
	if (CMP(buf1, buf2) == 0)
		return (1);
	else
		return (0);
}

int		main(void)
{
	int	error;

	error = 0;
	if (simple_string_no_opt())
		printf("simple_string_no_opt : OK");
	else
		printf("simple_string_no_opt : ERROR");
	return (0);
}
