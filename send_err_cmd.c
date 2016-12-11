#include "send_err_cmd.h"

const t_err_map		g_err_map[] = 
{
	{NICK_NO_PARAM, "Erroneous nickname", "432"},
	{NICK_TOO_LONG, "Erroneous nickname", "432"},
	{NICK_BAD_CHAR, "Erroneous nickname", "432"},
	{NICK_ALREADY_TAKEN, "Nickname is already in use", "433"},
	{ERR_NEEDMOREPARAMS, "Not enough parameters", "461"},
	{ERR_ALREADYREGISTRED, "Unauthorized command (already registered)", "462"}
};

const size_t		g_err_map_size = sizeof(g_err_map) / sizeof(t_err_map);

static char	*compose_response(const t_err_map *err, t_client *client)
{
	char	*res;
	size_t	final_size;

	final_size = ft_strlen(err->msg) + ft_strlen(err->code) + ft_strlen(client->hostname) + ft_strlen(client->nickname) + 16;
	res = malloc(final_size);
	ft_bzero(res, final_size);
	res[0] = ':';
	ft_strcat(res, client->hostname);
	ft_strcat(res, " ");
	ft_strcat(res, err->code);
	ft_strcat(res, " * ");
	ft_strcat(res, client->nickname);
	ft_strcat(res, " :");
	ft_strcat(res, err->msg);
	return (res);
}

void		send_err_cmd(int err, t_client *client)
{
	size_t			i;
	const t_err_map	*err_map;
	char			*res;


	printf("error: %d, size: %zu\n", err, g_err_map_size);
	i = 0;
	while (i < g_err_map_size)
	{
		err_map = g_err_map + i;
		if (err == err_map->err)
		{
			res = compose_response(err_map, client);
			push_back_circular_buffer(client->cmd_queue.buff_out, res);
			printf("Error: %s\n", res);
		}
		i++;
	}
}
