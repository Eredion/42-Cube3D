/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:44:08 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 11:48:22 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_image(t_struct *t, int fd)
{
	int y;
	int x;
	int size;

	y = 0;
	size = t->map.rx * (t->map.ry);
	while (y <= t->map.ry)
	{
		x = 0;
		while (x < t->map.rx)
		{
			write(fd, &t->img.data[size - (y * t->map.rx + t->map.rx - x)],
					4);
			x++;
		}
		y++;
	}
}

void	save_bmp(t_struct *t)
{
	int size;
	int	fd;
	int	empty;

	fd = 0;
	size = 0;
	empty = 54;
	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0640);
	size = 54 + (4 * (t->map.rx * t->map.ry));
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &empty, 4);
	bmp_header(t, fd);
	bmp_image(t, fd);
	close(fd);
	exit(0);
}

void	bmp_header(t_struct *t, int fd)
{
	int header_size;
	int plane;
	int i;

	header_size = 40;
	plane = 1;
	write(fd, &header_size, 4);
	write(fd, &t->map.rx, 4);
	write(fd, &t->map.ry, 4);
	write(fd, &plane, 2);
	write(fd, &t->img.bpp, 2);
	i = 0;
	while (i++ < 32)
	{
		write(fd, "\0", 1);
	}
}
