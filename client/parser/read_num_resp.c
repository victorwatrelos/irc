#include "parser/read_num_resp.h"

static t_bool	process_msg(t_num_resp_param *params, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < g_str_to_enum_num_resp_size)
	{
		if (ft_strncmp(g_str_to_enum_num_resp[i].num_cmd, params->num, 3) == 0)
		{
			g_str_to_enum_num_resp[i].cmd_fn(params, data);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool			read_num_resp(const char *cmd, t_data *data)
{
	t_num_resp_param	params;
	int					tmp;

	tmp = jump_to_space(cmd, 0);
	params.num = jump_end_of_space(cmd, tmp) + cmd;
	params.size_num = jump_to_space(params.num, 0);
	if (params.size_num != 3)
		return (FALSE);
	params.nick = jump_end_of_space(params.num, params.size_num) + params.num;
	params.size_nick = jump_to_space(params.nick, 0);
	params.msg = jump_end_of_space(params.nick, params.size_nick) + params.nick;
	return (process_msg(&params, data));
}
