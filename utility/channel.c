#include "channel.h"

t_bool	is_channel_name_valid(const char *channel)
{
	if (ft_strchr(LIST_FIRST_CHAR, channel[0]) == NULL)
		return (FALSE);
	if (ft_strchr(channel, '\x07') != NULL)
		return (FALSE);
	return (TRUE);
}
