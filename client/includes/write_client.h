/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_client.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:18 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_CLIENT_H
# define WRITE_CLIENT_H

# include <bool.h>
# include "struct_client.h"
# include <send_to_sockfd.h>

t_bool		write_client(int sockfd, t_data *data);

#endif
