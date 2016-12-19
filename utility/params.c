#include "params.h"

int		params_lst(const char *param_str, t_params_lst callback, void *data)
{
	const char	*end_param;
	const char	*end_params;
	const char	*start_param;
	char		param[MAX_CMD_SIZE + 1];
	int			i;

	param_str = param_str + jump_end_of_space(param_str, 0);
	end_params = param_str + jump_to_space(param_str, 0);
	start_param = param_str;
	if (end_params == start_param)
		return (0);
	i = 0;
	while (param_str < end_params)
	{
		if (*param_str == ',')
		{
			end_param = param_str;
			ft_strncpy(param, start_param, end_param - start_param);
			param[end_param - start_param] = '\0';
			param[MAX_CMD_SIZE] = '\0';
			if (!callback(param, data, FALSE))
				return (i + 1);
			i++;
			start_param = end_param + 1;
		}
		param_str++;
	}
	ft_strncpy(param, start_param, param_str - start_param);
	param[param_str - start_param] = '\0';
	callback(param, data, TRUE);
	return (i + 1);
}
