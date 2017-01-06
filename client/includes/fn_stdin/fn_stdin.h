#ifndef FN_STDIN_H
# define FN_STDIN_H

# include "struct_client.h"
# include <bool.h>
# include <stdio.h>
# include <str_utils.h>

# define MSG_NICK_BASE "NICK "
# define MSG_USER_BASE "USER "
# define MSG_USER_MIDDLE " 0 * "
# define MSG_JOIN_BASE "JOIN "
# define MSG_PART_BASE "PART "

int		nick_fn(const char *cmd, t_data *data);
int		join_fn(const char *params, t_data *data);
int		leave_fn(const char *params, t_data *data);

#endif
