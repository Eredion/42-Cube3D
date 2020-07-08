/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:32:55 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 16:16:32 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ref;

	if (!*lst)
		return ;
	ref = *lst;
	while (ref != NULL)
	{
		ft_lstdelone(ref, del);
		ref = ref->next;
	}
	ref = NULL;
	*lst = NULL;
}
