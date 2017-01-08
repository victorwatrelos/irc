/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_err_cmd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_ERR_CMD_H
# define SEND_ERR_CMD_H

# include "fn/fn.h"
# include "get_numeric_response.h"

typedef struct	s_err_map
{
	int			err;
	const char	*msg;
	const char	*code;
}				t_err_map;

void			send_err_cmd(int err, t_client *client);

#endif
