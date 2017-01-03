#ifndef READ_CLIENT_H
# define READ_CLIENT_H

# include "struct.h"
# include "errors/failure_exit.h"
# include <ft_printf.h>
# include "bool.h"
# include "add_cmd.h"
# include "read_socket.h"

t_bool		read_client(t_list *client_elem, t_list **lst_client);

#endif
