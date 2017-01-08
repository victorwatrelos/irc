/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_to_server.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:03:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2016/03/23 17:03:13 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT_TO_SERVER_H
# define CONNECT_TO_SERVER_H

# include "struct_client.h"
# include <libft.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>

int		connect_to_server(t_param *param);

#endif
