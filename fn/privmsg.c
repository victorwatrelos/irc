#include "privmsg.h"

static int	try_nick(const char *upper_target, t_client *src, const char *msg)
{
	t_list		*client_lst;
	t_client	*dest;

	client_lst = src->st_data->client_list;
	while (client_lst)
	{
		dest = client_lst->content;
		if (ft_strcmp(upper_target, dest->upper_nickname) == 0)
		{
			send_msg_to_client(dest, src, msg);
			return (TRUE);
		}
		client_lst = client_lst->next;
	}
	return (FALSE);
}

static int	try_chan(const char *upper_target, t_client *src, const char *msg)
{
	t_list		*chan_lst;
	t_channel	*chan;

	chan_lst = src->st_data->channel_list;
	while (chan_lst)
	{
		chan = chan_lst->content;
		printf("upper_target: %s, upper_chan: %s\n", upper_target, chan->upper_name);
		if (ft_strcmp(chan->upper_name, upper_target) == 0)
		{
			send_to_chan(chan, msg, src);
			return (TRUE);
		}
		chan_lst = chan_lst->next;
	}
	return (FALSE);
}

static void	send_privmsg(const char *p_target, size_t target_size, const char *p_msg, size_t msg_size, t_client *client)
{
	char	target[MAX_SIZE_CHANNEL_NAME + 1];
	char	upper_target[MAX_SIZE_CHANNEL_NAME + 1];
	char	msg[MAX_CMD_SIZE + 1];

	if (target_size > MAX_SIZE_CHANNEL_NAME)
	{
		ft_strncpy(target, p_target, MAX_SIZE_CHANNEL_NAME);
		target[MAX_SIZE_CHANNEL_NAME] = '\0';
		send_cannotsendchan(target, client);
		return ;
	}
	ft_strncpy(target, p_target, target_size);
	target[target_size] = '\0';
	ft_strcpy(upper_target, target);
	to_upper_rfc(upper_target);
	if (msg_size > MAX_CMD_SIZE)
	{
		send_cannotsendchan(target, client);
		return ;
	}
	ft_strncpy(msg, p_msg, msg_size);
	msg[msg_size] = '\0';
	if (try_chan(upper_target, client, msg))
		return ;
	if (try_nick(upper_target, client, msg))
		return ;
	send_cannotsendchan(target, client);
}

int		privmsg_fn(const char *param_str, t_client *client)
{
	const char	*start_target;
	const char	*end_target;
	const char	*start_msg;
	size_t		size_msg;
	size_t		size_target;

	printf("INSIDE\n");
	start_target = param_str + jump_end_of_space(param_str, 0);
	end_target = start_target + jump_to_space(start_target, 0);
	size_target = end_target - start_target;
	start_msg = end_target + jump_end_of_space(end_target, 0);
	size_msg = ft_strlen(start_msg);
	if (size_target == 0 || size_msg == 0)
		return (ERR_NEEDMOREPARAMS);
	send_privmsg(start_target, size_target, start_msg, size_msg, client);
	return (CMD_SUCCESS);
}
