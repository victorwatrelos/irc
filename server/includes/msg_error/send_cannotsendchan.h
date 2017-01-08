/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_cannotsendchan.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_CANNOTSENDCHAN_H
# define SEND_CANNOTSENDCHAN_H

# include "struct.h"
# include "get_numeric_response.h"
# define CANNOT_SEND ":Cannot send to channel"

void	send_cannotsendchan(const char *chan_name, t_client *client);

#endif
