#ifndef PARAMS_H
# define PARAMS_H

# include "bool.h"
# include "global.h"
# include "str_utils.h"

typedef t_bool	(*t_params_lst)(const char *, void *, t_bool last);
int					params_lst(const char *param_str, t_params_lst callback,
		void *data);

typedef struct		s_p_params
{
	const char		*end_param;
	const char		*end_params;
	const char		*start_param;
	const char		*param_str;
	char			param[MAX_CMD_SIZE + 1];
	t_bool			return_now;
}					t_p_params;

#endif
