#include "channel.h"

t_bool	is_channel_name_valid(const char *channel)
{
	if (ft_strchr(LIST_FIRST_CHAR, channel[0]) == NULL)
		return (FALSE);
	if (ft_strchr(channel, '\x07') != NULL)
		return (FALSE);
	return (TRUE);
}

void	remove_one(t_channel *channel, t_client *p_client)
{
	t_list		*client_lst;
	t_list		**ptn_client_lst;

	ptn_client_lst = &(channel->client_lst);
	client_lst = *ptn_client_lst;
	while (client_lst)
	{
		if (client_lst->content == p_client)
		{
			printf("remove %s\n", p_client->nickname);
			ft_lstdelone(ptn_client_lst, client_lst);
			return ;
		}
		client_lst = client_lst->next;
	}
}

void	leave_all(t_client *client)
{
	t_list	*channel_lst;

	channel_lst = client->st_data->channel_list;
	while (channel_lst)
	{
		remove_one(channel_lst->content, client);
		channel_lst = channel_lst->next;
	}
}
