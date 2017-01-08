/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_client.h"

t_client		*get_client(int server_fd, t_data_server *st_data)
{
	t_client			*client;
	struct sockaddr_in6	that;
	int					sockfd;
	socklen_t			addrlen;

	addrlen = sizeof(that);
	sockfd = accept(server_fd, NULL, NULL);
	if (sockfd < 0)
		failure_exit("Accept client error\n");
	getpeername(sockfd, (struct sockaddr *)&that, &addrlen);
	client = malloc(sizeof(t_client));
	if (!client)
		failure_exit("Unable to allocate t_client struct\n");
	ft_bzero(client, sizeof(t_client));
	if (!inet_ntop(AF_INET6, &that.sin6_addr,
				client->hostname, INET6_ADDRSTRLEN))
		ft_strcpy(client->hostname, "Unknown");
	client->sockfd = sockfd;
	client->cmd_queue.buff_out =
		new_circular_buffer(CMD_CIRCULAR_BUFF_SIZE_OUT);
	client->st_data = st_data;
	return (client);
}
