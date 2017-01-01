#include "msg_error/send_cannotsendchan.h"

void	send_cannotsendchan(const char *chan_name, t_client *client)
{
	const char	*data[4];
	char		*msg;
	size_t		size_msg;
	char		*response;

	size_msg = sizeof(CANNOT_SEND) + ft_strlen(chan_name) + 8;

	if ((msg = malloc(size_msg)) == NULL)
		return ;
	ft_strcpy(msg, " ");
	ft_strcat(msg, chan_name);
	ft_strcat(msg, " ");
	ft_strcat(msg, CANNOT_SEND);
	data[HOSTNAME] = client->hostname;
	data[CODE] = "404";
	data[NICKNAME] = client->nickname;
	data[MSG] = msg;
	if ((response = get_numeric_response_custom(data, FALSE)) == NULL)
		return ;
	free(msg);
	push_back_circular_buffer(client->cmd_queue.buff_out, response);
}

