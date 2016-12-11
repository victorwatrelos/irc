#ifndef STRUCT_H
# define STRUCT_H

# include "global.h"
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include "list.h"
# include "circular_buffer.h"

typedef struct	s_cmd_queue
{
	t_circ_buff	*buff_in;
	t_circ_buff	*buff_out;
}				t_cmd_queue;

typedef struct	s_data_server
{
	int			nb_client;
	t_list		*client_list;
}				t_data_server;

typedef struct	s_client
{
	int				sockfd;
	char			nickname[NICK_MAXSIZE + 1];
	char			upper_nickname[NICK_MAXSIZE + 1];
	char			curr_cmd[MAX_CMD_SIZE + 1];
	int				size_current_msg;
	char			hostname[MAX_SIZE_HOSTNAME + 1];
	char			username[MAX_SIZE_USERNAME + 1];
	char			upper_username[MAX_SIZE_USERNAME + 1];
	char			realname[MAX_SIZE_REALNAME + 1];
	char			usermode[MAX_SIZE_USERMODE + 1];
	t_data_server	*st_data;
	t_cmd_queue		cmd_queue;

}				t_client;

typedef struct	s_select
{
	fd_set		read;
	fd_set		write;
	int			new_connection;
	int			sockfd;
}				t_select;

typedef int (*t_cmd_fn)(const char *, t_client *);

typedef struct	s_cmd_map
{
	const char	cmd_str[MAX_SIZE_CMD_STR];
	t_cmd_fn	cmd_fn;
}				t_cmd_map;

#endif
