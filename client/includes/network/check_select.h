#ifndef CHECK_SELECT_H
# define CHECK_SELECT_H

# include <sys/select.h>
# include "struct_client.h"
# include "read_client.h"
# include "global_client.h"
# include "read_stdin.h"
# include "write_client.h"

int		check_select(t_select *st_select, int sockfd, t_data *data);

#endif
