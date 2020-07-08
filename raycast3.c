/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:23:32 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:02:09 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycastdos(t_struct *t)
{
	t->ray.camx = 0;
	t->ray.ray_x = 0;
	t->ray.ray_y = 0;
	t->ray.step_x = 0;
	t->ray.step_y = 0;
	t->ray.sidedist_x = 0;
	t->ray.sidedist_y = 0;
	t->ray.delta_x = 0;
	t->ray.delta_y = 0;
	t->ray.walldist = 0;
}

void	init_raycast(t_struct *t)
{
	init_raycastdos(t);
	t->ray.hit = 0;
	t->ray.side = 0;
	t->ray.line_h = 0;
	t->ray.d_start = 0;
	t->ray.d_end = 0;
	t->ray.d_start_y = 0;
	t->ray.d_end_y = 0;
	t->ray.wall_x = 0;
	t->ray.tex_x = 0;
	t->ray.tex_y = 0;
	t->ray.color = 0;
	t->ray.spr_x = 0;
	t->ray.spr_y = 0;
	t->ray.spr_h = 0;
	t->ray.spr_w = 0;
	t->ray.inv = 0;
	t->ray.trans_x = 0;
	t->ray.trans_y = 0;
	t->ray.spr_screenx = 0;
	t->ray.sp_buff = 0;
	t->ray.stripe = 0;
	t->ray.wall = 0;
	t->ray.sp_buff = malloc(sizeof(int) * t->map.rx);
}

void	raycast(t_struct *t)
{
	int x;

	x = 0;
	while (x < t->map.rx)
	{
		start_raycast(t, x);
		step_calculation(t);
		hit_calculation(t);
		if (t->map.nsprite > 0)
			t->ray.sp_buff[x] = t->ray.walldist;
		draw_calculation(t);
		if (t->tex_off != 1)
			print_raycast_tex(t, x);
		else
			print_raycast(t, x);
		x++;
	}
	if (t->spr_off != 1)
	{
		sprite_dist(t);
		print_sprites(t);
	}
}
