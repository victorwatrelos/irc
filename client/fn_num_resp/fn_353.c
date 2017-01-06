#include "fn_num_resp/fn_resp.h"

static char	*get_channel_name(const char *msg, int *i)
{
	const char	*start_chan;
	int			size_chan;
	char		*res;

	start_chan = jump_end_of_space(msg, 1) + msg;
	size_chan = jump_to_space(start_chan, 0);
	if ((res = malloc(size_chan + 1)) == NULL)
		return (NULL);
	ft_strncpy(res, start_chan, size_chan);
	res[size_chan] = '\0';
	*i = start_chan - msg + size_chan;
	return (res);
}

static char	*get_members(const char *msg)
{
	int			size_msg;
	const char	*start_name;
	int			i;
	char		*res;

	size_msg = ft_strlen(msg);
	if (size_msg < 1)
		return (NULL);
	start_name = jump_end_of_space(msg, 0) + msg;
	if (*start_name == '\0')
		return (NULL);
	start_name++;
	i = 0;
	while (start_name[i] != '\n' && start_name[i] != '\0')
		i++;
	if (start_name[i] == '\n')
		i--;
	if (i < 0)
		i = 0;
	if ((res = malloc(i + 1)) == NULL)
		return (NULL);
	ft_strncpy(res, start_name, i);
	res[i] = '\0';
	return (res);
}

static void	push_resp(const char *chan_name, const char *members, t_data *data)
{
	char	*res;

	res = malloc(ft_strlen(chan_name) + ft_strlen(members)
			+ sizeof(MSG_353_RESP_START) + sizeof(MSG_353_RESP_MIDDLE));
	if (res == NULL)
		return ;
	ft_strcpy(res, MSG_353_RESP_START);
	ft_strcat(res, chan_name);
	ft_strcat(res, MSG_353_RESP_MIDDLE);
	ft_strcat(res, members);
	push_back_circular_buffer(data->display_out, res);
}

int			fn_353(t_num_resp_param *param, t_data *data)
{
	int		size_params;
	char	*channel_name;
	char	*members;
	int		i;

	size_params = ft_strlen(param->msg);
	if (size_params < 4)
		return (0);
	if ((channel_name = get_channel_name(param->msg, &i)) == NULL)
		return (0);
	if ((members = get_members(param->msg + i)) == NULL)
	{
		free(channel_name);
		return (0);
	}
	push_resp(channel_name, members, data);
	free(channel_name);
	free(members);
	return (1);
}
