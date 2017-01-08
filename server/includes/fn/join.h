/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOIN_H
# define JOIN_H

# include "global.h"
# include "struct.h"
# include "str_utils.h"
# include "client_utils.h"
# include "channel.h"
# include "params.h"
# include "fn/fn.h"
# include <libft.h>
# include "msg_error/send_nosuchchannel.h"
# include "msg/send_rpl_namereply.h"
# include "msg/send_join_msg.h"

int			add_to_chan(t_channel *channel, t_client *client);
t_channel	*create_channel(const char *channel_name,
		const char *upper_channel_name);

#endif
