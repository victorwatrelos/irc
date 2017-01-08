/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_nosuchchannel.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_NOSUCHCHANNEL_H
# define SEND_NOSUCHCHANNEL_H

# include "struct.h"
# include "get_numeric_response.h"

# define NOSUCHCHANNEL	":No such channel"

void	send_nosuchchannel(const char *chan_name, t_client *client);

#endif
