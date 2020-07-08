/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:40:34 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 15:36:30 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (dstsize > 1 && *src)
	{
		*dst++ = *src++;
		dstsize--;
		i++;
	}
	*dst = '\0';
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}
