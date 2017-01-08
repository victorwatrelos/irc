/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_chan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:11 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "send_to_chan.h"

void	send_to_chan(t_channel *channel, const char *msg, t_client *src)
{
	char		*res;
	char		*to_push;
	t_list		*client_lst;
	t_client	*client;

	if ((res = get_priv_msg(msg, channel->name, src)) == NULL)
		return ;
	client_lst = channel->client_lst;
	while (client_lst)
	{
		if ((to_push = ft_strdup(res)) == NULL)
		{
			free(res);
			return ;
		}
		client = client_lst->content;
		if (client != src)
			push_back_circular_buffer(client->cmd_queue.buff_out, to_push);
		else
			free(to_push);
		client_lst = client_lst->next;
	}
	free(res);
}
