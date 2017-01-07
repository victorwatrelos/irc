#include "msg/send_rpl_endofname.h"

void		send_rpl_endofname(t_client *client, const char *chan_name)
{
	const char	*data[4];
	char		*msg;
	size_t		size_msg;
	char		*response;

	size_msg = sizeof(MSG_ENDOFNAME) + ft_strlen(chan_name) + 8;
	if ((msg = malloc(size_msg)) == NULL)
		return ;
	ft_strcpy(msg, " ");
	ft_strcat(msg, chan_name);
	ft_strcat(msg, " ");
	ft_strcat(msg, MSG_ENDOFNAME);
	data[HOSTNAME] = client->hostname;
	data[CODE] = "366";
	data[NICKNAME] = client->nickname;
	data[MSG] = msg;
	if ((response = get_numeric_response_custom(data, FALSE)) == NULL)
		return ;
	free(msg);
	push_back_circular_buffer(client->cmd_queue.buff_out, response);
}
