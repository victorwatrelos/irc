#include "send_msg_to_client.h"

void		send_msg_to_client(t_client *dest, t_client *src, const char *msg)
{
	nick@hostname PRIVMSG target :msg
	size_t		final_size;
	char		*res;

	final_size = ft_strlen(src->nickname) + ft_strlen(src->hostname)
		+ sizeof(PRIVMSG) + ft_strlen(dest->nickname) + ft_strlen(msg) + 4;
	if ((res = malloc(final_size)) == NULL)
		return ;

	ft_strcpy(res, src->nickname);
	ft_strcat(res, "@");
	ft_strcat(res, src->hostname);
	ft_strcat(res, PRIVMSG);
	ft_strcat(res, dest->nickname);
	ft_strcat(res, " ");
	ft_strcat(res, msg);
	push_back_circular_buffer(dest->cmd_queue.buff_out, res);
}
