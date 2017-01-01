#ifndef SEND_RPL_NAMEREPLY_H
# define SEND_RPL_NAMEREPLY_H


#include <client_utils.h>

void	send_rpl_namereply(t_list *client_lst, t_client *dest, const char *chan_name);

#endif
