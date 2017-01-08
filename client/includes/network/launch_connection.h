/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_connection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCH_CONNECTION_H
# define LAUNCH_CONNECTION_H

# include <global.h>
# include <ft_printf.h>
# include <bool.h>
# include "struct_client.h"
# include "network/check_select.h"
# include "network/connect_to_server.h"
# include "errors/server_disconnect.h"
# include "disp_msg.h"

int		launch_connection(const char *ip, int32_t port);

#endif
