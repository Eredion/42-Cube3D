/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:03:25 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 12:53:59 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	chose_color(t_struct *t, int y, int x)
{
	if (t->map.array[y][x] == 1)
		return (0x45310a);
	return (0xedf5f2);
}

void			pixel_put(t_struct *t, int x, int y, int color)
{
	t->img.data[y * t->map.rx + x] = color;
}

void			paint_square(t_struct *t, unsigned int color, int x, int y)
{
	int	i;
	int n;

	i = 0;
	while (i < 10)
	{
		n = 0;
		while (n < 10)
		{
			pixel_put(t, (x + n), (y + i), color);
			n++;
		}
		i++;
	}
}

void			paint_map(t_struct *t, int x, int y)
{
	int col;
	int row;

	row = 0;
	while (row != t->map.rows)
	{
		col = 0;
		while (col != t->map.cols)
		{
			paint_square(t, chose_color(t, row, col),
				(x + (10 * col)), (y + (10 * row)));
			col++;
		}
		row++;
	}
}

void			paint_pos(t_struct *t)
{
	int	i;
	int n;

	i = 0;
	while (i < 5)
	{
		n = 0;
		while (n < 5)
		{
			pixel_put(t, (((t->mov.posx) * 10) + n - 3 +
				(t->map.rx) - (10 * t->map.cols)), ((t->mov.posy * 10) + i - 3),
					0x008000);
			n++;
		}
		i++;
	}
}
