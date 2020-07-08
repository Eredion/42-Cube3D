/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:34:12 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:55:10 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mov(t_struct *t)
{
	t->mov.speed = 0.075;
	t->mov.degrees = t->mov.speed * 0.3;
	t->mov.cx = 0;
	t->mov.cy = 0;
	t->mov.mov_x = 0;
	t->mov.mov_y = 0;
	t->mov.up = 0;
	t->mov.left = 0;
	t->mov.right = 0;
	t->mov.down = 0;
	t->mov.turnl = 0;
	t->mov.turnr = 0;
	t->mov.int_posx = 0;
	t->mov.int_posy = 0;
	t->mov.posx = 0;
	t->mov.posy = 0;
	t->mov.plx = 0;
	t->mov.ply = 0;
}

void	init_all(t_struct *t)
{
	t->spr_off = 0;
	t->tex_off = 0;
	init_mov(t);
	initial_pos(t);
	load_texture(t);
	if (t->map.nsprite > 0 && ft_strlen(t->map.sprite) > 5)
		load_sprite(t);
	init_raycast(t);
}

void	initial_pos(t_struct *t)
{
	t->mov.plx = 0;
	t->mov.ply = 0;
	if (t->map.face == 'N' && (t->mov.plx = 0.5))
		t->mov.angle = M_PI / 2;
	else if (t->map.face == 'S' && (t->mov.plx = -0.5))
		t->mov.angle = (3 * M_PI / 2);
	else if (t->map.face == 'E' && (t->mov.ply = 0.66))
		t->mov.angle = 0;
	else if (t->map.face == 'W' && (t->mov.ply = -0.66))
		t->mov.angle = (M_PI);
	t->mov.cx = cos(t->mov.angle);
	t->mov.cy = -sin(t->mov.angle);
	t->mov.posx = (double)t->map.posx + 0.5;
	t->mov.posy = (double)t->map.posy + 0.5;
}

void	load_texture(t_struct *t)
{
	int i;

	t->tex[0].ptr = mlx_xpm_file_to_image(t->init,
		t->map.no, &t->tex[0].width, &t->tex[0].height);
	t->tex[1].ptr = mlx_xpm_file_to_image(t->init,
		t->map.so, &t->tex[1].width, &t->tex[1].height);
	t->tex[2].ptr = mlx_xpm_file_to_image(t->init,
		t->map.we, &t->tex[2].width, &t->tex[2].height);
	t->tex[3].ptr = mlx_xpm_file_to_image(t->init,
		t->map.ea, &t->tex[3].width, &t->tex[3].height);
	i = 0;
	while (i < 4)
	{
		if (t->tex[i].ptr == NULL)
		{
			t->tex_off = 1;
			return ;
		}
		t->tex[i].data = (int*)mlx_get_data_addr(t->tex[i].ptr,
			&t->tex[i].bpp, &t->tex[i].size, &t->tex[i].endian);
		i++;
	}
}

void	create_img(t_struct *t)
{
	t->img.ptr = mlx_new_image(t->init, t->map.rx, t->map.ry);
	t->img.data = (int*)mlx_get_data_addr(t->img.ptr,
	&t->img.bpp, &t->img.size, &t->img.endian);
}
