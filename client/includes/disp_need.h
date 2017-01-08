/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_need.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISP_NEED_H
# define DISP_NEED_H

# include "struct_client.h"

# define MSG_DISP_NEED_CONNECT "You first need to /connect <ip> <port>"
# define MSG_DISP_NEED_NICK "You first need to /nick <name>"

void	disp_need_nick(t_data *data);
void	disp_need_connect(t_data *data);

#endif
