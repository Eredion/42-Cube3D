/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:16:42 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/07 18:00:50 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_helper(const char *str, const char *to_find, int i, int c)
{
	int	p;

	while (to_find[i] != '\0')
	{
		if (to_find[i] == str[c + i])
			p = 1;
		else
			return (0);
		i++;
	}
	return (p);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	c;

	c = 0;
	if (needle[c] == '\0')
		return ((char*)haystack);
	if (haystack[c] == '\0')
		return (0);
	while (c + ft_strlen(needle) <= (int)len)
	{
		i = 0;
		if (haystack[c] == needle[i])
		{
			if (ft_helper(haystack, needle, i, c) == 1)
				return ((char*)&haystack[c]);
		}
		c++;
	}
	return (NULL);
}
