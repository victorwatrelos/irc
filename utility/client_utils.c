#include "client_utils.h"

t_bool		is_nick_free(t_list *client_lst, const char *nick)
{
	t_client	*client;
	t_list		*next;

	while (client_lst)
	{
		next = client_lst->next;
		client = client_lst->content;
		if (ft_strncmp(client->upper_nickname, nick, NICK_MAXSIZE) == 0)
		{
			return (FALSE);
		}
		client_lst = next;
	}
	return (TRUE);
}

t_bool		is_username_free(t_list *client_lst, const char *upper_username)
{
	t_client	*client;
	t_list		*next;

	while (client_lst)
	{
		next = client_lst->next;
		client = client_lst->content;
		if (ft_strncmp(client->upper_username, upper_username, MAX_SIZE_USERNAME) == 0)
		{
			return (FALSE);
		}
		client_lst = next;
	}
	return (TRUE);
}

t_bool		is_nick_valid(const char *nick)
{
	int			i;

	i = 0;
	while (nick[i] != '\0')
	{
		if (i == 0 && (ft_isdigit(nick[i]) || nick[i] == '-'))
			return (FALSE);
		if (ft_strchr(AUTHORIZED_CHAR_NICK, nick[i]) == NULL)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static char	*get_num_resp(t_client *dest, const char *msg)
{
	const char	*data[4];

	data[HOSTNAME] = dest->hostname;
	data[CODE] = "353";
	data[NICKNAME] = dest->nickname;
	data[MSG] = msg;
	return (get_numeric_response_custom(data, FALSE));
}

void		send_rpl_namereply(t_list *client_lst, t_client *dest, const char *chan_name)
{
	char	*msg;
	size_t	final_size;
	t_list	*client_elem;
	char	*response;

	final_size = ft_strlen(chan_name) + 6;
	client_elem = client_lst;
	while (client_elem)
	{
		final_size += ft_strlen(((t_client *)client_elem->content)->nickname) + 1;
		client_elem = client_elem->next;
	}
	if ((msg = malloc(final_size)) == NULL)
		return ;
	ft_strcpy(msg, " = ");
	ft_strcat(msg, chan_name);
	ft_strcat(msg, " :");
	while (client_lst)
	{
		ft_strcat(msg, ((t_client *)client_lst->content)->nickname);
		ft_strcat(msg, " ");
		client_lst = client_lst->next;
	}
	response = get_num_resp(dest, msg);
	free(msg);
	push_back_circular_buffer(dest->cmd_queue.buff_out, response);
}
