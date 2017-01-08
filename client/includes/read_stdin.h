#ifndef READ_STDIN_H
# define READ_STDIN_H

# include <stdio.h>
# include <bool.h>
# include <read_socket.h>
# include "struct_client.h"
# include "parser/user_cmd.h"

t_bool		read_stdin(t_data *data, const char *line);

#endif
