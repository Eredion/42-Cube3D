/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:35:42 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:55:25 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_press(t_struct *t)
{
	if (t->key == _W || t->key == _UP)
		t->mov.up = 1;
	if (t->key == _S || t->key == _DOWN)
		t->mov.down = 1;
	if (t->key == _E || t->key == _RIGHT)
		t->mov.turnr = 1;
	if (t->key == _Q || t->key == _LEFT)
		t->mov.turnl = 1;
	if (t->key == _A)
		t->mov.left = 1;
	if (t->key == _D)
		t->mov.right = 1;
}

void	move_release(t_struct *t)
{
	if (t->key == _W || t->key == _UP)
		t->mov.up = 0;
	if (t->key == _S || t->key == _DOWN)
		t->mov.down = 0;
	if (t->key == _E || t->key == _RIGHT)
		t->mov.turnr = 0;
	if (t->key == _Q || t->key == _LEFT)
		t->mov.turnl = 0;
	if (t->key == _A)
		t->mov.left = 0;
	if (t->key == _D)
		t->mov.right = 0;
}

void	mov_change(t_struct *t)
{
	if (t->mov.up == 1 && (t->mov.mov_x = t->mov.cx * t->mov.speed))
		t->mov.mov_y = t->mov.cy * t->mov.speed;
	if (t->mov.down == 1 && (t->mov.mov_x = -t->mov.cx * t->mov.speed))
		t->mov.mov_y = -t->mov.cy * t->mov.speed;
	if (t->mov.left == 1 && (t->mov.mov_x = t->mov.cy * t->mov.speed))
		t->mov.mov_y = -t->mov.cx * t->mov.speed;
	if (t->mov.right == 1 && (t->mov.mov_x = -t->mov.cy * t->mov.speed))
		t->mov.mov_y = t->mov.cx * t->mov.speed;
	if (t->spr_off == 1)
	{
		if (t->map.array[(int)t->mov.posy]
			[(int)(t->mov.posx + (t->mov.mov_x * 3))] != 1)
			t->mov.posx += t->mov.mov_x;
		if (t->map.array[(int)(t->mov.posy + (t->mov.mov_y * 3))]
			[(int)t->mov.posx] != 1)
			t->mov.posy = t->mov.posy + t->mov.mov_y;
	}
	else
		spr_col(t);
	t->mov.mov_x = 0;
	t->mov.mov_y = 0;
}

void	movement(t_struct *t)
{
	mov_change(t);
	if ((t->mov.turnl == 1) && (t->mov.angle = t->mov.angle + t->mov.degrees))
	{
		t->mov.cx = cos(t->mov.angle);
		t->mov.cy = sin(-1 * t->mov.angle);
		t->mov.ply = t->mov.plx * sin(-t->mov.degrees)
			+ t->mov.ply * cos(-t->mov.degrees);
		t->mov.plx = t->mov.plx * cos(-t->mov.degrees)
			- t->mov.ply * sin(-t->mov.degrees);
	}
	if ((t->mov.turnr == 1 && (t->mov.angle = t->mov.angle - t->mov.degrees)))
	{
		t->mov.cx = cos(t->mov.angle);
		t->mov.cy = sin(-1 * t->mov.angle);
		t->mov.ply = t->mov.plx * sin(t->mov.degrees) +
			t->mov.ply * cos(t->mov.degrees);
		t->mov.plx = t->mov.plx * cos(t->mov.degrees) -
			t->mov.ply * sin(t->mov.degrees);
	}
}

int		mouse(int x, int y, t_struct *t)
{
	int limitl;
	int limitr;

	limitl = (int)((double)t->map.rx * 0.4);
	limitr = (int)((double)t->map.rx * 0.6);
	if (y < 0 || y > t->map.ry || (x < limitr && x > limitl) ||
		t->map.rx < x || x < 0)
	{
		t->mov.turnl = 0;
		t->mov.turnr = 0;
	}
	else if (x < limitl && x > 0)
	{
		t->mov.turnl = 1;
		t->mov.turnr = 0;
	}
	else if (x > limitr && x < t->map.rx)
	{
		t->mov.turnl = 0;
		t->mov.turnr = 1;
	}
	return (0);
}
