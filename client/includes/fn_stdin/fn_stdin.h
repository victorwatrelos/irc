/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_stdin.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_STDIN_H
# define FN_STDIN_H

# include "struct_client.h"
# include <bool.h>
# include <stdio.h>
# include <str_utils.h>
# include "network/connect_to_server.h"

# define MSG_NICK_BASE "NICK "
# define MSG_USER_BASE "USER "
# define MSG_USER_MIDDLE " 0 * "
# define MSG_JOIN_BASE "JOIN "
# define MSG_WHO_BASE "NAMES "
# define MSG_PART_BASE "PART "
# define MSG_MSG_BASE "PRIVMSG "
# define MSG_CON_FAIL "Connection with the server fail"

int		connect_fn(const char *params, t_data *data);
int		nick_fn(const char *cmd, t_data *data);
int		join_fn(const char *params, t_data *data);
int		leave_fn(const char *params, t_data *data);
int		msg_fn(const char *params, t_data *data);
int		who_fn(const char *params, t_data *data);

#endif
