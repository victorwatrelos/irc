/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_sockfd.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:09:59 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:02 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_TO_SOCKFD_H
# define SEND_TO_SOCKFD_H

# include <circular_buffer.h>
# include <struct_global.h>

int			send_to_sockfd(int sockfd, t_send_buff *buff,
		t_circ_buff *circ_buff_out);

#endif
