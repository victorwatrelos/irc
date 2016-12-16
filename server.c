/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/21 18:05:19 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/06/24 17:49:49 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	init_fd_set(int sockfd, t_list *clients, t_select *st_select)
{
	int			tmp_fd;
	int			fd_max;
	t_client	*tmp;

	set_fd_select(sockfd, st_select);
	fd_max = sockfd;
	while (clients != NULL)
	{
		tmp = (t_client *)clients->content;
		tmp_fd = tmp->sockfd;
		if (tmp_fd >= 0)
		{
			if (tmp_fd > fd_max)
				fd_max = tmp_fd;
			FD_SET(tmp_fd, &(st_select->read));
			if (get_size_circular_buffer(tmp->cmd_queue.buff_out) > 0
					|| tmp->send_buff.end != tmp->send_buff.start)
				FD_SET(tmp_fd, &(st_select->write));
		}
		clients = clients->next;
	}
	return (fd_max);
}

static int	select_wrapper(int sockfd, t_select *st_select, t_data_server *st_data)
{
	struct timeval	tv;
	int				fd_max;
	int				ret;

	tv.tv_sec = TIME_WAIT_SELECT_US / 1000000;
	tv.tv_usec = TIME_WAIT_SELECT_US % 1000000;
	fd_max = init_fd_set(sockfd, st_data->client_list, st_select) + 1;
	ret = select(fd_max + 1, &(st_select->read), &(st_select->write),
			NULL, &tv);
	if (ret < 0)
	{
		ft_printf("%rSelect fail\n");
		return (FALSE);
	}
	if (ret > 0)
		check_select(st_select, st_data);
	return (TRUE);
}

int			launch_select(int sockfd, t_data_server *s_data)
{
	t_select		st_select;

	st_select.sockfd = sockfd;
	s_data->st_select = &st_select;
	while (1)
	{
		if (!select_wrapper(sockfd, &st_select, s_data))
			return (FALSE);
	}
}
