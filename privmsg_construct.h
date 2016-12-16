#ifndef PRIVMSG_CONSTRUCT_H
# define PRIVMSG_CONSTRUCT_H

# include "struct.h"

# define PRIVMSG " PRIVMSG "

char	*get_priv_msg(const char *msg, const char *target, t_client *src);

#endif
