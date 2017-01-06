#ifndef READ_NUM_RESP_H
# define READ_NUM_RESP_H

# include <str_utils.h>
# include "struct_client.h"
# include "client_const_global.h"
# include "parser/read_privmsg.h"

t_bool			read_num_resp(const char *cmd, t_data *data);

#endif
