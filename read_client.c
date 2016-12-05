#include "read_client.h"

static void	cat_cmd(t_client *client, const char *msg, int size)
{
	int		carriage;
	int		eol;
	int		i;

	eol = FALSE;
	carriage = FALSE;
	i = 0;
	while (i < size)
	{
		if (msg[i] == '\r')
			carriage = TRUE;
		else if (msg[i] == '\n' && carriage)
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
			ft_strncat(client->curr_cmd, msg, i - 2);
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
	ft_strncat(client->curr_cmd, 
}

void		read_client(t_list *client_elem, t_command_queue *cmd, t_list **lst_client)
{
	int			ret;
	char		buff[MAX_CMD_SIZE + 1];
	t_client	*client;

	client = client_elem->content;
	if ((ret = recv(client->sockfd, buff, MAX_CMD_SIZE, 0)) < 0)
	{
		ft_printf("%rClient %d disconnect\n", client->sockfd);
		failure_exit_client(client_elem, lst_client);
		return;
	}
	(void)client;
}
