/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:01:50 by rdieulan          #+#    #+#             */
/*   Updated: 2016/11/22 21:31:03 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_graph	*init_graph(char *file)
{
	t_graph *graph;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->title = file;
	graph->ptr = mlx_init();
	graph->win = mlx_new_window(graph->ptr, WIN_W, WIN_H, graph->title);
	graph->img = mlx_new_image(graph->ptr, WIN_W, WIN_H);
	graph->addr = mlx_get_data_addr(graph->img, &(graph->bits), &(graph->len),
			&(graph->endian));
	return (graph);
}

t_env	*init_env(char *file)
{
	t_env	*e;

	e = (t_env*)malloc(sizeof(t_env));
	printf("Initialazing graphics ...\n");
	e->graph = init_graph(file);
	printf("GRAPHIC ENVIRONNEMENT INITIALIZED.\n");
	e->oid = 0;
	printf("Initialazing objects ... \n");
	init_obj(file, e);
	return (e);
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc == 2)
	{
		e = init_env(argv[1]);
		printf("starting ray tracing\n");
		ray_tracing(e);
	}
	else
		ft_putstr("Wrong number of parameters. Must be 1.\n");
	return (0);
}
