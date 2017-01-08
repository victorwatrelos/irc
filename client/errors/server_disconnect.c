/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_disconnect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors/server_disconnect.h"

void		server_disconnect(t_data *data)
{
	data->sockfd = -1;
	data->is_connected = FALSE;
	printf("Server %s:%d disconnect\n", data->host, data->port);
}
