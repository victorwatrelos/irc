#ifndef READ_CLIENT_H
# define READ_CLIENT_H

# include "struct.h"
# include "failure_exit.h"
# include <ft_printf.h>
# include "bool.h"
# include "add_cmd.h"

void		read_client(t_list *client_elem, t_command_queue *cmd, t_list **lst_client);

#endif
