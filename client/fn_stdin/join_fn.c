#include "fn_stdin/fn_stdin.h"

int		join_fn(const char *params, t_data *data)
{
	int			size_channels;
	char		*join_msg;

	size_channels = jump_to_space(params, 0);
	if ((join_msg = malloc(size_channels + sizeof(MSG_JOIN_BASE) + 1)) == NULL)
		return (0);
	ft_strcpy(join_msg, MSG_JOIN_BASE);
	ft_strncat(join_msg, params, size_channels);
	join_msg[size_channels + sizeof(MSG_JOIN_BASE)] = '\0';
	ft_strcat(join_msg, "\n");
	push_back_circular_buffer(data->buff_out, join_msg);
	return (1);
}
