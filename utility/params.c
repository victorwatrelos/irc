#include "params.h"

static int	browse_param(t_p_params *p, const char *param_str,
		t_params_lst callback, void *data)
{
	int		i;

	i = 0;
	while (param_str < p->end_params)
	{
		if (*param_str == ',')
		{
			p->end_param = param_str;
			ft_strncpy(p->param, p->start_param, p->end_param - p->start_param);
			p->param[p->end_param - p->start_param] = '\0';
			p->param[MAX_CMD_SIZE] = '\0';
			if (!callback(p->param, data, FALSE))
			{
				p->return_now = TRUE;
				return (i + 1);
			}
			i++;
			p->start_param = p->end_param + 1;
		}
		param_str++;
	}
	p->return_now = FALSE;
	return (i);
}

int			params_lst(const char *param_str, t_params_lst callback, void *data)
{
	int			i;
	t_p_params	p;

	param_str = param_str + jump_end_of_space(param_str, 0);
	p.end_params = param_str + jump_to_space(param_str, 0);
	p.start_param = param_str;
	if (p.end_params == p.start_param)
		return (0);
	i = browse_param(&p, param_str, callback, data);
	if (p.return_now)
		return (i);
	ft_strncpy(p.param, p.start_param, param_str - p.start_param);
	p.param[param_str - p.start_param] = '\0';
	callback(p.param, data, TRUE);
	return (i + 1);
}
