#ifndef SEND_NOSUCHCHANNEL_H
# define SEND_NOSUCHCHANNEL_H

# include "struct.h"
# include "get_numeric_response.h"

# define NOSUCHCHANNEL	":No such channel"

void	send_nosuchchannel(const char *chan_name, t_client *client);

#endif
