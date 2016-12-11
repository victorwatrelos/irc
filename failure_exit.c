#include "failure_exit.h"

void	failure_exit(char const *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

void	failure_exit_client(t_list *client_elem, t_list **lst_client)
{
	t_client	*client;
	void		*data;

	client = (t_client *)client_elem->content;
	while ((data = pop_front_circular_buffer(client->cmd_queue.buff_out)))
		free(data);
	close(client->sockfd);
	free(client);
	ft_lstdelone(lst_client, client_elem);
}
