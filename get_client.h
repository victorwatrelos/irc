#ifndef GET_CLIENT_H
# define GET_CLIENT_H

# include "struct.h"
# include "failure_exit.h"
# include "libft.h"
# include "global.h"

t_client		*get_client(int fd, t_data_server *st_data);

#endif
