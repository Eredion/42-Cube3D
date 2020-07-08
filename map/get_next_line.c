/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:25:23 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/21 16:57:57 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int				check_line(t_map *m)
{
	if (m->line[0] == 'R')
		get_res(m);
	if (m->line[0] == 'N' && m->line[1] == 'O')
		m->no = get_texture(m);
	if (m->line[0] == 'S' && m->line[1] == 'O')
		m->so = get_texture(m);
	if (m->line[0] == 'W' && m->line[1] == 'E')
		m->we = get_texture(m);
	if (m->line[0] == 'E' && m->line[1] == 'A')
		m->ea = get_texture(m);
	if (m->line[0] == 'S' && m->line[1] == ' ')
		m->sprite = get_texture(m);
	if (m->line[0] == 'F' && m->line[1] == 'T')
		m->ft = get_texture(m);
	if (m->line[0] == 'C' && m->line[1] == 'T')
		m->ct = get_texture(m);
	if (m->line[0] == 'F' && m->line[1] == ' ')
		m->f = get_color(m);
	if (m->line[0] == 'C' && m->line[1] == ' ')
		m->c = get_color(m);
	if (m->line[0] == '1')
		get_map(m);
	return (0);
}

static int		ft_check_output(int fd, int r, char **line, char **arr)
{
	if (r == 0)
	{
		if (arr[fd] == NULL)
		{
			*line = ft_strdup("");
			return (0);
		}
		*line = arr[fd];
		arr[fd] = NULL;
		return (0);
	}
	return (1);
}

static int		ft_checkline(int fd, char **arr, char **line)
{
	int		i;
	char	*str;

	i = 0;
	while (arr[fd][i] != '\0')
	{
		if (arr[fd][i] == '\n')
		{
			*line = ft_substr(arr[fd], 0, i);
			str = ft_strdup(&arr[fd][i + 1]);
			free(arr[fd]);
			arr[fd] = str;
			return (-1);
		}
		i++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*arr[4096];
	int			r;
	char		b[BUFFER_SIZE + 1];
	char		*str;

	if (fd > 4095 || !line || read(fd, b, 0) < 0 || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (arr[fd] != NULL && ft_checkline(fd, arr, line) != 0)
		return (1);
	while ((r = read(fd, b, BUFFER_SIZE)) > 0)
	{
		b[r] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strdup(b);
		else
		{
			str = ft_strjoin(arr[fd], b);
			free(arr[fd]);
			arr[fd] = str;
		}
		if (ft_checkline(fd, arr, line) == -1)
			break ;
	}
	return (ft_check_output(fd, r, line, arr));
}
