#ifndef LAUNCH_CONNECTION_H
# define LAUNCH_CONNECTION_H

# include <global.h>
# include <ft_printf.h>
# include <bool.h>
# include "struct_client.h"
# include "network/check_select.h"
# include "network/connect_to_server.h"
# include "errors/server_disconnect.h"

int		launch_connection(const char *ip, int32_t port);

#endif
