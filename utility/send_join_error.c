#include "send_join_error.h"

static char	*get_error_str(const char *chan_name)
{
	char		*final_msg;
	size_t		final_size;

	final_size = ft_strlen(chan_name) + sizeof(END_NO_SUCH_CHAN) + 1; 
	if ((final_msg = malloc(final_size)) == NULL)
		return (NULL);
	ft_strcpy(final_msg, chan_name);
	ft_strcat(final_msg, END_NO_SUCH_CHAN);
	return (final_msg);
}

void	send_join_error_no_chan(t_client *client, const char *chan_name)
{
	char	*msg;
	char	*response;

	if ((msg = get_error_str(chan_name)) == NULL)
		return (NULL);
	response = get_numeric_response(client->hostname, "403", client->nickname, msg);
	push_back_circular_buffer(client->cmd_queue.buff_out, response);
	free(msg);
}
