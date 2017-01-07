/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 14:15:38 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/06/24 14:15:59 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_SERVER_H
# define INIT_SERVER_H

# include <sys/socket.h>
# include <netinet/in.h>
# include "libft.h"
# include "bool.h"
# include "ft_printf.h"

int				init_serv(int *sockfd, int port);

#endif
