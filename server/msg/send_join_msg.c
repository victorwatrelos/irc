#include "msg/send_join_msg.h"

void	send_join_msg(t_channel *chan, t_client *dst, t_client *src)
{
	char	*res;
	size_t	final_size;

	final_size = 1 + ft_strlen(src->hostname) + 1 + sizeof(MSG_JOIN_BASE_START)
		+ sizeof(chan->name) + 2 + ft_strlen(src->nickname) + 1;
	if ((res = malloc(final_size)) == NULL)
		return ;
	ft_strcpy(res, ":");
	ft_strcat(res, src->nickname);
	ft_strcat(res, "!");
	ft_strcat(res, src->hostname);
	ft_strcat(res, MSG_JOIN_BASE_START);
	ft_strcat(res, chan->name);
	ft_strcat(res, "\n");
	push_back_circular_buffer(dst->cmd_queue.buff_out, res);
}

void	send_part_msg(t_channel *chan, t_client *dst, t_client *src)
{
	char	*res;
	size_t	final_size;

	final_size = 1 + ft_strlen(src->hostname) + 1 + sizeof(MSG_JOIN_BASE_START)
		+ sizeof(chan->name) + 2 + ft_strlen(src->nickname) + 1;
	if ((res = malloc(final_size)) == NULL)
		return ;
	ft_strcpy(res, ":");
	ft_strcat(res, src->nickname);
	ft_strcat(res, "!");
	ft_strcat(res, src->hostname);
	ft_strcat(res, MSG_PART_BASE_START);
	ft_strcat(res, chan->name);
	ft_strcat(res, "\n");
	push_back_circular_buffer(dst->cmd_queue.buff_out, res);
}
