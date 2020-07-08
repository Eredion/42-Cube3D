/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:57:49 by asegovia          #+#    #+#             */
/*   Updated: 2020/07/08 09:01:37 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/libft.h"

typedef struct	s_sprite
{
	int		x;
	int		y;
	double	dist;
}				t_spr;

typedef struct	s_map
{
	char	*map;
	int		*mapi;
	int		**array;
	char	face;
	int		posx;
	int		posy;
	int		len;
	int		rows;
	int		cols;
	char	*sprite;
	int		nsprite;
	int		ry;
	int		rx;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*line;
	char	*ft;
	char	*ct;
	int		c;
	int		f;
	int		fd;
	int		gnl_r;
	t_spr	*spr;

}				t_map;

int				get_next_line(int fd, char **line);
void			get_res(t_map *m);
char			*get_texture(t_map *m);
void			get_map(t_map *m);
int				translate_color(int r, int g, int b);
int				get_color(t_map *m);
int				check_line(t_map *m);
int				read_map(t_map *m, char *file);
void			map_params(char *str, t_map *m);
void			map_to_int(t_map *m);
void			map_to_array(t_map *m);
void			get_face(t_map *m, int i);
void			get_sprites(t_map *m);
int				check_map(t_map *m);
int				check_all(t_map *m);

#endif
