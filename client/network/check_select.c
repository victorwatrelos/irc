/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:18 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "network/check_select.h"

t_data	*set_data(t_data *p_data)
{
	static t_data	*data = NULL;

	if (p_data != NULL)
		data = p_data;
	return (data);
}

void	callback_readline(char *line)
{
	t_data	*data;

	if (line == NULL)
	{
		return ;
	}
	if (ft_strlen(line) > 0)
		add_history(line);
	data = set_data(NULL);
	read_stdin(data, line);
	free(line);
	rl_callback_handler_remove();
	rl_callback_handler_install("", (VCPFunction *)&callback_readline);
}

int		check_select(t_select *st_select, int sockfd, t_data *data)
{
	if (sockfd > 0 && FD_ISSET(sockfd, &(st_select->read)))
	{
		if (!read_client(sockfd, data))
			return (SERVER_DISCONNECT);
	}
	if (FD_ISSET(0, &(st_select->read)))
	{
		rl_callback_read_char();
	}
	if (sockfd > 0 && (get_size_circular_buffer(data->buff_out) > 0
				|| data->send_buff.start != data->send_buff.end)
			&& FD_ISSET(sockfd, &(st_select->write)))
	{
		if (!write_client(sockfd, data))
			return (SERVER_DISCONNECT);
	}
	return (SUCCESS);
}
