#include "signal_handler.h"

static void	close_client(t_list *client_lst)
{
	t_list	*next;

	while (client_lst)
	{
		next = client_lst->next;
		close(((t_client *)client_lst->content)->sockfd);
		free(client_lst->content);
		free(client_lst);
		client_lst = next;
	}
}

static void	free_channel(t_list *chan_lst)
{
	t_list	*next;
	t_list	*client;
	t_list	*client_next;

	while(chan_lst)
	{
		next = chan_lst->next;
		client = ((t_channel *)chan_lst->content)->client_lst;
		while (client)
		{
			client_next = client->next;
			free(client);
			client = client_next;
		}
		free(chan_lst->content);
		free(chan_lst);
		chan_lst = next;
	}
}

void	exit_clean(t_data_server *p_data)
{
	static t_data_server	*data = NULL;

	if (p_data != NULL)
	{
		data = p_data;
		return ;
	}
	if (data == NULL)
		return ;
	close_client(data->client_list);
	close(data->st_select->sockfd);
	free_channel(data->channel_list);
}

void		signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		exit_clean(NULL);
		printf("Exit\n");
		exit(0);
	}
}
