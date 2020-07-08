/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:11:51 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:51:35 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int				check_map(t_map *m)
{
	int i;

	i = 0;
	while (m->array[0][i] == 1 && i < m->cols)
		i++;
	if (m->cols != i)
		return (0);
	i = 0;
	while (m->array[m->rows - 1][i] == 1 && i < m->cols)
		i++;
	if (m->cols != i)
		return (0);
	i = 0;
	while (m->array[i][0] == 1 && i < m->rows - 1)
		i++;
	if (i != m->rows - 1)
		return (0);
	i = 0;
	while (m->array[i][m->cols - 1] == 1 && i < m->rows - 1)
		i++;
	if (i != m->rows - 1)
		return (0);
	return (1);
}

int				check_all(t_map *m)
{
	if (!m->rx || !m->ry || !m->face || !m->posx || !m->posy || !m->map ||
		!m->mapi || !m->array || !m->f || !m->c || check_map(m) != 1)
		return (0);
	return (1);
}

static void		map_error(void)
{
	write(1, "Map Error, introduce a valid map.\n", 35);
	exit(0);
}

void			init_params(t_map *m)
{
	m->face = 0;
	m->posx = 0;
	m->posy = 0;
	m->len = 0;
	m->rows = 0;
	m->cols = 0;
	m->nsprite = 0;
	m->ry = 0;
	m->rx = 0;
	m->c = 0;
	m->f = 0;
	m->gnl_r = 0;
	m->no = NULL;
	m->so = NULL;
	m->we = NULL;
	m->ea = NULL;
	m->sprite = NULL;
}

int				read_map(t_map *m, char *file)
{
	int		r;

	init_params(m);
	if ((m->fd = open(file, O_RDONLY)) < 0)
		map_error();
	while ((r = get_next_line(m->fd, &m->line)) >= 0)
	{
		if (ft_strlen(m->line) > 2)
			check_line(m);
		free(m->line);
		if (r == 0 || m->gnl_r == 1)
			break ;
	}
	map_params(m->map, m);
	map_to_int(m);
	map_to_array(m);
	get_sprites(m);
	if (check_all(m) != 1 || m->fd < 0 || r < 0)
		map_error();
	return (1);
}
