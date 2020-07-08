/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:47:42 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 16:04:27 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, count * size);
	return ((void*)ptr);
}
