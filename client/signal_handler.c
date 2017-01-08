/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:18 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"
#include <readline/readline.h>

void	exit_clean(t_data *p_data, int mod)
{
	static t_data		*data = NULL;

	if (p_data != NULL)
	{
		data = p_data;
		return ;
	}
	if (data == NULL)
		return ;
	close(data->sockfd);
	if (mod == 1)
	{
		data->sockfd = -1;
		data->is_connected = FALSE;
	}
	else
	{
		delete_circular_buffer(data->buff_out);
		delete_circular_buffer(data->display_out);
		rl_callback_handler_remove();
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		exit_clean(NULL, 0);
		printf("Exit\n");
		exit(0);
	}
	if (signal == SIGPIPE)
	{
		exit_clean(NULL, 1);
	}
}
