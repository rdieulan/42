/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 07:57:48 by rdieulan          #+#    #+#             */
/*   Updated: 2016/02/15 14:38:04 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

/*int	convertor_sum(const char * format)
{
	return 0;
}

int	param_validity(va_list ap)
{
	return 0;
}*/

int	ft_printf(const char * format, ...)
{
//	char arg;
//	va_list ap;
	
//	va_start(ap, format);
//	arg = va_arg(ap, char);
//	printf("%c", arg);
	/*while ((arg = va_arg(ap,int)) != 0) 
	{
		if (param_validity(arg, ) == -1)
			exit;
	}*/
	ft_putstr(format);
	return 0;
}
