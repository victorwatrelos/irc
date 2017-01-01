/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 17:46:55 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/06/24 17:49:48 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network/server.h"

void	set_fd_select(int sockfd, t_select *st_select)
{
	FD_ZERO(&(st_select->read));
	FD_ZERO(&(st_select->write));
	FD_SET(sockfd, &(st_select->read));
}
