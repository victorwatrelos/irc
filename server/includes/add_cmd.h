/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_CMD_H
# define ADD_CMD_H

# include "struct.h"
# include "const_global.h"
# include "str_utils.h"
# include "msg_error/send_err_cmd.h"

void	add_cmd(t_cat_cmd *st_cat_cmd, t_client *client);

#endif
