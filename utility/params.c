#include "params.h"

static int	browse_param(t_p_params *p,
		t_params_lst callback, void *data)
{
	int		i;

	printf("browse param with: %s\n", p->param_str);
	i = 0;
	while (p->param_str < p->end_params)
	{
		if (*(p->param_str) == ',')
		{
			p->end_param = p->param_str;
			ft_strncpy(p->param, p->start_param, p->end_param - p->start_param);
			p->param[p->end_param - p->start_param] = '\0';
			p->param[MAX_CMD_SIZE] = '\0';
			printf("callback on: %s\n", p->param);
			if (!callback(p->param, data, FALSE))
			{
				p->return_now = TRUE;
				return (i + 1);
			}
			i++;
			p->start_param = p->end_param + 1;
		}
		(p->param_str)++;
	}
	p->return_now = FALSE;
	return (i);
}

int			params_lst(const char *param_str, t_params_lst callback, void *data)
{
	int			i;
	t_p_params	p;

	printf("param_str: %s\n", param_str);
	p.param_str = param_str + jump_end_of_space(param_str, 0);
	p.start_param = p.param_str;
	p.end_params = p.param_str + jump_to_space(p.param_str, 0);
	printf("end param: %p\n", p.end_params);
	printf("start_Param: %p\n", p.start_param);
	if (p.end_params == p.start_param)
		return (0);
	printf("here\n");
	i = browse_param(&p, callback, data);
	if (p.return_now)
		return (i);
	printf("end\n");
	ft_strncpy(p.param, p.start_param, p.param_str - p.start_param);
	p.param[p.param_str - p.start_param] = '\0';
	callback(p.param, data, TRUE);
	return (i + 1);
}
