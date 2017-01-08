/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_H
# define USER_H

# include "global.h"
# include "struct.h"
# include "str_utils.h"
# include "client_utils.h"
# include "fn/fn.h"
# include "send_success_login.h"

typedef struct	s_client_param
{
	char		*user;
	char		*mode;
	char		*realname;
	char		upper_username[MAX_SIZE_USERNAME + 1];
}				t_client_param;

#endif
