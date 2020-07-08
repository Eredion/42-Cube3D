/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:49:52 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:54:23 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int n, char **args)
{
	t_struct t;

	t.save = 0;
	t.tex_off = 0;
	t.spr_off = 0;
	t.key = 0;
	t.init = mlx_init();
	if (n == 1)
		read_map(&t.map, "maps/1.cub");
	else
		read_map(&t.map, args[1]);
	if (n == 3 && ft_strncmp("--save", args[2], 6) == 0)
		t.save = 1;
	t.window = mlx_new_window(t.init, t.map.rx, t.map.ry, "Cub3D");
	init_all(&t);
	mlx_hook(t.window, 2, 0, press, &t);
	mlx_hook(t.window, 3, 0, release, &t);
	mlx_hook(t.window, 6, 0, mouse, &t);
	mlx_hook(t.window, 17, 1L << 2, exit_win, &t);
	mlx_loop_hook(t.init, waiting, &t);
	mlx_loop(t.init);
	return (0);
}
