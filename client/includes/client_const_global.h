#ifndef CLIENT_CONST_GLOBAL_H
# define CLIENT_CONST_GLOBAL_H

# include "fn_stdin/fn_stdin.h"
# include "struct_client.h"

typedef int (*t_stdin_fn)(const char *, t_data *);

typedef struct	s_stdin_map
{
	const char	cmd_str[MAX_SIZE_CMD_STR];
	t_stdin_fn	cmd_fn;
}				t_stdin_map;

extern const t_stdin_map g_str_to_enum_stdin[];
extern const size_t	g_str_to_enum_stdin_size;

#endif
