/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:44:24 by asegovia          #+#    #+#             */
/*   Updated: 2020/02/12 17:38:17 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../Libft/libft.h"

int		main(int n, char **args)
{
	t_map	*m;
	int i = 0;
/*
	if (n != 2)
	{
		write(1, "Wrong number of arguments\n", 27);
		return (0);
	}*/
	if(!(m = malloc(sizeof(t_map))))
		return (0);
	read_map(m, "1.cub");
	
/*	printf("R %d %d\n", m->rx, m->ry);
	printf("NO = %s%s%s\n", m->no, m->we, m->ft);
	printf("colorines:%d %d\n", m->f, m->c);
	printf("el buen mapa:\n%s\n", m->map);
	printf("map %s\nrows = %d, cols = %d, mlen = %d, face = %c, \n", m->map, m->rows, m->cols, m->len, m->face);
	printf("apunta hacia: %c en la X = %d y la Y = %d\n%s\n", m->face, m->posx, m->posy, m->map);
	while (i < m->len)
	{
		printf("%d", m->mapi[i]);
		i++;
		if (i % m->cols == 0)
			printf("\n");
	}
	printf("\n%d\n", i);
	int c = 0;
	while (c < m->rows)
	{
		i = 0;
		while (i < m->cols)
		{
			printf("%d", m->array[c][i]);
			i++;
		}
		printf("\n");
		c++;
	}*/	
	free(m);
	//system("leaks a.out");
}
