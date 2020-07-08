/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:29:05 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 14:21:02 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	char			*dest;
	const char		*src;

	i = 0;
	dest = str1;
	src = str2;
	if (!n || src == dest)
		return (dest);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (str1);
}
