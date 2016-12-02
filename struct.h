#ifndef STRUCT_H
# define STRUCT_H

# include "global.h"
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include "list.h"

typedef struct	s_client
{
	int			sockfd;
	char		nickname[NICK_MAXSIZE + 1];
}				t_client;

typedef struct	s_select
{
	fd_set		read;
	fd_set		write;
	int			new_connection;
	int			sockfd;
}				t_select;

typedef struct	s_data_server
{
	int			nb_client;
	t_list		*client_list;
}				t_data_server;



#endif
