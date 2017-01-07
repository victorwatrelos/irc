#ifndef SEND_RPL_ENDOFNAME_H
# define SEND_RPL_ENDOFNAME_H

# include <client_utils.h>
# define MSG_ENDOFNAME ":End of NAMES list"

void		send_rpl_endofname(t_client *dest, const char *chan_name);

#endif
