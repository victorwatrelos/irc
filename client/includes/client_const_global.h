/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_const_global.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:17 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_CONST_GLOBAL_H
# define CLIENT_CONST_GLOBAL_H

# include "fn_stdin/fn_stdin.h"
# include "struct_client.h"
# include "fn_num_resp/fn_loggin.h"
# include "fn_num_resp/fn_resp.h"
# define MAX_SIZE_NUM 4

typedef int	(*t_stdin_fn)(const char *, t_data *);

typedef struct	s_stdin_map
{
	const char	cmd_str[MAX_SIZE_CMD_STR];
	t_stdin_fn	cmd_fn;
	t_bool		need_nick;
	t_bool		need_connect;
}				t_stdin_map;

extern const t_stdin_map g_str_to_enum_stdin[];
extern const size_t	g_str_to_enum_stdin_size;

typedef int	(*t_num_resp_fn)(t_num_resp_param *, t_data *);

typedef struct	s_num_resp_map
{
	const char		num_cmd[MAX_SIZE_NUM];
	t_num_resp_fn	cmd_fn;
}				t_num_resp_map;

extern const t_num_resp_map g_str_to_enum_num_resp[];
extern const size_t	g_str_to_enum_num_resp_size;

typedef int	(*t_resp_fn)(t_num_resp_param *, t_data *);

typedef struct	s_resp_map
{
	const char		num_cmd[MAX_SIZE_NUM];
	t_resp_fn		cmd_fn;
}				t_resp_map;

extern const t_resp_map g_str_to_enum_resp[];
extern const size_t	g_str_to_enum_resp_size;

#endif
