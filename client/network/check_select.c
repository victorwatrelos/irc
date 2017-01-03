#include "network/check_select.h"

int		check_select(t_select *st_select, int sockfd, t_data *data)
{
	if (sockfd > 0 && FD_ISSET(sockfd, &(st_select->read)))
	{
		if (!read_client(sockfd, data))
			return (SERVER_DISCONNECT);
	}
	if (FD_ISSET(0, &(st_select->read)))
	{
		if (!read_stdin(data))
			return (STDIN_DISCONNECT);
	}
	if (sockfd > 0 && (get_size_circular_buffer(data->buff_out) > 0
				|| data->send_buff.start != data->send_buff.end)
			&& FD_ISSET(sockfd, &(st_select->write)))
	{
		if (!write_client(sockfd, data))
			return (SERVER_DISCONNECT);
	}
	return (SUCCESS);
}
