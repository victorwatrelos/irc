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

#include "init_server.h"

int				init_serv(int *sockfd, int port)
{
	struct sockaddr_in	this;

	*sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (*sockfd < 0)
		return (FALSE);
	ft_bzero(&this, sizeof(this));
	this.sin_family = AF_INET;
	this.sin_port = htons(port);
	this.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(*sockfd, (struct sockaddr *)&this, sizeof(this)) < 0)
		return (FALSE);
	if (listen(*sockfd, 255) < 0)
		return (FALSE);
	ft_printf("Server start on %d\n", port);
	return (TRUE);
}
