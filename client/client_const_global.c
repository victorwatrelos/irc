#include "client_const_global.h"

const t_stdin_map	g_str_to_enum_stdin[] =
{
	{"connect", connect_fn, FALSE, FALSE},
	{"join", join_fn, TRUE, TRUE},
	{"nick", nick_fn, FALSE, TRUE},
	{"leave", leave_fn, TRUE, TRUE},
	{"msg", msg_fn, TRUE, TRUE},
	{"who", who_fn, TRUE, TRUE}
};

const size_t	g_str_to_enum_stdin_size =
sizeof(g_str_to_enum_stdin) / sizeof(t_stdin_map);

const t_num_resp_map	g_str_to_enum_num_resp[] =
{
	{"001", fn_001},
	{"002", fn_002},
	{"003", fn_003},
	{"004", fn_004},
	{"353", fn_353},
	{"366", fn_366},
	{"432", fn_432},
	{"404", fn_404},
	{"461", fn_461},
	{"403", fn_403},
	{"433", fn_433},
	{"462", fn_462}
};

const size_t	g_str_to_enum_num_resp_size =
sizeof(g_str_to_enum_num_resp) / sizeof(t_num_resp_map);

const t_resp_map	g_str_to_enum_resp[] =
{
	{"JOIN", fn_join_resp},
	{"PART", fn_part_resp}
};

const size_t	g_str_to_enum_resp_size =
sizeof(g_str_to_enum_resp) / sizeof(t_resp_map);
