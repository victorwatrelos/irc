/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_loggin.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_LOGGIN_H
# define FN_LOGGIN_H

# include "struct_client.h"
# define MSG_SUCCESS "You are now log on the server"

int		fn_001(t_num_resp_param *param, t_data *data);
int		fn_002(t_num_resp_param *param, t_data *data);
int		fn_003(t_num_resp_param *param, t_data *data);
int		fn_004(t_num_resp_param *param, t_data *data);
void	check_if_all(t_data *data);
void	push_msg(const char *msg, t_data *data);

#endif
