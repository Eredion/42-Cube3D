/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:40:37 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 12:50:25 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ref;
	t_list	*new;
	t_list	*t;

	if (!lst || !f)
		return (NULL);
	t = f(lst->content);
	if (!(new = ft_lstnew(t)))
		return (NULL);
	ref = new;
	lst = lst->next;
	while (lst)
	{
		t = f(lst->content);
		if (!(new->next = ft_lstnew(t)))
		{
			ft_lstclear(&ref, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (ref);
}
