#include "fn/part.h"

static void		leave_chan(t_channel *chan, t_client *client)
{
	t_list	*client_lst;
	t_list	*next;

	client_lst = chan->client_lst;
	while (client_lst)
	{
		next = client_lst->next;
		if (client_lst->content == client)
			ft_lstdelone(&(chan->client_lst), client_lst);
		else
			send_part_msg(chan, (t_client *)client_lst->content, client);
		client_lst = next;
	}
}

static void		leave(const char *upper_name, t_client *client,
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
		leave_chan(chan, client);
		return ;
	}
}

static void		part(const char *chan_name, t_client *client)
{
	char		upper_name[MAX_SIZE_CHANNEL_NAME + 1];

	if (ft_strlen(chan_name) > MAX_SIZE_CHANNEL_NAME)
	{
		send_nosuchchannel(chan_name, client);
		return ;
	}
	ft_strcpy(upper_name, chan_name);
	to_upper_rfc(upper_name);
	leave(upper_name, client, client->st_data->channel_list);
}

static t_bool	callback(const char *param, void *p_client, t_bool last)
{
	(void)last;
	part(param, (t_client *)p_client);
	return (TRUE);
}

int				part_fn(const char *param_str, t_client *client)
{
	if (params_lst(param_str, callback, client) == 0)
		return (ERR_NEEDMOREPARAMS);
	return (CMD_SUCCESS);
}
