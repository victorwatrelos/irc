/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:07 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn/names.h"

static void		send_chan_nick(const char *upper_name, t_client *client,
		t_list *chan_lst)
{
	t_channel	*chan;

	while (chan_lst)
	{
		chan = chan_lst->content;
		if (ft_strcmp(chan->upper_name, upper_name) != 0)
		{
			chan_lst = chan_lst->next;
			continue ;
		}
		send_rpl_namereply(chan->client_lst, client, chan->name);
		send_rpl_endofname(client, chan->name);
		return ;
	}
	send_rpl_endofname(client, upper_name);
}

static void		names(const char *chan_name, t_client *client)
{
	char		upper_name[MAX_SIZE_CHANNEL_NAME + 1];

	if (ft_strlen(chan_name) > MAX_SIZE_CHANNEL_NAME)
	{
		send_nosuchchannel(chan_name, client);
		return ;
	}
	ft_strcpy(upper_name, chan_name);
	to_upper_rfc(upper_name);
	send_chan_nick(upper_name, client, client->st_data->channel_list);
}

static t_bool	callback(const char *param, void *p_client, t_bool last)
{
	(void)last;
	names(param, (t_client *)p_client);
	return (TRUE);
}

int				names_fn(const char *params_str, t_client *client)
{
	if (params_lst(params_str, callback, client) == 0)
		return (ERR_NEEDMOREPARAMS);
	return (CMD_SUCCESS);
}
