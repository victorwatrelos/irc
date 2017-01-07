#include "msg_error/send_err_cmd.h"

const t_err_map		g_err_map[] =
{
	{NICK_NO_PARAM, "Erroneous nickname", "432"},
	{NICK_TOO_LONG, "Erroneous nickname", "432"},
	{NICK_BAD_CHAR, "Erroneous nickname", "432"},
	{NICK_ALREADY_TAKEN, "Nickname is already in use", "433"},
	{ERR_NEEDMOREPARAMS, "Not enough parameters", "461"},
	{ERR_ALREADYREGISTRED, "Unauthorized command (already registered)", "462"},
	{ERR_NOSUCHCHANNEL, "No such channel", "403"},
};

const size_t		g_err_map_size = sizeof(g_err_map) / sizeof(t_err_map);

static char	*compose_response(const t_err_map *err, t_client *client)
{
	return (get_numeric_response(client->hostname, err->code,
				client->nickname, err->msg));
}

void		send_err_cmd(int err, t_client *client)
{
	size_t			i;
	const t_err_map	*err_map;
	char			*res;

	i = 0;
	while (i < g_err_map_size)
	{
		err_map = g_err_map + i;
		if (err == err_map->err)
		{
			res = compose_response(err_map, client);
			push_back_circular_buffer(client->cmd_queue.buff_out, res);
		}
		i++;
	}
}
