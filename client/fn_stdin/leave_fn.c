/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_stdin/fn_stdin.h"

int		leave_fn(const char *params, t_data *data)
{
	int			size_channels;
	char		*part_msg;

	size_channels = jump_to_space(params, 0);
	if ((part_msg = malloc(size_channels + sizeof(MSG_PART_BASE) + 1)) == NULL)
		return (0);
	ft_strcpy(part_msg, MSG_PART_BASE);
	ft_strncat(part_msg, params, size_channels);
	part_msg[size_channels + sizeof(MSG_PART_BASE)] = '\0';
	ft_strcat(part_msg, "\n");
	push_back_circular_buffer(data->buff_out, part_msg);
	return (1);
}
