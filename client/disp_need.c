#include "disp_need.h"

void	disp_need_connect(t_data *data)
{
	char	*res;

	if ((res = ft_strdup(MSG_DISP_NEED_CONNECT)) == NULL)
		return ;
	push_back_circular_buffer(data->display_out, res);
}

void	disp_need_nick(t_data *data)
{
	char	*res;

	if ((res = ft_strdup(MSG_DISP_NEED_NICK)) == NULL)
		return ;
	push_back_circular_buffer(data->display_out, res);
}
