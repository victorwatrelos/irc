#include "failure_exit.h"

void	failure_exit(char const *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

void	failure_exit_client(t_list *client_elem, t_list **lst_client)
{
	t_client	*client;

	client = (t_client *)client_elem->content;
	close(client->sockfd);
	free(client);
	ft_lstdelone(lst_client, client_elem);
}
