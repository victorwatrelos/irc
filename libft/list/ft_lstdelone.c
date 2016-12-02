/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:30:57 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/06/25 17:33:13 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	tmp_norm(t_list *prvs, t_list *elem)
{
	t_list		*cur;

	cur = prvs->next;
	while (cur != NULL)
	{
		if (cur == elem)
		{
			prvs->next = cur->next;
			free(elem);
		}
		prvs = cur;
		cur = cur->next;
	}
}

void		ft_lstdelone(t_list **list, t_list *elem)
{
	t_list		*prvs;

	if (*list == NULL)
		return ;
	if (elem == NULL)
		return ;
	if ((*list)->next == NULL)
	{
		if (*list == elem)
		{
			free(elem);
			*list = NULL;
		}
		return ;
	}
	prvs = *list;
	tmp_norm(prvs, elem);
}
