/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_client.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:18 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CLIENT_H
# define READ_CLIENT_H

# include <ft_printf.h>
# include <bool.h>
# include "struct_client.h"
# include "add_cmd.h"
# include <read_socket.h>

t_bool			read_client(int sockfd, t_data *data);

#endif
