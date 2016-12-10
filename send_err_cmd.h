#ifndef SEND_ERR_CMD_H
# define SEND_ERR_CMD_H

# include "fn/fn.h"

typedef struct	s_err_map
{
	int			err;
	const char	*msg;
	const char	*code;
}				t_err_map;

#endif
