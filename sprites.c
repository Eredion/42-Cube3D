/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:36:41 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:57:05 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_sort(t_struct *t)
{
	int		s;
	int		i;
	t_spr	b;

	i = 0;
	s = t->map.nsprite - 1;
	while (s >= 0)
	{
		while (i < t->map.nsprite)
		{
			if (t->map.spr[i].dist < t->map.spr[i + 1].dist)
			{
				b = t->map.spr[i + 1];
				t->map.spr[i + 1] = t->map.spr[i];
				t->map.spr[i] = b;
			}
			i++;
		}
		i = 0;
		s--;
	}
}

void	sprite_dist(t_struct *t)
{
	int i;

	i = 0;
	while (i < t->map.nsprite)
	{
		t->map.spr[i].dist = pow((((float)t->map.spr[i].x + 0.5)
		- t->mov.posx), 2.0) +
		pow((((float)t->map.spr[i].y + 0.5) - t->mov.posy), 2.0);
		i++;
	}
	sprite_sort(t);
}

void	load_sprite(t_struct *t)
{
	t->spr.ptr = mlx_xpm_file_to_image(t->init,
	t->map.sprite, &t->spr.width, &t->spr.height);
	if (t->spr.ptr == NULL || ft_strlen(t->map.sprite) < 3)
	{
		t->spr_off = 1;
		t->map.nsprite = 0;
		return ;
	}
	t->spr.data = (int*)mlx_get_data_addr(t->spr.ptr,
	&t->spr.bpp, &t->spr.size, &t->spr.endian);
}

void	spr_col(t_struct *t)
{
	if (t->map.array[(int)t->mov.posy]
		[(int)(t->mov.posx + (t->mov.mov_x * 3))] == 0)
		t->mov.posx += t->mov.mov_x;
	if (t->map.array[(int)(t->mov.posy + (t->mov.mov_y * 3))]
		[(int)t->mov.posx] == 0)
		t->mov.posy = t->mov.posy + t->mov.mov_y;
}
