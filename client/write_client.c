#include "write_client.h"

t_bool		write_client(int sockfd, t_data *data)
{
	if (send_to_sockfd(sockfd, &(data->send_buff), data->buff_out) < 0)
		return (FALSE);
	return (TRUE);
}
