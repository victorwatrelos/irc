#ifndef SEND_CANNOTSENDCHAN_H
# define SEND_CANNOTSENDCHAN_H

# include "struct.h"
# include "get_numeric_response.h"
# define CANNOT_SEND ":Cannot send to channel"

void	send_cannotsendchan(const char *chan_name, t_client *client);


#endif
