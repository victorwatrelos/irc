#ifndef SEND_JOIN_MSG_H
# define SEND_JOIN_MSG_H

# include <struct.h>

# define MSG_JOIN_BASE_START " JOIN "
# define MSG_PART_BASE_START " PART "

void	send_join_msg(t_channel *chan, t_client *dst, t_client *src);
void	send_part_msg(t_channel *chan, t_client *dst, t_client *src);

#endif
