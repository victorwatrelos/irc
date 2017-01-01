#ifndef PARAMS_H
# define PARAMS_H

# include "bool.h"
# include "global.h"
# include "str_utils.h"

typedef t_bool	(*t_params_lst)(const char *, void *, t_bool last);
int		params_lst(const char *param_str, t_params_lst callback, void *data);

#endif
