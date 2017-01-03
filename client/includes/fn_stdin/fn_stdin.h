#ifndef FN_STDIN_H
# define FN_STDIN_H

# include "struct_client.h"
# include <bool.h>
# include <stdio.h>

# define MSG_NICK_BASE "NICK "
# define MSG_USER_BASE "USER "
# define MSG_USER_MIDDLE " 0 * "

int		nick_fn(const char *cmd, t_data *data);

#endif
