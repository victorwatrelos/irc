#ifndef READ_CLIENT_H
# define READ_CLIENT_H

# include <ft_printf.h>
# include <bool.h>
# include "struct_client.h"
# include "add_cmd.h"
# include <read_socket.h>

t_bool			read_client(int sockfd, t_data *data);

#endif
