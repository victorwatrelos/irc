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

static t_bool	browse_ip(int sockfd, struct addrinfo *servinfo, int port)
{
	struct addrinfo		*p;
	struct sockaddr_in6 *h;
	char				ip[INET6_ADDRSTRLEN];

	p = servinfo;
	while (p)
	{
		h = (struct sockaddr_in6 *)p->ai_addr;
		inet_ntop(p->ai_family, &h->sin6_addr, ip, INET6_ADDRSTRLEN);
		if (ft_strcmp(ip, "0.0.0.0") == 0)
		{
			p = p->ai_next;
			continue ;
		}
		h->sin6_family = p->ai_family;
		h->sin6_port = htons(port);
		if (connect(sockfd, p->ai_addr, p->ai_addrlen) >= 0)
			return (1);
		p = p->ai_next;
	}
	return (0);
}

static int		hostname_to_ip(const char *hostname, int port)
{
	struct addrinfo hints;
	struct addrinfo	*servinfo;
	int				rv;
	char			*port_str;
	int				sockfd;

	port_str = ft_itoa(port);
	ft_bzero(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if ((rv = getaddrinfo(hostname, port_str, &hints, &servinfo)) != 0)
	{
		free(port_str);
		return (-1);
	}
	if ((sockfd = socket(servinfo->ai_family, SOCK_STREAM, 0)) < 0)
		return (-1);
	free(port_str);
	if (browse_ip(sockfd, servinfo, port) == 0)
	{
		freeaddrinfo(servinfo);
		return (-1);
	}
	freeaddrinfo(servinfo);
	return (sockfd);
}

static int		init_client_ipv4(int port, const char *host)
{
	struct sockaddr_in	to;
	int					sockfd;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (-1);
	ft_bzero(&to, sizeof(to));
	to.sin_family = AF_INET;
	to.sin_port = htons(port);
	if (inet_pton(AF_INET, host, &(to.sin_addr)) == 0)
	{
		close(sockfd);
		return (-1);
	}
	if (connect(sockfd, (struct sockaddr *)&to, sizeof(struct sockaddr_in)) < 0)
	{
		close(sockfd);
		return (-1);
	}
	return (sockfd);
}

static int		init_client_ipv6(int port, const char *host)
{
	struct sockaddr_in6	to;
	int					sockfd;

	if ((sockfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
		return (-1);
	ft_bzero(&to, sizeof(to));
	to.sin6_family = AF_INET6;
	to.sin6_port = htons(port);
	if (inet_pton(AF_INET6, host, to.sin6_addr.s6_addr) == 0)
	{
		close(sockfd);
		return (-1);
	}
	if (connect(sockfd, (struct sockaddr *)&to,
				sizeof(struct sockaddr_in6)) < 0)
	{
		close(sockfd);
		return (-1);
	}
	return (sockfd);
}

int				connect_to_server(t_param *param)
{
	int			sockfd;

	if (param->host == NULL)
	{
		return (-1);
	}
	if ((sockfd = hostname_to_ip(param->host, param->port)) >= 0)
		return (sockfd);
	if ((sockfd = init_client_ipv6(param->port, param->host)) >= 0)
		return (sockfd);
	if ((sockfd = init_client_ipv4(param->port, param->host)) >= 0)
		return (sockfd);
	printf("Connection fail\n");
	return (-1);
}
