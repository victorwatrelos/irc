#include "fn/user.h"

int		user_fn(const char *param_str, t_client *client)
{
	int			size;
	const char	*next;
	const char	*param;
	char		*user;
	char		*mode;
	char		*realname;
	char		upper_username[MAX_SIZE_USERNAME + 1];
	int			i;

	i = 0;
	while (i < 4)
	{
		param = next_param(param_str, &size, &next);
		if (param == NULL)
			return (ERR_NEEDMOREPARAMS);
		if (size > 512)
			return (UNEXPECTED_ERROR);
		if (i == 0)
			user = ft_strndup(param, size);
		else if (i == 1)
			mode = ft_strndup(param, size);
		else if (i == 3)
			realname = ft_strndup(param, size);

		param_str = next;
		i++;
	}
	ft_strncpy(upper_username, user, MAX_SIZE_USERNAME);
	to_upper_rfc(upper_username);
	if (!is_username_free(client->st_data->client_list, upper_username))
		return (ERR_ALREADYREGISTRED);
	ft_strncpy(client->upper_username, upper_username, MAX_SIZE_USERNAME);
	ft_strncpy(client->username, user, MAX_SIZE_USERNAME);
	ft_strncpy(client->usermode, mode, MAX_SIZE_USERMODE);
	ft_strncpy(client->realname, realname, MAX_SIZE_REALNAME);
	client->username_set = TRUE;
	send_success_login(client);
	return (CMD_SUCCESS);
}
