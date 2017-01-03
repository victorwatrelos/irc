#include "network/launch_connection.h"

static int		init_fd_set(int sockfd, t_select *st_select, t_data *data)
{
	FD_ZERO(&(st_select->read));
	FD_ZERO(&(st_select->write));
	if (sockfd >= 0)
		FD_SET(sockfd, &(st_select->read));
	ft_printf("before\n");
	FD_SET(0, &(st_select->read));
	if (sockfd >= 0 && (get_size_circular_buffer(data->buff_out) > 0
			|| data->send_buff.start != data->send_buff.end))
		FD_SET(sockfd, &(st_select->write));
	ft_printf("after\n");
	if (sockfd < 0)
		return (0);
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
		return (check_select(&st_select, sockfd, data));
	return (TRUE);
}

int		loop(t_data *data)
{
	int		ret;

	ft_printf("In loop\n");
	while (1)
	{
		ret = select_listen(data->sockfd, data);
		if (ret == STDIN_DISCONNECT)
			return (STDIN_DISCONNECT);
		if (ret == SERVER_DISCONNECT)
			return (SERVER_DISCONNECT);
	}
	ft_printf("Out of loop\n");
}

int		launch_connection(const char *ip, int32_t port)
{
	t_param		param;
	int			ret;
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	param.host = ip;
	param.port = port;
	data.host = ip;
	data.port = port;
	data.sockfd = connect_to_server(&param);
	data.buff_out = new_circular_buffer(SIZE_CIRCULAR_BUFFER);
	if ((ret = loop(&data)) == STDIN_DISCONNECT)
		return (STDIN_DISCONNECT);
	else if (ret == SERVER_DISCONNECT)
	{
		data.sockfd = -1;
		server_disconnect(&data);
		loop(&data);
	}
	return (-666);
}
