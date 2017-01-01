#ifndef SEND_SUCCESS_LOGIN_H
# define SEND_SUCCESS_LOGIN_H

# include "struct.h"
# include "get_numeric_response.h"

#define START_HOST_MSG "Your host is "
#define END_HOST_MSG ", running 42 irc server"

void	send_success_login(t_client *client);

#endif
