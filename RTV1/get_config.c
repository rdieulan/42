/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:16:38 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/23 00:59:00 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_pos(t_obj *obj, char **param)
{
	obj->pos.x = ft_atoi(param[1]);
	obj->pos.y = ft_atoi(param[2]);
	obj->pos.z = ft_atoi(param[3]);
	printf("POS\n");
}

void	get_dir(t_obj *obj, char **param)
{
	obj->dir.x = ft_atoi(param[1]);
	obj->dir.y = ft_atoi(param[2]);
	obj->dir.z = ft_atoi(param[3]);
	normalize(obj->dir);
	printf("DIR\n");
}

void	get_color(t_obj *obj, char **param)
{
	obj->color.r = (float)ft_atoi(param[1]);
	obj->color.g = (float)ft_atoi(param[2]);
	obj->color.b = (float)ft_atoi(param[3]);
}
