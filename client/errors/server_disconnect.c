#include "errors/server_disconnect.h"

void		server_disconnect(t_data *data)
{
	printf("Server %s:%d disconnect\n", data->host, data->port);
}
