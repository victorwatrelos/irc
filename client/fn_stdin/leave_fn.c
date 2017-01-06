#include "fn_stdin/fn_stdin.h"

int		leave_fn(const char *params, t_data *data)
{
	int			size_channels;
	char		*part_msg;

	size_channels = jump_to_space(params, 0);
	printf("params: |%s|\n", params);
	if ((part_msg = malloc(size_channels + sizeof(MSG_PART_BASE) + 1)) == NULL)
		return (0);
	ft_strcpy(part_msg, MSG_PART_BASE);
	ft_strncat(part_msg, params, size_channels);
	part_msg[size_channels + sizeof(MSG_PART_BASE)] = '\0';
	ft_strcat(part_msg, "\n");
	printf("part msg: |%s|\n", part_msg);
	push_back_circular_buffer(data->buff_out, part_msg);
	return (1);
}
