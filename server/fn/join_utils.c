/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:07 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn/join.h"

int			add_to_chan(t_channel *channel, t_client *client)
{
	t_list		*client_lst;
	t_client	*tmp_client;
	int			not_here;

	not_here = 0;
	client_lst = channel->client_lst;
	while (client_lst)
	{
		tmp_client = client_lst->content;
		if (ft_strcmp(tmp_client->upper_nickname, client->upper_nickname) == 0)
			not_here = 1;
		else
			send_join_msg(channel, tmp_client, client);
		client_lst = client_lst->next;
	}
	if (not_here)
		return (CMD_SUCCESS);
	ft_lstadd(&(channel->client_lst), ft_lstnew(client, sizeof(t_client)));
	send_rpl_namereply(channel->client_lst, client, channel->name);
	return (CMD_SUCCESS);
}

t_channel	*create_channel(const char *channel_name,
		const char *upper_channel_name)
{
	t_channel		*chan;

	if ((chan = malloc(sizeof(t_channel))) == NULL)
		return (NULL);
	ft_bzero(chan, sizeof(t_channel));
	ft_strcpy(chan->name, channel_name);
	ft_strcpy(chan->upper_name, upper_channel_name);
	return (chan);
}
