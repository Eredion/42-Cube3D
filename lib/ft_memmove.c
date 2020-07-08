/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:29:05 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/07 15:56:16 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dest;
	const char		*srce;

	dest = dst;
	srce = src;
	if (dest > srce)
	{
		while (len)
		{
			len--;
			dest[len] = srce[len];
		}
	}
	else
	{
		return (ft_memcpy(dst, src, len));
	}
	return (dst);
}
