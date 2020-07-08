/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:52:16 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 16:42:19 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_clean(char const *s1, char const *set)
{
	int i;
	int c;

	c = 0;
	while (s1[c] != '\0')
	{
		i = 0;
		while (i >= 0 && set[i] != '\0')
		{
			if (s1[c] == set[i])
			{
				i++;
				i = -i;
			}
			else
				i++;
			if (i > (int)ft_strlen(set) - 1)
				return (c);
		}
		c++;
	}
	return (-1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*reverse;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_clean(s1, set);
	reverse = ft_strrev((char*)s1);
	if (!reverse)
		return (NULL);
	len = ft_strlen(s1) - ft_clean(reverse, set) - start;
	if (start == -1)
		return (ft_strdup(""));
	else
		return (ft_substr(s1, start, len));
}
