#ifndef FN_RESP_H
# define FN_RESP_H

# include "struct_client.h"
# include <str_utils.h>
# include <circular_buffer.h>
# define MSG_353_RESP_START "Channel "
# define MSG_353_RESP_MIDDLE " have users: "
# define MSG_JOIN_RESP_END " has join the channel "
# define MSG_PART_RESP_END " has leave the channel "

int		fn_353(t_num_resp_param *param, t_data *data);
int		fn_366(t_num_resp_param *param, t_data *data);
int		fn_join_resp(t_num_resp_param *param, t_data *data);
int		fn_part_resp(t_num_resp_param *param, t_data *data);

#endif
