#include "fn_num_resp/fn_loggin.h"

void		check_if_all(t_data *data)
{
	int		i;
	char	*msg;

	i = 0;
	while (i < 4)
	{
		if (data->logged.get_num_resp[i] == FALSE)
			return ;
		++i;
	}
	data->is_logged = TRUE;
	if ((msg = ft_strdup(MSG_SUCCESS)) == NULL)
		return ;
	push_back_circular_buffer(data->display_out, msg);
}

void		push_msg(const char *msg, t_data *data)
{
	int			size_msg;
	const char	*content;
	char		*res_msg;

	size_msg = ft_strlen(msg);
	if (size_msg <= 1)
		return ;
	content = msg + 1;
	if ((res_msg = ft_strdup(content)) == NULL)
		return ;
	res_msg[size_msg - 3] = '\0';
	push_back_circular_buffer(data->display_out, res_msg);
}

int				fn_462(t_num_resp_param *param, t_data *data)
{
	(void)param;
	(void)data;
	return (1);
}
