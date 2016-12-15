#ifndef SEND_MSG_TO_CLIENT_H
# define SEND_MSG_TO_CLIENT_H

# define PRIVMSG " PRIVMSG "

void		send_msg_to_client(t_client *dest, t_client *src, const char *msg);

#endif
