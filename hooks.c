/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:57:27 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:46:34 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		release(int key, t_struct *t)
{
	t->key = key;
	move_release(t);
	return (0);
}

int		waiting(t_struct *t)
{
	create_img(t);
	movement(t);
	raycast(t);
	paint_map(t, (t->map.rx - (10 * t->map.cols)), 0);
	paint_pos(t);
	if (t->save == 1)
		save_bmp(t);
	mlx_put_image_to_window(t->init, t->window, t->img.ptr, 0, 0);
	return (0);
}

int		exit_win(t_struct *t)
{
	if (t->map.nsprite > 0)
		free(t->map.spr);
	mlx_destroy_window(t->init, t->window);
	exit(0);
}

int		press(int key, t_struct *t)
{
	t->key = key;
	move_press(t);
	if (t->key == _ESC)
	{
		if (t->map.nsprite > 0)
			free(t->map.spr);
		mlx_destroy_window(t->init, t->window);
		exit(0);
	}
	return (0);
}
