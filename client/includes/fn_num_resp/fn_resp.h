#ifndef FN_RESP_H
# define FN_RESP_H

# include "struct_client.h"
# include <str_utils.h>
# include <circular_buffer.h>
# define MSG_353_RESP_START "You have joined the channel "
# define MSG_353_RESP_MIDDLE " with users: "

int		fn_353(t_num_resp_param *param, t_data *data);

#endif
