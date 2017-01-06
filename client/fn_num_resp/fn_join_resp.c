#include "fn_num_resp/fn_resp.h"

static char	*get_nickname(const char *host, int host_size)
{
	int		i;
	char	*res;

	i = 0;
	while (i < host_size && host[i] != '\0' && host[i] != '!')
		i++;
	if ((res = malloc(i + 1)) == NULL)
		return (NULL);
	ft_strncpy(res, host, i);
	return (res);
}

static char	*get_channame(const char *msg)
{
	const char	*start_chan;
	int			size;
	char		*res;

	start_chan = jump_end_of_space(msg, 0) + msg;
	size = jump_to_space(start_chan, 0);
	res = malloc(size + 1);
	ft_strncpy(res, start_chan, size);
	res[size] = '\0';
	return (res);
}

static void	push_resp(const char *nick, const char *chan, const char *msg,
		t_data *data)
{
	char	*res;

	res = malloc(ft_strlen(nick) + ft_strlen(chan) + ft_strlen(msg) + 3);
	if (res == NULL)
		return ;
	ft_strcpy(res, nick);
	ft_strcat(res, msg);
	ft_strcat(res, chan);
	push_back_circular_buffer(data->display_out, res);
}

int			fn_join_resp(t_num_resp_param *param, t_data *data)
{
	char	*nickname;
	char	*chan_name;

	if ((nickname = get_nickname(param->host, param->size_host)) == NULL)
		return (0);
	if ((chan_name = get_channame(param->msg)) == NULL)
		return (0);
	push_resp(nickname, chan_name, MSG_JOIN_RESP_END, data);
	free(nickname);
	free(chan_name);
	return (1);
}

int			fn_part_resp(t_num_resp_param *param, t_data *data)
{
	char	*nickname;
	char	*chan_name;

	if ((nickname = get_nickname(param->host, param->size_host)) == NULL)
		return (0);
	if ((chan_name = get_channame(param->msg)) == NULL)
		return (0);
	push_resp(nickname, chan_name, MSG_PART_RESP_END, data);
	free(nickname);
	free(chan_name);
	return (1);
}
