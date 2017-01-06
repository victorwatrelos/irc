#include "parser/read_privmsg.h"

static char	*get_sender(const char *host, int size)
{
	int		i;
	char	*res;

	i = 0;
	while (i < size && host[i] != '@' && host[i] != '\0')
		i++;
	if ((res = malloc(i + 1)) == NULL)
		return (NULL);
	ft_strncpy(res, host, i);
	res[i] = '\0';
	return (res);
}

char	*get_target(const char *msg, int *i)
{
	int		size;
	char	*res;

	size = jump_to_space(msg, 0);
	*i = size;
	if ((res = malloc(size + 1)) == NULL)
		return (NULL);
	ft_strncpy(res, msg, size);
	res[size] = '\0';
	return (res);
}

char	*get_msg(const char *msg)
{
	const char	*start_msg;
	char		*res;
	int			size;

	start_msg = jump_end_of_space(msg, 0) + msg;
	if (*start_msg == '\0')
		return (NULL);
	start_msg++;
	size = ft_strlen(start_msg);
	if ((res = malloc(size + 1)) == NULL)
		return (NULL);
	size--;
	if (size == 0)
	{
		free(res);
		return (NULL);
	}
	ft_strncpy(res, start_msg, size);
	res[size] = '\0';
	return (res);
}

static void	push_resp(const char *sender, const char *target, const char *msg, t_data *data)
{
	char		*res;
	int			final_size;

	final_size = sizeof(OPENING) + sizeof(CLOSING_MID) + sizeof(CLOSING)
		+ ft_strlen(sender) + ft_strlen(target) + ft_strlen(msg) + 1;
	if ((res = malloc(final_size)) == NULL)
		return ;
	ft_strcpy(res, OPENING);
	ft_strcat(res, sender);
	ft_strcat(res, CLOSING_MID);
	ft_strcat(res, target);
	ft_strcat(res, CLOSING);
	ft_strcat(res, msg);
	push_back_circular_buffer(data->display_out, res);
}

t_bool	read_privmsg(t_num_resp_param *param, t_data *data)
{
	char	*sender;
	char	*target;
	char	*msg;
	int		i;

	if ((sender = get_sender(param->host, param->size_host)) == NULL)
		return (FALSE);
	if ((target = get_target(param->msg, &i)) == NULL)
		return (FALSE);
	if ((msg = get_msg(param->msg + i)) == NULL)
		return (FALSE);
	push_resp(sender, target, msg, data);
	free(sender);
	free(target);
	free(msg);
	return (TRUE);
}
