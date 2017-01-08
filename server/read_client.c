/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:11 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_client.h"

t_bool			read_client(t_list *client_elem, t_list **lst_client)
{
	t_client	*client;

	client = client_elem->content;
	client->cat_cmd.callback = (t_callback_cat_cmd)add_cmd;
	client->cat_cmd.param_callback = client;
	if (!read_socket(client->sockfd, &(client->cat_cmd)))
	{
		failure_exit_client(client_elem, lst_client);
		return (FALSE);
	}
	return (TRUE);
}
