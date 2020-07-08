/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:23:58 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 17:23:41 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_raycast(t_struct *t, int x)
{
	int i;

	i = 0;
	while (i < t->ray.d_start)
	{
		pixel_put(t, x, i, t->map.c);
		i++;
	}
	while (i < t->ray.d_end)
	{
		if (t->ray.side == 1)
			pixel_put(t, x, i, (0x6C3B2A / 2));
		else
			pixel_put(t, x, i, 0x6C3B2A);
		i++;
	}
	while (i < t->map.ry)
	{
		pixel_put(t, x, i, t->map.f);
		i++;
	}
}

void	tex_color(t_struct *t, int i)
{
	t->ray.wall = 0;
	if (t->ray.side == 0 && t->ray.ray_x > 0)
		t->ray.wall = 0;
	else if (t->ray.side == 0 && t->ray.ray_x < 0)
		t->ray.wall = 1;
	else if (t->ray.side == 1 && t->ray.ray_y > 0)
		t->ray.wall = 2;
	else if (t->ray.side == 1 && t->ray.ray_y < 0)
		t->ray.wall = 3;
	t->ray.tex_y = (i - (-t->ray.line_h / 2 + t->map.ry / 2)) /
		(t->ray.line_h / (double)t->tex[t->ray.wall].height);
	t->ray.tex_x = t->ray.wall_x * (double)t->tex[t->ray.wall].width;
	t->ray.color = t->tex[t->ray.wall].data[(t->ray.tex_x) +
	(t->ray.tex_y * t->tex[t->ray.wall].width)];
}

void	print_raycast_tex(t_struct *t, int x)
{
	int i;

	i = 0;
	while (i < t->ray.d_start)
	{
		pixel_put(t, x, i, t->map.c);
		i++;
	}
	while (i < t->ray.d_end)
	{
		tex_color(t, i);
		pixel_put(t, x, i, t->ray.color);
		i++;
	}
	while (i < t->map.ry)
	{
		pixel_put(t, x, i, t->map.f);
		i++;
	}
}

void	start_raycast(t_struct *t, int x)
{
	t->ray.camx = 2 * x / (double)t->map.rx - 1;
	t->ray.ray_x = t->mov.cx + t->mov.plx * t->ray.camx;
	t->ray.ray_y = t->mov.cy + t->mov.ply * t->ray.camx;
	t->mov.int_posx = (int)(t->mov.posx);
	t->mov.int_posy = (int)(t->mov.posy);
	t->ray.delta_x = fabs(1 / t->ray.ray_x);
	t->ray.delta_y = fabs(1 / t->ray.ray_y);
	t->ray.hit = 0;
}

void	step_calculation(t_struct *t)
{
	if (t->ray.ray_x < 0 && (t->ray.step_x = -1))
		t->ray.sidedist_x = (t->mov.posx - t->mov.int_posx) * t->ray.delta_x;
	else
	{
		t->ray.step_x = 1;
		t->ray.sidedist_x = (t->mov.int_posx + 1.0 - t->mov.posx) *
		t->ray.delta_x;
	}
	if (t->ray.ray_y < 0 && (t->ray.step_y = -1))
		t->ray.sidedist_y = (t->mov.posy - t->mov.int_posy) * t->ray.delta_y;
	else
	{
		t->ray.step_y = 1;
		t->ray.sidedist_y = (t->mov.int_posy + 1.0 - t->mov.posy) *
		t->ray.delta_y;
	}
}
