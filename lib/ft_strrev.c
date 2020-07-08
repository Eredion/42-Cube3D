/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:11:26 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 16:11:13 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	int		i;
	int		c;

	if (!(rev = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	c = ft_strlen(str) - 1;
	while (c > -1)
		rev[i++] = str[c--];
	rev[i] = '\0';
	return (rev);
}
