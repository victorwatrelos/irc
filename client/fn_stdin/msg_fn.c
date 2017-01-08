/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_fn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_stdin/fn_stdin.h"

static void	send_msg(const char *target, const char *msg, t_data *data)
{
	char	*res;
	int		final_size;

	final_size = ft_strlen(target) + ft_strlen(msg) + sizeof(MSG_MSG_BASE) + 4;
	if ((res = malloc(final_size)) == NULL)
		return ;
	ft_strcpy(res, MSG_MSG_BASE);
	ft_strcat(res, target);
	ft_strcat(res, " :");
	ft_strcat(res, msg);
	ft_strcat(res, "\n");
	push_back_circular_buffer(data->buff_out, res);
}

int			msg_fn(const char *params, t_data *data)
{
	int			size_target;
	int			size_msg;
	char		*target;
	char		*msg;
	const char	*start_msg;

	size_target = jump_to_space(params, 0);
	if ((target = malloc(size_target + 1)) == NULL)
		return (FALSE);
	ft_strncpy(target, params, size_target);
	target[size_target] = '\0';
	start_msg = jump_end_of_space(params, size_target) + params;
	size_msg = ft_strlen(start_msg);
	msg = malloc(size_msg + 1);
	ft_strncpy(msg, start_msg, size_msg);
	msg[size_msg] = '\0';
	send_msg(target, msg, data);
	free(msg);
	free(target);
	return (TRUE);
}
