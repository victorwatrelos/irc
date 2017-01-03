#include "read_client.h"
t_bool			read_client(int sockfd, t_data *data)
{
	data->st_cat_cmd.callback = (t_callback_cat_cmd)add_cmd;
	data->st_cat_cmd.param_callback = (void *)data;
	return (read_socket(sockfd, &(data->st_cat_cmd)));
}
