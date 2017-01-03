#include "client_const_global.h"

const t_stdin_map	g_str_to_enum_stdin[] =
{
	{"nick", nick_fn}
};

const size_t	g_str_to_enum_stdin_size =
sizeof(g_str_to_enum_stdin) / sizeof(t_stdin_map);
