#ifndef SEND_MSG_TO_CLIENT_H
# define SEND_MSG_TO_CLIENT_H

# include "struct.h"
# include "privmsg_construct.h"

void		send_msg_to_client(t_client *dest, t_client *src, const char *msg);

#endif
