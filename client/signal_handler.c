#include "signal_handler.h"

void	exit_clean(t_data *p_data, int mod)
{
	static t_data		*data = NULL;

	if (p_data != NULL)
	{
		data = p_data;
		return ;
	}
	if (data == NULL)
		return ;
	close(data->sockfd);
	if (mod == 1)
	{
		data->sockfd = -1;
		data->is_connected = FALSE;
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		exit_clean(NULL, 0);
		printf("Exit\n");
		exit(0);
	}
	if (signal == SIGPIPE)
	{
		exit_clean(NULL, 1);
	}
}
