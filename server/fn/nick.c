/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:07 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn/nick.h"

int			nick_fn(const char *param_str, t_client *client)
{
	int		end;
	int		start;
	char	nickname[NICK_MAXSIZE + 1];
	char	upper_nickname[NICK_MAXSIZE + 1];

	start = jump_end_of_space(param_str, 0);
	end = jump_to_space(param_str, start);
	if (start == end)
		return (NICK_NO_PARAM);
	if (end - start > NICK_MAXSIZE)
		return (NICK_TOO_LONG);
	nickname[end - start] = '\0';
	ft_strncpy(nickname, param_str + start, end - start);
	ft_strcpy(upper_nickname, nickname);
	to_upper_rfc(upper_nickname);
	if (!is_nick_free(client->st_data->client_list, upper_nickname))
		return (NICK_ALREADY_TAKEN);
	if (!is_nick_valid(upper_nickname))
		return (NICK_BAD_CHAR);
	ft_strcpy(client->upper_nickname, upper_nickname);
	ft_strcpy(client->nickname, nickname);
	client->nick_set = TRUE;
	send_success_login(client);
	return (CMD_SUCCESS);
}
