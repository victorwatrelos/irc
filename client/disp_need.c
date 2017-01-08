/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_need.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disp_need.h"

void	disp_need_connect(t_data *data)
{
	char	*res;

	if ((res = ft_strdup(MSG_DISP_NEED_CONNECT)) == NULL)
		return ;
	push_back_circular_buffer(data->display_out, res);
}

void	disp_need_nick(t_data *data)
{
	char	*res;

	if ((res = ft_strdup(MSG_DISP_NEED_NICK)) == NULL)
		return ;
	push_back_circular_buffer(data->display_out, res);
}
