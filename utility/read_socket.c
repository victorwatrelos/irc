#include "read_socket.h"

static void		reset_msg(t_cat_cmd *st_cat_cmd)
{
	st_cat_cmd->size_current_msg = 0;
	st_cat_cmd->curr_cmd[0] = '\0';
}

static void		add_to_cmd(t_cat_cmd *st_cat_cmd, const char *msg, int size)
{
	if (st_cat_cmd->size_current_msg + size > MAX_CMD_SIZE)
	{
		reset_msg(st_cat_cmd);
		return ;
	}
	ft_strcat(st_cat_cmd->curr_cmd, msg);
	st_cat_cmd->size_current_msg += size;
}

static void		process_msg(t_cat_cmd *st_cat_cmd,
		const char *msg, int i)
{
	if (i + st_cat_cmd->size_current_msg > MAX_CMD_SIZE)
	{
		reset_msg(st_cat_cmd);
		return ;
	}
	ft_strncpy((st_cat_cmd->curr_cmd + st_cat_cmd->size_current_msg), msg, i);
	st_cat_cmd->curr_cmd[i + st_cat_cmd->size_current_msg] = '\0';
	st_cat_cmd->callback(st_cat_cmd, st_cat_cmd->param_callback);
	reset_msg(st_cat_cmd);
}

static void		cat_cmd(t_cat_cmd *st_cat_cmd, const char *msg, int size)
{
	int		i;
	t_bool	no_cmd;

	no_cmd = TRUE;
	i = 0;
	while (i < size)
	{
		if (msg[i] == 0x0A)
		{
			++i;
			process_msg(st_cat_cmd, msg, i);
			no_cmd = FALSE;
			break ;
		}
		i++;
	}
	if (no_cmd)
	{
		add_to_cmd(st_cat_cmd, msg, size);
		return ;
	}
	cat_cmd(st_cat_cmd, msg + i, size - i);
}

t_bool			read_socket(int sockfd, t_cat_cmd *st_cat_cmd)
{
	int			ret;
	char		buff[MAX_CMD_SIZE + 1];

	if ((ret = read(sockfd, buff, MAX_CMD_SIZE)) <= 0)
	{
		ft_printf("%rClient %d disconnect\n", sockfd);
		return (FALSE);
	}
	buff[ret] = '\0';
	cat_cmd(st_cat_cmd, buff, ret);
	return (TRUE);
}
