#include "fn_stdin/fn_stdin.h"

static char	*get_ip(const char *params, int *i)
{
	const char	*start_ip;
	int			size_ip;
	char		*res;

	*i = jump_end_of_space(params, 0);
	start_ip = *i + params;
	size_ip = jump_to_space(start_ip, 0);
	*i += size_ip;
	if ((res = malloc(size_ip + 1)) == NULL)
		return (NULL);
	ft_strncpy(res, start_ip, size_ip);
	res[size_ip] = '\0';
	return (res);
}

static char	*get_port(const char *params)
{
	const char	*start_port;
	int			size_port;
	char		*res;

	start_port = jump_end_of_space(params, 0) + params;
	size_port = jump_to_space(start_port, 0);
	if (size_port == 0)
		return (NULL);
	if ((res = malloc(size_port + 1)) == NULL)
		return (NULL);
	ft_strncpy(res, start_port, size_port);
	res[size_port] = '\0';
	return (res);
}

static void	disp_conn_fail(t_data *data)
{
	char	*res;

	if ((res = ft_strdup(MSG_CON_FAIL)) == NULL)
		return ;
	push_back_circular_buffer(data->display_out, res);
}

int			connect_fn(const char *params, t_data *data)
{
	char	*ip;
	char	*port;
	int		i;
	t_param	param;

	if ((ip = get_ip(params, &i)) == NULL)
		return (FALSE);
	if ((port = get_port(params + i)) == NULL)
		param.port = 6667;
	else
		param.port = ft_atoi(port);
	param.host = ip;
	if (data->is_connected)
		close(data->sockfd);
	data->sockfd = connect_to_server(&param);
	printf("sockfd: %d\n", data->sockfd);
	data->is_connected = data->sockfd >= 0;
	if (!data->is_connected)
	{
		disp_conn_fail(data);
	}
	data->is_logged = FALSE;
	ft_bzero(&(data->logged), sizeof(t_logged));
	return (TRUE);
}
