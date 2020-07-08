/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:21:13 by asegovia          #+#    #+#             */
/*   Updated: 2019/11/14 12:12:19 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst == NULL)
		return ;
	last = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
