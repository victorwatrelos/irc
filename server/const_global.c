/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:07 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_global.h"

const t_cmd_map	g_str_to_enum_cmd[] =
{
	{"NICK", nick_fn},
	{"USER", user_fn},
	{"JOIN", join_fn},
	{"PRIVMSG", privmsg_fn},
	{"PART", part_fn},
	{"NAMES", names_fn}
};

const size_t	g_str_to_enum_cmd_size =
sizeof(g_str_to_enum_cmd) / sizeof(t_cmd_map);
