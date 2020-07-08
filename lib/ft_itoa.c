/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:51:48 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/13 15:51:37 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	nb;
	int			i;
	char		*str;

	nb = n;
	i = ft_intlen(nb);
	if (nb == 0)
		return (ft_strdup((const char*)"0"));
	if (!(str = malloc(sizeof(char) * ft_intlen(nb) + 1)))
		return (NULL);
	str[i] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		str[--i] = (nb % 10 + 48);
		nb /= 10;
	}
	str[--i] = (nb / 10 + 48);
	str[i] = (nb % 10 + 48);
	return (str);
}
