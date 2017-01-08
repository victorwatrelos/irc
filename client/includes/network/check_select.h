#ifndef CHECK_SELECT_H
# define CHECK_SELECT_H

# include <sys/select.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "struct_client.h"
# include "read_client.h"
# include "global_client.h"
# include "read_stdin.h"
# include "write_client.h"

t_data	*set_data(t_data *p_data);
void	callback_readline(char *line);
int		check_select(t_select *st_select, int sockfd, t_data *data);

#endif
