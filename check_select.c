/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 18:04:54 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/06/23 19:09:47 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	check_client(t_select *st_select, t_list **client_lst_pointer)
{
	t_client	*client;
	t_list		*client_lst;

	client_lst = *client_lst_pointer;
	while (client_lst)
	{
		client = client_lst->content;
		if (FD_ISSET(client->sockfd, &(st_select->read)))
			read_client(client_lst, client_lst_pointer);
		client_lst = client_lst->next;
	}
}

void		check_select(t_select *st_select, t_data_server *st_data)
{
	if (FD_ISSET(st_select->sockfd, &(st_select->read)))
	{
		ft_lstadd(&(st_data->client_list),
				ft_lstnew(get_client(st_select->sockfd), sizeof(t_client))
		);
		ft_printf("New client\n");
	}
	check_client(st_select, &(st_data->client_list));
}
