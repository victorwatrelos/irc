#include "add_cmd.h"

void		add_cmd(t_cat_cmd *st_cat_cmd, t_data *data)
{
	if (!read_num_resp(st_cat_cmd->curr_cmd, data))
		printf("%s not recognize\n", st_cat_cmd->curr_cmd);
}
