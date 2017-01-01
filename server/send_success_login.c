#include "send_success_login.h"

static char	*get_host_msg(const char *hostname)
{
	size_t	final_size;
	char	*res;

	final_size = (sizeof(START_HOST_MSG) - 1 + sizeof(END_HOST_MSG)) + ft_strlen(hostname);
	res = malloc(sizeof(char) * final_size);
	ft_strcpy(res, START_HOST_MSG);
	ft_strcat(res, hostname);
	ft_strcat(res, END_HOST_MSG);
	return (res);
}

void	send_success_login(t_client *client)
{
	char	*response;
	char	*hostmsg;

	if (!client->nick_set || !client->username_set || client->logged_in)
		return ;
	response = get_numeric_response(client->hostname, "001", client->nickname, "Hi, welcome to IRC");
	push_back_circular_buffer(client->cmd_queue.buff_out, response);

	hostmsg = get_host_msg(client->hostname);
	response = get_numeric_response(client->hostname, "002", client->nickname, hostmsg);
	push_back_circular_buffer(client->cmd_queue.buff_out, response);
	free(hostmsg);

	response = get_numeric_response(client->hostname, "003", client->nickname, "This server was created sometime");
	push_back_circular_buffer(client->cmd_queue.buff_out, response);

	response = get_numeric_response(client->hostname, "004", client->nickname, "42server 1.0 0 0");
	push_back_circular_buffer(client->cmd_queue.buff_out, response);

	client->logged_in = TRUE;
}
