/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:27:23 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:55:54 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hit_calculation(t_struct *t)
{
	while (t->ray.hit == 0)
	{
		if (t->ray.sidedist_x < t->ray.sidedist_y)
		{
			t->ray.sidedist_x += t->ray.delta_x;
			t->mov.int_posx += t->ray.step_x;
			t->ray.side = 0;
		}
		else
		{
			t->ray.sidedist_y += t->ray.delta_y;
			t->mov.int_posy += t->ray.step_y;
			t->ray.side = 1;
		}
		if (t->map.array[t->mov.int_posy][t->mov.int_posx] == 1)
			t->ray.hit = 1;
	}
	if (t->ray.side == 0)
		t->ray.wall_x = t->mov.posy + t->ray.walldist * t->ray.ray_y;
	else
		t->ray.wall_x = t->mov.posx + t->ray.walldist * t->ray.ray_x;
	t->ray.wall_x -= floor((t->ray.wall_x));
}

void	draw_calculation(t_struct *t)
{
	if (t->ray.side == 0)
		t->ray.walldist = (t->mov.int_posx - t->mov.posx +
		(1 - t->ray.step_x) / 2) / t->ray.ray_x;
	else
		t->ray.walldist = (t->mov.int_posy - t->mov.posy +
		(1 - t->ray.step_y) / 2) / t->ray.ray_y;
	t->ray.line_h = (int)(t->map.ry / t->ray.walldist);
	t->ray.d_start = -t->ray.line_h / 2 + t->map.ry / 2;
	if (t->ray.d_start < 0)
		t->ray.d_start = 0;
	t->ray.d_end = t->ray.line_h / 2 + t->map.ry / 2;
	if (t->ray.d_end > t->map.ry)
		t->ray.d_end = t->map.ry;
}

void	spr_calculation(t_struct *t, int i)
{
	t->ray.spr_x = t->map.spr[i].x - t->mov.posx + 0.5;
	t->ray.spr_y = t->map.spr[i].y - t->mov.posy + 0.5;
	t->ray.inv = 1.0 / (t->mov.plx * t->mov.cy - t->mov.cx * t->mov.ply);
	t->ray.trans_x = t->ray.inv * (t->mov.cy * t->ray.spr_x -
		t->mov.cx * t->ray.spr_y);
	t->ray.trans_y = t->ray.inv * (-t->mov.ply * t->ray.spr_x +
		t->mov.plx * t->ray.spr_y);
	t->ray.spr_screenx = (int)((t->map.rx / 2) *
	(1 + t->ray.trans_x / t->ray.trans_y));
	t->ray.spr_h = fabs((t->map.ry / t->ray.trans_y));
	t->ray.d_start_y = -t->ray.spr_h / 2 + t->map.ry / 2;
	if (t->ray.d_start_y < 0)
		t->ray.d_start_y = 0;
	t->ray.d_end_y = t->ray.spr_h / 2 + t->map.ry / 2;
	if (t->ray.d_end_y >= t->map.ry)
		t->ray.d_end_y = t->map.ry - 1;
	t->ray.spr_w = fabs((t->map.ry / (t->ray.trans_y)));
	t->ray.d_start = -t->ray.spr_w / 2 + t->ray.spr_screenx;
	if (t->ray.d_start < 0)
		t->ray.d_start = 0;
	t->ray.d_end = t->ray.spr_w / 2 + t->ray.spr_screenx;
	if (t->ray.d_end >= t->map.rx)
		t->ray.d_end = t->map.rx - 1;
	t->ray.stripe = t->ray.d_start;
}

void	draw_stripe(t_struct *t)
{
	int y;

	y = t->ray.d_start_y;
	t->ray.tex_x = (int)(256 * (t->ray.stripe - (-t->ray.spr_w /
	2 + t->ray.spr_screenx)) * t->tex->width / t->ray.spr_w) / 256;
	if (t->ray.trans_y > 0 && t->ray.stripe > 0 && t->ray.stripe < t->map.rx &&
	t->ray.trans_y < t->ray.sp_buff[t->ray.stripe])
	{
		while (y < t->ray.d_end_y)
		{
			t->ray.tex_y = ((((y) * 256 - t->map.ry * 128 + t->ray.spr_h * 128)
			* t->tex->height) / t->ray.spr_h) / 256;
			t->ray.color = t->spr.data[(t->spr.width * t->ray.tex_y) +
			t->ray.tex_x];
			if (t->ray.color != 0)
				pixel_put(t, t->ray.stripe, y, t->ray.color);
			y++;
		}
	}
}

void	print_sprites(t_struct *t)
{
	int x;
	int i;

	x = 0;
	while (x < t->map.rx)
	{
		i = 0;
		while (i < t->map.nsprite)
		{
			spr_calculation(t, i);
			while (t->ray.stripe < t->ray.d_end)
			{
				draw_stripe(t);
				t->ray.stripe++;
				x++;
			}
			i++;
		}
		x++;
	}
}
