/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_success_login.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:11 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_SUCCESS_LOGIN_H
# define SEND_SUCCESS_LOGIN_H

# include "struct.h"
# include "get_numeric_response.h"

# define START_HOST_MSG "Your host is "
# define END_HOST_MSG ", running 42 irc server"

void	send_success_login(t_client *client);

#endif
