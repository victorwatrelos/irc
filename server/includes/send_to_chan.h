#ifndef SEND_TO_CHAN_H
# define SEND_TO_CHAN_H

# include "privmsg_construct.h"

void	send_to_chan(t_channel *channel, const char *msg, t_client *src);

#endif
