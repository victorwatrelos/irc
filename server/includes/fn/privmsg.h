#ifndef PRIVMSG_H
# define PRIVMSG_H

# include "msg_error/send_cannotsendchan.h"
# include "global.h"
# include "struct.h"
# include "str_utils.h"
# include "client_utils.h"
# include "channel.h"
# include "fn.h"
# include <libft.h>
# include "msg_error/send_nosuchchannel.h"
# include "send_to_chan.h"
# include "send_msg_to_client.h"

typedef struct		s_p_privmsg
{
	const char		*start_target;
	const char		*start_msg;
	size_t			size_msg;
	size_t			size_target;
}					t_p_privmsg;

#endif
