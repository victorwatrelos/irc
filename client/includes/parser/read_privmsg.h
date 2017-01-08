/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_privmsg.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_PRIVMSG_H
# define READ_PRIVMSG_H

# include "struct_client.h"
# include <str_utils.h>
# define OPENING "["
# define CLOSING_MID "]->["
# define CLOSING "]: "

t_bool	read_privmsg(t_num_resp_param *param, t_data *data);

#endif
