#ifndef CHANNEL_H
# define CHANNEL_H

# define LIST_FIRST_CHAR "&#+!"
# include <libft.h>
# include "bool.h"
# include "struct.h"

t_bool	is_channel_name_valid(const char *channel);
void	leave_all(t_client *client);
void	remove_one(t_channel *channel, t_client *p_client);

#endif
