#include "msg/send_rpl_namereply.h"

static char	*get_num_resp(t_client *dest, const char *msg)
{
	const char	*data[4];

	data[HOSTNAME] = dest->hostname;
	data[CODE] = "353";
	data[NICKNAME] = dest->nickname;
	data[MSG] = msg;
	return (get_numeric_response_custom(data, FALSE));
}

void		send_rpl_namereply(t_list *client_lst, t_client *dest, const char *chan_name)
{
	char	*msg;
	size_t	final_size;
	t_list	*client_elem;
	char	*response;

	final_size = ft_strlen(chan_name) + 6;
	client_elem = client_lst;
	while (client_elem)
	{
		final_size += ft_strlen(((t_client *)client_elem->content)->nickname) + 1;
		client_elem = client_elem->next;
	}
	if ((msg = malloc(final_size)) == NULL)
		return ;
	ft_strcpy(msg, " = ");
	ft_strcat(msg, chan_name);
	ft_strcat(msg, " :");
	while (client_lst)
	{
		ft_strcat(msg, ((t_client *)client_lst->content)->nickname);
		ft_strcat(msg, " ");
		client_lst = client_lst->next;
	}
	response = get_num_resp(dest, msg);
	free(msg);
	printf("namereply: %s\n", response);
	push_back_circular_buffer(dest->cmd_queue.buff_out, response);
}
