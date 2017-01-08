/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rpl_endofname.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_RPL_ENDOFNAME_H
# define SEND_RPL_ENDOFNAME_H

# include <client_utils.h>
# define MSG_ENDOFNAME ":End of NAMES list"

void		send_rpl_endofname(t_client *dest, const char *chan_name);

#endif
