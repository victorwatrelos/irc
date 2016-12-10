#include "nick.h"

int		nick_fn(const char *param_str, t_client *client)
{
	int		end;
	int		start;
	char	nickname[NICK_MAXSIZE + 1];

	start = jump_end_of_space(param_str, 0);
	end = jump_to_space(param_str, start);
	if (start == end)
		return (NICK_NO_PARAM);
	if (end - start > NICK_MAXSIZE)
		return (NICK_TOO_LONG);
	nickname[end - start] = '\0';
	ft_strncpy(client->nickname, param_str + start, end - start);
	ft_strcpy(client->upper_nickname, client->nickname);
	to_upper_rfc(client->upper_nickname);
	if (!nick_used(client->st_data->client_list, client->upper_nickname))
			return (NICK_ALREADY_TAKEN);
	if (!is_nick_valid(client->upper_nickname))
			return (NICK_BAD_CHAR);
	return (CMD_SUCCESS);
}
