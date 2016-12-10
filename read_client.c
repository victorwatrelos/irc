#include "read_client.h"

static t_bool	get_carriage_flag(t_client *client)
{
	if (client->size_current_msg <= 0)
		return (FALSE);
	return (client->curr_cmd[0] == '\r');
}

static void	cat_cmd(t_client *client, const char *msg, int size)
{
	t_bool	carriage;
	t_bool	eol;
	int		i;

	printf("message: --%s--\n", msg);
	eol = FALSE;
	carriage = get_carriage_flag(client);
	i = 0;
	while (i < size)
	{
		printf("%x-", (int)msg[i]);
		if (msg[i] == 0x0D)
			carriage = TRUE;
		else if (msg[i] == 0x0A && carriage)
			eol = TRUE;
		else
		{
			carriage = FALSE;
			eol = FALSE;
		}
		if (carriage && eol)
		{
			if (i + client->size_current_msg > MAX_CMD_SIZE)
				break ;
			ft_strncat(client->curr_cmd, msg, i - 1);
			add_cmd(client);
		}
		i++;
	}
	if (i + client->size_current_msg > MAX_CMD_SIZE)
	{
		client->size_current_msg = 0;
		client->curr_cmd[0] = '\0';
		ft_printf("%rCmd with a size > to 512\n");
		cat_cmd(client, msg + i, size - i);
		return ;
	}
	ft_strncat(client->curr_cmd, msg, i);
	client->size_current_msg += i;
}

void		read_client(t_list *client_elem, t_list **lst_client)
{
	int			ret;
	char		buff[MAX_CMD_SIZE + 1];
	t_client	*client;

	client = client_elem->content;
	if ((ret = read(client->sockfd, buff, MAX_CMD_SIZE)) < 0)
	{
		ft_printf("%rClient %d disconnect\n", client->sockfd);
		failure_exit_client(client_elem, lst_client);
		return;
	}
	if (ret == 0)
	{
		ft_printf("%rClient %d disconnect\n", client->sockfd);
		failure_exit_client(client_elem, lst_client);
		return ;
	}
	buff[ret] = '\0';
	cat_cmd(client, buff, ret);
}
