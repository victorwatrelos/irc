#include "const_global.h"

const t_cmd_map	g_str_to_enum_cmd[] =
{
	{"NICK", nick_fn},
	{"USER", user_fn},
	{"JOIN", join_fn},
	{"PRIVMSG", privmsg_fn}
};

const size_t	g_str_to_enum_cmd_size = sizeof(g_str_to_enum_cmd) / sizeof(t_cmd_map);
