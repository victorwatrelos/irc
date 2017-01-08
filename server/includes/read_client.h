/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_client.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:11 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CLIENT_H
# define READ_CLIENT_H

# include "struct.h"
# include "errors/failure_exit.h"
# include <ft_printf.h>
# include "bool.h"
# include "add_cmd.h"
# include "read_socket.h"

t_bool		read_client(t_list *client_elem, t_list **lst_client);

#endif
