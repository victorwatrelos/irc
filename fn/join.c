#include "join.h"

static int	add_to_chan(t_channel *channel, t_client *client)
{
	t_list		*client_lst;
	t_client	*tmp_client;

	client_lst = channel->client_lst;
	while (client_lst)
	{
		tmp_client = client_lst->content;
		if (ft_strcmp(tmp_client->upper_nickname, client->upper_nickname) == 0)
			return (CMD_SUCCESS);
		client_lst = client_lst->next;
	}
	ft_lstadd(&(channel->client_lst), ft_lstnew(client, sizeof(t_client)));
	send_rpl_namereply(channel->client_lst, client, channel->name);
	return (CMD_SUCCESS);
}

static t_channel	*create_channel(const char *channel_name, const char *upper_channel_name)
{
	t_channel		*chan;

	if ((chan = malloc(sizeof(t_channel))) == NULL)
		return (NULL);
	ft_bzero(chan, sizeof(t_channel));
	ft_strcpy(chan->name, channel_name);
	ft_strcpy(chan->upper_name, upper_channel_name);
	return (chan);
}

static int	join_channel(const char *join_channel, t_list **channel_list, t_client *client)
{
	t_list		*channel_elem;
	t_channel	*channel;
	char		upper_channel_name[MAX_SIZE_CHANNEL_NAME + 1];

	printf("Join channel: %s\n", join_channel);
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

static int	join(const char *channel_name, t_client *client)
{
	size_t		size_channel;

	size_channel = ft_strlen(channel_name);
	if (size_channel > MAX_SIZE_CHANNEL_NAME)
	{
		send_nosuchchannel(channel_name, client);
		return (ERR_NOSUCHCHANNEL);
	}
	ft_memcpy(channel_name, start, size_channel);
	channel_name[size_channel] = '\0';
	if (!is_channel_name_valid(channel_name))
	{
		send_nosuchchannel(channel_name, client);
		return (CMD_SUCCESS);
	}
	join_channel(channel_name, &(client->st_data->channel_list), client);
	return (CMD_SUCCESS);
}

static t_bool	callback(const char *param, t_client *client, t_bool last)
{
	if (last && ft_strcmp(param, "0") == 0)
	{
		leave_all(client);
		return (TRUE);
	}
	join(param, client);	
	return (TRUE);
}

int		join_fn(const char *param_str, t_client *client)
{
	if (params_lst(param_str, callback, client) == 0)
		return (ERR_NEEDMOREPARAMS);
	return (CMD_SUCCESS);
	/*
	const char	*end_param;
	const char	*end_params;
	const char	*start_param;

	param_str = param_str + jump_end_of_space(param_str, 0);
	end_params = param_str + jump_to_space(param_str, 0);
	start_param = param_str;
	if (end_params == start_param)
		return (ERR_NEEDMOREPARAMS);
	while (param_str < end_params)
	{
		if (*param_str == ',')
		{
			end_param = param_str;
			join(start_param, end_param, client);
			start_param = end_param + 1;
		}
		param_str++;
	}
	if ((end_params - start_param) == 1 && start_param[0] == '0')
		leave_all(client);
	else
		join(start_param, param_str, client);
	return (CMD_SUCCESS);
	*/
}
