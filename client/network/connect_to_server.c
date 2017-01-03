/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_to_server.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:00:16 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/03/23 17:00:24 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network/connect_to_server.h"

static int			init_client(int sockfd, int port, const char *host)
{
	struct sockaddr_in	to;

	ft_bzero(&to, sizeof(to));
	to.sin_family = AF_INET;
	to.sin_port = htons(port);
	to.sin_addr.s_addr = inet_addr(host);
	if (connect(sockfd, (struct sockaddr *)&to, sizeof(struct sockaddr_in)) < 0)
		return (0);
	return (1);
}

int					connect_to_server(t_param *param)
{
	int			sockfd;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Socket creation fail\n");
		return (-1);
	}
	if (!init_client(sockfd, param->port, param->host))
	{
		printf("Socket initialization fail\n");
		return (-1);
	}
	return (sockfd);
}
