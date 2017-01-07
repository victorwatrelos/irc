#include "errors/server_disconnect.h"

void		server_disconnect(t_data *data)
{
	data->sockfd = -1;
	data->is_connected = FALSE;
	printf("Server %s:%d disconnect\n", data->host, data->port);
}
