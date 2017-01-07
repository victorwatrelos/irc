#include "network/server.h"

static void	write_client(t_list **client_lst, t_list *client_elem,
		t_client *client)
{
	if (send_to_sockfd(client->sockfd, &(client->send_buff),
				client->cmd_queue.buff_out) < 0)
		failure_exit_client(client_elem, client_lst);
}

static void	check_client(t_select *st_select, t_list **client_lst_pointer)
{
	t_client	*client;
	t_list		*client_lst;
	t_list		*next;

	client_lst = *client_lst_pointer;
	while (client_lst)
	{
		client = client_lst->content;
		next = client_lst->next;
		if (FD_ISSET(client->sockfd, &(st_select->read)))
		{
			if (!read_client(client_lst, client_lst_pointer))
			{
				check_client(st_select, client_lst_pointer);
				return ;
			}
		}
		if (FD_ISSET(client->sockfd, &(st_select->write)))
			write_client(client_lst_pointer, client_lst, client);
		client_lst = next;
	}
}

void		check_select(t_select *st_select, t_data_server *st_data)
{
	if (FD_ISSET(st_select->sockfd, &(st_select->read)))
	{
		ft_lstadd(&(st_data->client_list),
				ft_lstnew(get_client(st_select->sockfd, st_data),
				sizeof(t_client)));
		ft_printf("New client\n");
	}
	check_client(st_select, &(st_data->client_list));
}
