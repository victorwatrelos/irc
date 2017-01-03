#include "network/launch_connection.h"

static int		init_fd_set(int sockfd, t_select *st_select, t_data *data)
{
	FD_ZERO(&(st_select->read));
	FD_ZERO(&(st_select->write));
	FD_SET(sockfd, &(st_select->read));
	FD_SET(0, &(st_select->read));
	if (get_size_circular_buffer(data->buff_out) > 0)
		FD_SET(sockfd, &(st_select->write));
	return (sockfd);
}

static int		select_listen(int sockfd, t_data *data)
{
	struct timeval	tv;
	int				fd_max;
	int				ret;
	t_select		st_select;

	tv.tv_sec = TIME_WAIT_SELECT_US / 1000000;
	tv.tv_usec = TIME_WAIT_SELECT_US % 1000000;
	fd_max = init_fd_set(sockfd, &st_select, data) + 1;
	ret = select(fd_max + 1, &(st_select.read), &(st_select.write),
			NULL, &tv);
	if (ret < 0)
	{
		ft_printf("%rSelect fail\n");
		return (FALSE);
	}
	if (ret > 0)
		return (check_select(st_select, st_data));
	return (TRUE);
}

int		launch_connection(const char *ip, int32_t port)
{
	t_param		param;
	int			socket;
	int			ret;
	t_data		data;

	param.host = ip;
	param.port = port;
	socket = connect_to_server(&param);
	while (1)
	{
		ret = select_listen(socket, &data);
		if (ret == STDIN_DISCONNECT)
			return (STDIN_DISCONNECT);
		//if (ret == SERVER_DISCONNECT)
		//	server_deconnection(data);
	}
}
