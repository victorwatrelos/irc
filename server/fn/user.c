#include "fn/user.h"

static int	process_user(t_client_param *param, t_client *client)
{
	ft_strncpy(param->upper_username, param->user, MAX_SIZE_USERNAME);
	to_upper_rfc(param->upper_username);
	if (!is_username_free(client->st_data->client_list, param->upper_username))
		return (ERR_ALREADYREGISTRED);
	ft_strncpy(client->upper_username, param->upper_username,
			MAX_SIZE_USERNAME);
	client->upper_username[MAX_SIZE_USERNAME] = '\0';
	ft_strncpy(client->username, param->user, MAX_SIZE_USERNAME);
	client->username[MAX_SIZE_USERNAME] = '\0';
	ft_strncpy(client->usermode, param->mode, MAX_SIZE_USERMODE);
	client->usermode[MAX_SIZE_USERMODE] = '\0';
	ft_strncpy(client->realname, param->realname, MAX_SIZE_REALNAME);
	client->realname[MAX_SIZE_REALNAME] = '\0';
	client->username_set = TRUE;
	send_success_login(client);
	return (CMD_SUCCESS);
}

static int	process_param(t_client_param *param_fn, t_client *client)
{
	int		i;

	i = process_user(param_fn, client);
	free(param_fn->realname);
	free(param_fn->mode);
	free(param_fn->user);
	return (i);
}

int			user_fn(const char *param_str, t_client *client)
{
	int				size;
	const char		*next;
	const char		*param;
	t_client_param	param_fn;
	int				i;

	i = 0;
	while (i < 4)
	{
		param = next_param(param_str, &size, &next);
		if (param == NULL)
			return (ERR_NEEDMOREPARAMS);
		if (size > 512)
			return (UNEXPECTED_ERROR);
		if (i == 0)
			param_fn.user = ft_strndup(param, size);
		else if (i == 1)
			param_fn.mode = ft_strndup(param, size);
		else if (i == 3)
			param_fn.realname = ft_strndup(param, size);
		param_str = next;
		i++;
	}
	return (process_param(&param_fn, client));
}
