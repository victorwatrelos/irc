/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 18:05:01 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/06/21 18:06:47 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network/init_server.h"

int				init_serv(int *sockfd, int port)
{
	struct sockaddr_in6	this;

	*sockfd = socket(AF_INET6, SOCK_STREAM, 0);
	if (*sockfd < 0)
		return (FALSE);
	ft_bzero(&this, sizeof(this));
	this.sin6_family = AF_INET6;
	this.sin6_port = htons(port);
	this.sin6_addr = in6addr_any;
	if (bind(*sockfd, (struct sockaddr *)&this, sizeof(this)) < 0)
		return (FALSE);
	if (listen(*sockfd, 255) < 0)
		return (FALSE);
	ft_printf("Server start on %d\n", port);
	return (TRUE);
}
