#include "read_client.h"

static t_bool	get_carriage_flag(t_client *client)
{
	if (client->size_current_msg <= 0)
		return (FALSE);
	return (client->curr_cmd[0] == '\r');
}

static void	reset_client_msg(t_client *client)
{
	client->size_current_msg = 0;
	client->curr_cmd[0] = '\0';
}

static void	add_to_client(t_client *client, const char *msg, int size)
{
	if (client->size_current_msg + size > MAX_CMD_SIZE)
	{
		reset_client_msg(client);
		return ;
	}
	ft_strcat(client->curr_cmd, msg);
	client->size_current_msg += size;
}

static void	cat_cmd(t_client *client, const char *msg, int size)
{
	int		i;
	t_bool	carriage;
	t_bool	eol;
	t_bool	no_cmd;

	no_cmd = TRUE;
	//carriage = get_carriage_flag(client);
	carriage = TRUE;
	eol = FALSE;
	i = 0;
	while (i < size)
	{
		if (msg[i] == 0x0D)
			carriage = TRUE;
		else if (msg[i] == 0x0A && carriage)
			eol = TRUE;
		else
		{
	//		carriage = FALSE;
			eol = FALSE;
		}
		if (carriage && eol)
		{
			i++;//To have i point to next char of eol and be the size of the command
			if (i + client->size_current_msg > MAX_CMD_SIZE)//Command too long
			{
				reset_client_msg(client);
				no_cmd = FALSE;
				break ;
			}
			ft_strncpy((client->curr_cmd + client->size_current_msg), msg, i);
			client->curr_cmd[i + client->size_current_msg] = '\0';
			add_cmd(client);
			reset_client_msg(client);
			no_cmd = FALSE;
			break ;
		}
		i++;
	}
	if (no_cmd)
	{
		add_to_client(client, msg, size);
		return ;
	}
	cat_cmd(client, msg + i, size - i);
}

t_bool		read_client(t_list *client_elem, t_list **lst_client)
{
	int			ret;
	char		buff[MAX_CMD_SIZE + 1];
	t_client	*client;

	client = client_elem->content;
	if ((ret = read(client->sockfd, buff, MAX_CMD_SIZE)) <= 0)
	{
		ft_printf("%rClient %d disconnect\n", client->sockfd);
		failure_exit_client(client_elem, lst_client);
		return (FALSE);
	}
	buff[ret] = '\0';
	cat_cmd(client, buff, ret);
	return (TRUE);
}
