#include "fn/privmsg.h"

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
		if (ft_strcmp(chan->upper_name, upper_target) == 0)
		{
			send_to_chan(chan, msg, src);
			return (TRUE);
		}
		chan_lst = chan_lst->next;
	}
	return (FALSE);
}

static void	send_privmsg(t_p_privmsg *p, t_client *client)
{
	char	target[MAX_SIZE_CHANNEL_NAME + 1];
	char	upper_target[MAX_SIZE_CHANNEL_NAME + 1];
	char	msg[MAX_CMD_SIZE + 1];

	if (p->size_target > MAX_SIZE_CHANNEL_NAME)
	{
		ft_strncpy(target, p->start_target, MAX_SIZE_CHANNEL_NAME);
		target[MAX_SIZE_CHANNEL_NAME] = '\0';
		send_cannotsendchan(target, client);
		return ;
	}
	ft_strncpy(target, p->start_target, p->size_target);
	target[p->size_target] = '\0';
	ft_strcpy(upper_target, target);
	to_upper_rfc(upper_target);
	if (p->size_msg > MAX_CMD_SIZE)
	{
		send_cannotsendchan(target, client);
		return ;
	}
	ft_strncpy(msg, p->start_msg, p->size_msg);
	msg[p->size_msg] = '\0';
	if (try_chan(upper_target, client, msg)
			|| try_nick(upper_target, client, msg))
		return ;
	send_cannotsendchan(target, client);
}

int		privmsg_fn(const char *param_str, t_client *client)
{
	const char	*end_target;
	t_p_privmsg	p;

	p.start_target = param_str + jump_end_of_space(param_str, 0);
	end_target = p.start_target + jump_to_space(p.start_target, 0);
	p.size_target = end_target - p.start_target;
	p.start_msg = end_target + jump_end_of_space(end_target, 0);
	p.size_msg = ft_strlen(p.start_msg);
	if (p.size_target == 0 || p.size_msg == 0)
		return (ERR_NEEDMOREPARAMS);
	send_privmsg(&p, client);
	return (CMD_SUCCESS);
}
