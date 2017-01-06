#include "read_stdin.h"

static void	stdin_cmd(t_cat_cmd *stdin_cat_cmd, t_data *data)
{
	parse_cmd(data, stdin_cat_cmd->curr_cmd);
}

t_bool		read_stdin(t_data *data)
{
	data->stdin_cat_cmd.callback = (t_callback_cat_cmd)stdin_cmd;
	data->stdin_cat_cmd.param_callback = (void *)data;
	return (read_socket(0, &(data->stdin_cat_cmd)));
}
