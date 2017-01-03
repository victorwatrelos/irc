#ifndef WRITE_CLIENT_H
# define WRITE_CLIENT_H

# include <bool.h>
# include "struct_client.h"
# include <send_to_sockfd.h>

t_bool		write_client(int sockfd, t_data *data);

#endif
