#ifndef DISP_NEED_H
# define DISP_NEED_H

# include "struct_client.h"

# define MSG_DISP_NEED_CONNECT "You first need to /connect <ip> <port>"
# define MSG_DISP_NEED_NICK "You first need to /nick <name>"

void	disp_need_nick(t_data *data);
void	disp_need_connect(t_data *data);

#endif
