#include "errors/failure_exit.h"

void	failure_exit(char const *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

static t_bool	in_lst(t_list *client_elem, t_list *client_lst)
{
	while (client_lst)
	{
		if (client_lst == client_elem)
			return (TRUE);
		client_lst = client_lst->next;
	}
	return (FALSE);
}

void	failure_exit_client(t_list *client_elem, t_list **lst_client)
{
	t_client	*client;
	void		*data;

	if (!in_lst(client_elem, *lst_client))
		return ;
	client = (t_client *)client_elem->content;
	FD_CLR(client->sockfd, &(client->st_data->st_select->read));
	FD_CLR(client->sockfd, &(client->st_data->st_select->write));
	leave_all(client);
	while ((data = pop_front_circular_buffer(client->cmd_queue.buff_out)))
		free(data);
	close(client->sockfd);
	free(client);
	ft_lstdelone(lst_client, client_elem);
}
