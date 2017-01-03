#include "network/check_select.h"

int		check_select(t_select *st_select, int sockfd, t_data *data)
{
	if (FD_ISSET(sockfd, &(st_select->read)))
	{
		if (!read_client(sockfd, data))
			return (SERVER_DISCONNECT);
	}
	if (FD_ISSET(0, &(st_select->read)))
	{
		if (!read_stdin(data))
			return (STDIN_DISCONNECT);
	}
	if (FD_ISSET(sockfd, &(st_select->write))
			&& get_size_circular_buffer(data->buff_out) > 0)
	{
		if (!write_fd(sockfd, data))
			return (SERVER_DISCONNECT);
	}
	return (SUCCESS);
}
