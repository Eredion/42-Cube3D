/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:03:22 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 15:27:39 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0 || len == 0 || (int)start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	if (!str)
		return (NULL);
	return (str);
}
