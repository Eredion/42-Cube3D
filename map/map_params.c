/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:12:27 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:58:27 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		map_params(char *str, t_map *m)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	m->cols = (i / 2) + 1;
	m->rows = -1;
	i = 0;
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\n')
			i++;
		else if (*str == '\n')
			m->rows++;
		str++;
	}
	m->len = i;
}

void		map_to_array(t_map *m)
{
	int	x;
	int y;
	int i;

	m->array = malloc(sizeof(int*) * m->rows);
	y = 0;
	i = 0;
	while (y < m->rows)
	{
		m->array[y] = malloc(sizeof(int) * m->cols);
		x = 0;
		while (x < m->cols)
		{
			m->array[y][x] = m->mapi[i];
			if (m->array[y][x] == 4)
			{
				m->array[y][x] = 0;
				m->posx = x;
				m->posy = y;
			}
			x++;
			i++;
		}
		y++;
	}
}

void		get_sprites(t_map *m)
{
	int y;
	int x;
	int i;

	if (!(m->spr = malloc(sizeof(t_spr))))
		return ;
	y = 0;
	i = 0;
	while (y < m->rows)
	{
		x = 0;
		while (x < m->cols)
		{
			if (m->array[y][x] == 2)
			{
				m->spr[i].y = y;
				m->spr[i].x = x;
				i++;
			}
			x++;
		}
		y++;
	}
}

void		get_face(t_map *m, int i)
{
	m->mapi[i] = 4;
	m->face = m->map[(2 * i)];
}

void		map_to_int(t_map *m)
{
	int	i;
	int	c;

	m->nsprite = 0;
	m->mapi = malloc(sizeof(int) * m->len);
	i = 0;
	c = 0;
	while (m->map[i] != '\0')
	{
		if (m->map[i] == ' ' || m->map[i] == '\n')
			i++;
		else
		{
			if (m->map[i] >= '0' && m->map[i] <= '2')
			{
				m->map[i] == '2' ? m->nsprite++ : 0;
				(m->mapi[c] = m->map[i] - '0');
			}
			else
				get_face(m, c);
			i++;
			c++;
		}
	}
}
