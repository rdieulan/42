/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:00:37 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/10 17:01:31 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	graphic_init(t_env *env)
{
	MLX->w = WSZ;
	MLX->h = HSZ;
	MLX->ptr = mlx_init();
	MLX->win = mlx_new_window(MLX->ptr, MLX->w, MLX->h, env->title);
}

void	set_menu(t_env *env)
{
	int		i;
	int		j;
	char	*text1;
	char	*text2;

	text1 = "(Up/Down/Left/Right) -> Move                pg(Up/Down) -> depth";
	text2 = "(+/-) -> Zoom";
	i = 0;
	j = MENU;
	while (i <= WSZ)
		mlx_pixel_put(MLX->ptr, MLX->win, i++, j, 0xFFFFFF);
	mlx_string_put(MLX->ptr, MLX->win, 10, MENU, 0x00FFFFFF, text1);
	mlx_string_put(MLX->ptr, MLX->win, 10, MENU + 20, 0x00FFFFFF, text2);
}

void	graphic_process(t_env *env)
{
	MLX = (t_mlx*)malloc(sizeof(t_mlx));
	graphic_init(env);
	mlx_hook(MLX->win, 2, 1L << 0, key_hooker, env);
	set_menu(env);
	draw(env);
	mlx_loop(MLX->ptr);
}
