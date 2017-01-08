/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:18 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_client.h"

t_bool		write_client(int sockfd, t_data *data)
{
	if (send_to_sockfd(sockfd, &(data->send_buff), data->buff_out) < 0)
		return (FALSE);
	return (TRUE);
}
