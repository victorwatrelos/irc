#ifndef FN_H
# define FN_H

# define NICK_NO_PARAM (-1)
# define NICK_TOO_LONG (-2)
# define NICK_ALREADY_TAKEN (-3)
# define NICK_BAD_CHAR (-4)
# define ERR_NEEDMOREPARAMS (-5)
# define ERR_ALREADYREGISTRED (-6)
# define ERR_NOSUCHCHANNEL (-7)

# define CMD_SUCCESS (1)
# define UNEXPECTED_ERROR (2)

# include "struct.h"

int		nick_fn(const char *param_str, t_client *client);
int		user_fn(const char *param_str, t_client *client);
int		join_fn(const char *param_str, t_client *client);

#endif
