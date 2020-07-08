/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:55:21 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 16:12:13 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ref;

	if (!lst)
		return (0);
	ref = lst;
	i = 0;
	while (ref != NULL)
	{
		ref = ref->next;
		i++;
	}
	return (i);
}
