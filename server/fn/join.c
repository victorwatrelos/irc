#include "fn/join.h"

static int		join_channel(const char *join_channel,
		t_list **channel_list, t_client *client)
{
	t_list		*channel_elem;
	t_channel	*channel;
	char		upper_channel_name[MAX_SIZE_CHANNEL_NAME + 1];

	ft_strcpy(upper_channel_name, join_channel);
	to_upper_rfc(upper_channel_name);
	channel_elem = *channel_list;
	while (channel_elem)
	{
		channel = channel_elem->content;
		if (ft_strcmp(upper_channel_name, channel->upper_name) == 0)
		{
			return (add_to_chan(channel, client));
		}
		channel_elem = channel_elem->next;
	}
	if ((channel = create_channel(join_channel, upper_channel_name)) == NULL)
		return (UNEXPECTED_ERROR);
	ft_lstadd(channel_list, ft_lstnew(channel, sizeof(t_channel)));
	add_to_chan(channel, client);
	return (CMD_SUCCESS);
}

static int		join(const char *channel_name, t_client *client)
{
	size_t		size_channel;

	size_channel = ft_strlen(channel_name);
	if (size_channel > MAX_SIZE_CHANNEL_NAME)
	{
		send_nosuchchannel(channel_name, client);
		return (ERR_NOSUCHCHANNEL);
	}
	if (!is_channel_name_valid(channel_name))
	{
		send_nosuchchannel(channel_name, client);
		return (CMD_SUCCESS);
	}
	join_channel(channel_name, &(client->st_data->channel_list), client);
	return (CMD_SUCCESS);
}

static t_bool	callback(const char *param, void *p_client, t_bool last)
{
	t_client	*client;

	client = p_client;
	if (last && ft_strcmp(param, "0") == 0)
	{
		leave_all(client);
		return (TRUE);
	}
	join(param, client);
	return (TRUE);
}

int				join_fn(const char *param_str, t_client *client)
{
	if (params_lst(param_str, callback, client) == 0)
		return (ERR_NEEDMOREPARAMS);
	return (CMD_SUCCESS);
}
