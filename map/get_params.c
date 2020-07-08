/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:18:24 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/20 19:27:15 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_res(t_map *m)
{
	int i;

	i = 1;
	while (m->line[i] == ' ')
		i++;
	if (ft_isdigit(m->line[i]) == 1)
	{
		m->rx = ft_atoi(&m->line[i]);
		i = i + ft_intlen(m->rx) + 1;
	}
	if (ft_isdigit(m->line[i]) == 1)
		m->ry = ft_atoi(&m->line[i]);
	if (m->rx > 2560 || m->rx < 100)
		m->rx = 2560;
	if (m->ry > 1390 || m->ry < 100)
		m->ry = 1390;
}

char	*get_texture(t_map *m)
{
	int		i;
	char	*str;
	int		c;

	i = 2;
	c = 0;
	while (m->line[i] == ' ')
		i++;
	if (!(str = malloc(sizeof(char) * ft_strlen(&m->line[i] + 1))))
		return (NULL);
	while (m->line[i] != '\0')
		str[c++] = m->line[i++];
	str[c] = '\0';
	return (str);
}

void	get_map(t_map *m)
{
	int		r;
	char	*aux;
	char	*line;

	m->map = ft_strjoin(m->line, "\n");
	while ((r = get_next_line(m->fd, &line) > 0))
	{
		if (ft_strlen(line) > 2)
		{
			aux = ft_strjoin(m->map, line);
			free(m->map);
			m->map = ft_strjoin(aux, "\n");
			free(aux);
		}
		free(line);
	}
	aux = ft_strjoin(m->map, line);
	free(m->map);
	m->map = ft_strjoin(aux, "\n");
	free(aux);
	free(line);
	m->gnl_r = 1;
}

int		translate_color(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

int		get_color(t_map *m)
{
	int i;
	int r;
	int g;
	int b;

	i = 1;
	while (m->line[i] == ' ')
		i++;
	r = ft_atoi(&m->line[i]);
	i = i + ft_intlen(m->rx) + 1;
	g = ft_atoi(&m->line[i]);
	i = i + ft_intlen(m->rx) + 1;
	b = ft_atoi(&m->line[i]);
	i = i + ft_intlen(m->rx) + 1;
	return (translate_color(r, g, b));
}
