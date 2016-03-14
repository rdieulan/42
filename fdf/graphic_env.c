/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:00:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/03/14 19:20:04 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hooker(int keycode, t_mlx *mlx)
{
	if (keycode == 53) // 53 = escape
		exit(0);
	else
		printf("keycode not assigned : %d\n", keycode);
	return (0);
}

void	graphic_init(t_mlx *mlx, int x, int y, char *title)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, x, y, title);
}

void	graphic_process(t_env *env)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	graphic_init(mlx, 500, 500, "FENETRE");
	mlx_pixel_put(mlx->ptr, mlx->win, 250, 250, 0x00FFFFFF);
	mlx_key_hook(mlx->win, key_hooker, mlx);
	mlx_loop(mlx->ptr);
}
