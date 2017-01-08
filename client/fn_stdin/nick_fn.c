/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_stdin/fn_stdin.h"

static char	*get_nick_msg(const char *nickname)
{
	char	*res;

	res = malloc(sizeof(MSG_NICK_BASE) + ft_strlen(nickname) + 1);
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, MSG_NICK_BASE);
	ft_strcat(res, nickname);
	ft_strcat(res, "\n");
	return (res);
}

static char	*get_user_msg(const char *nickname)
{
	char	*res;

	res = malloc(sizeof(MSG_USER_BASE) + ft_strlen(nickname) * 2
			+ sizeof(MSG_USER_MIDDLE) + 1);
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, MSG_USER_BASE);
	ft_strcat(res, nickname);
	ft_strcat(res, MSG_USER_MIDDLE);
	ft_strcat(res, nickname);
	ft_strcat(res, "\n");
	return (res);
}

int			nick_fn(const char *params, t_data *data)
{
	char	*nick_msg;
	char	*user_msg;

	if ((nick_msg = get_nick_msg(params)) == NULL)
		return (FALSE);
	if ((user_msg = get_user_msg(params)) == NULL)
		return (FALSE);
	push_back_circular_buffer(data->buff_out, nick_msg);
	push_back_circular_buffer(data->buff_out, user_msg);
	return (TRUE);
}
