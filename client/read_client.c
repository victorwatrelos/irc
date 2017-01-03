#include "read_client.h"

static void		reset_client_msg(t_client *client)
{
	client->size_current_msg = 0;
	client->curr_cmd[0] = '\0';
}

static void		add_to_client(t_client *client, const char *msg, int size)
{
	if (client->size_current_msg + size > MAX_CMD_SIZE)
	{
		reset_client_msg(client);
		return ;
	}
	ft_strcat(client->curr_cmd, msg);
	client->size_current_msg += size;
}

static void		process_msg(t_data *data, const char *msg, int i)
{
	if (i + data->client.size_current_msg > MAX_CMD_SIZE)
	{
		reset_client_msg(&(data->client));
		return ;
	}
	ft_strncpy((data->client.curr_cmd + data->client.size_current_msg), msg, i);
	data->client.curr_cmd[i + data->client.size_current_msg] = '\0';
	add_cmd(data);
	reset_client_msg(&(data->client));
}

static void		cat_cmd(t_data *data, const char *msg, int size)
{
	int		i;
	t_bool	no_cmd;

	no_cmd = TRUE;
	i = 0;
	while (i < size)
	{
		if (msg[i] == 0x0A)
		{
			++i;
			process_msg(data, msg, i);
			no_cmd = FALSE;
			break ;
		}
		i++;
	}
	if (no_cmd)
	{
		add_to_client(&(data->client), msg, size);
		return ;
	}
	cat_cmd(data, msg + i, size - i);
}

t_bool			read_client(int sockfd, t_data *data)
{
	int			ret;
	char		buff[MAX_CMD_SIZE + 1];

	if ((ret = read(sockfd, buff, MAX_CMD_SIZE)) <= 0)
	{
		ft_printf("%rClient %d disconnect\n", sockfd);
		return (FALSE);
	}
	buff[ret] = '\0';
	cat_cmd(data, buff, ret);
	return (TRUE);
}
