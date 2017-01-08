/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_fn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_stdin/fn_stdin.h"

int		who_fn(const char *params, t_data *data)
{
	int			size_channels;
	char		*who_msg;

	size_channels = jump_to_space(params, 0);
	if ((who_msg = malloc(size_channels + sizeof(MSG_WHO_BASE) + 1)) == NULL)
		return (0);
	ft_strcpy(who_msg, MSG_WHO_BASE);
	ft_strncat(who_msg, params, size_channels);
	who_msg[size_channels + sizeof(MSG_WHO_BASE)] = '\0';
	ft_strcat(who_msg, "\n");
	push_back_circular_buffer(data->buff_out, who_msg);
	return (1);
}
