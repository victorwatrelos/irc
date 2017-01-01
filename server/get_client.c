#include "get_client.h"

t_client		*get_client(int server_fd, t_data_server *st_data)
{
	t_client			*client;
	struct sockaddr_in	that;
	socklen_t			lg;
	int					sockfd;

	lg = sizeof(that);
	sockfd = accept(server_fd, (struct sockaddr *)(&that), &lg);
	if (sockfd < 0)
		failure_exit("Accept client error\n");
	client = malloc(sizeof(t_client));
	if (!client)
		failure_exit("Unable to allocate t_client struct\n");
	ft_bzero(client, sizeof(t_client));
	client->sockfd = sockfd;
	client->cmd_queue.buff_out = new_circular_buffer(CMD_CIRCULAR_BUFF_SIZE_OUT);
	client->st_data = st_data;
	ft_strcpy(client->hostname, "Unknown");
	return (client);
}
