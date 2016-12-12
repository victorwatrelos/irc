#include "join.h"

static int	add_to_chan(t_channel *channel, t_client *client)
{
	ft_lstadd(&(channel->client_lst), ft_lstnew(client, sizeof(t_client)));
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

	ft_strcpy(upper_channel_name, join_channel);
	to_upper_rfc(upper_channel_name);
	channel_elem = *channel_list;
	while (channel_elem)
	{
		channel = channel_elem->content;
		if (upper_channel_name == channel->upper_name)
		{
			return (add_to_chan(channel, client));
		}
		channel_elem = channel_elem->next;
	}
	if ((channel = create_channel(join_channel, upper_channel_name)) == NULL)
		return (UNEXPECTED_ERROR);
	add_to_chan(channel, client);
	return (CMD_SUCCESS);
}

static int	join(const char *start, const char *end, t_client *client)
{
	size_t		size_channel;
	char		channel_name[MAX_SIZE_CHANNEL_NAME + 1];

	size_channel = end - start;
	if (size_channel > MAX_SIZE_CHANNEL_NAME)
		return (ERR_NOSUCHCHANNEL);
	ft_memcpy(channel_name, start, size_channel);
	channel_name[size_channel] = '\0';
	printf("Channel name: %s\n", channel_name);
	if (!is_channel_name_valid(channel_name))
		return (ERR_NOSUCHCHANNEL);
	join_channel(channel_name, &(client->st_data->channel_list), client);
	return (CMD_SUCCESS);
}

int		join_fn(const char *param_str, t_client *client)
{
	int			i;
	const char	*end_param;
	const char	*end_params;
	const char	*start_param;

	i = 0;
	param_str = param_str + jump_end_of_space(param_str, 0);
	end_params = param_str + jump_to_space(param_str, 0);
	start_param = param_str;
	while (param_str < end_params)
	{
		if (*param_str == ',')
		{
			end_param = param_str;
			join(start_param, end_param, client);
			i++;
			start_param = end_param + 1;
		}
		param_str++;
	}
	if (i <= 0)
		return (ERR_NEEDMOREPARAMS);
	if ((i = join(start_param, param_str, client)) != CMD_SUCCESS)
	{
		client->err[0] = 
	}
	return (CMD_SUCCESS);
}
