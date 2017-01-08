/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_resp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_RESP_H
# define FN_RESP_H

# include "struct_client.h"
# include <str_utils.h>
# include <circular_buffer.h>
# define MSG_353_RESP_START "Channel "
# define MSG_353_RESP_MIDDLE " have users: "
# define MSG_JOIN_RESP_END " has join the channel "
# define MSG_PART_RESP_END " has leave the channel "
# define MSG_432 "Bad nickname"
# define MSG_403 "Channel name invalid"
# define MSG_461 "Not enough parameter"
# define MSG_404 "Cannot send to channel"
# define MSG_433 "Nickname is already in use"

int		fn_353(t_num_resp_param *param, t_data *data);
int		fn_366(t_num_resp_param *param, t_data *data);
int		fn_432(t_num_resp_param *param, t_data *data);
int		fn_403(t_num_resp_param *param, t_data *data);
int		fn_404(t_num_resp_param *param, t_data *data);
int		fn_461(t_num_resp_param *param, t_data *data);
int		fn_433(t_num_resp_param *param, t_data *data);
int		fn_462(t_num_resp_param *param, t_data *data);
int		fn_join_resp(t_num_resp_param *param, t_data *data);
int		fn_part_resp(t_num_resp_param *param, t_data *data);

#endif
