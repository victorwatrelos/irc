#include "user.h"

int		user_fn(const char *param_str, t_client *client)
{
	int			size;
	const char	*next;
	const char	*param;
	char		*user;
	char		*mode;
	char		*realname;
	int			i;

	i = 0;
	while (i < 4)
	{
		param = next_param(param_str, &size, &next);
		if (param == NULL)
			return (ERR_NEEDMOREPARAMS);
		/*
		 * A switch would be better, but the Norm doesn't authorized it
		 */
		if (size > 512)
			return (UNEXPECTED_ERROR);
		if (i == 0)
			user = ft_strndup(param, size);
		else if (i == 1)
			mode = ft_strndup(param, size);
		else if (i == 3)
			realname = ft_strndup(param, size);
		i++;
	}
	printf("user: %s, mode: %s, realname: %s\n", user, mode, realname);
	return (CMD_SUCCESS);
}
