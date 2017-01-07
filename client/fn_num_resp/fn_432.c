#include "fn_num_resp/fn_resp.h"

int			fn_403(t_num_resp_param *param, t_data *data)
{
	char		*res;

	(void)param;
	if ((res = ft_strdup(MSG_403)) == NULL)
		return (FALSE);
	push_back_circular_buffer(data->display_out, res);
	return (TRUE);
}

int			fn_432(t_num_resp_param *param, t_data *data)
{
	char		*res;

	(void)param;
	if ((res = ft_strdup(MSG_432)) == NULL)
		return (FALSE);
	push_back_circular_buffer(data->display_out, res);
	return (TRUE);
}

int			fn_461(t_num_resp_param *param, t_data *data)
{
	char		*res;

	(void)param;
	if ((res = ft_strdup(MSG_461)) == NULL)
		return (FALSE);
	push_back_circular_buffer(data->display_out, res);
	return (TRUE);
}

int			fn_404(t_num_resp_param *param, t_data *data)
{
	char		*res;

	(void)param;
	if ((res = ft_strdup(MSG_404)) == NULL)
		return (FALSE);
	push_back_circular_buffer(data->display_out, res);
	return (TRUE);
}

int				fn_433(t_num_resp_param *param, t_data *data)
{
	char		*res;

	(void)param;
	if ((res = ft_strdup(MSG_433)) == NULL)
		return (FALSE);
	push_back_circular_buffer(data->display_out, res);
	return (TRUE);
}
