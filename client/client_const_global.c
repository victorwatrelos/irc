#include "client_const_global.h"

const t_stdin_map	g_str_to_enum_stdin[] =
{
	{"nick", nick_fn}
};

const size_t	g_str_to_enum_stdin_size =
sizeof(g_str_to_enum_stdin) / sizeof(t_stdin_map);

const t_num_resp_map	g_str_to_enum_num_resp[] =
{
	{"001", fn_001},
	{"002", fn_002},
	{"003", fn_003},
	{"004", fn_004}
};

const size_t	g_str_to_enum_num_resp_size =
sizeof(g_str_to_enum_num_resp) / sizeof(t_num_resp_map);
