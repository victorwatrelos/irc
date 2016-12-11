#ifndef STRUCT_H
# define STRUCT_H

# include "global.h"
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include "list.h"
# include "circular_buffer.h"
# include "bool.h"

typedef struct	s_cmd_queue
{
	t_circ_buff	*buff_out;
}				t_cmd_queue;

typedef struct	s_data_server
{
	int			nb_client;
	t_list		*client_list;
	t_list		*channel_list;
}				t_data_server;

typedef struct	s_send_buff
{
	char		buff[SIZE_SEND_BUFF];
	size_t		start;
	size_t		end;
}				t_send_buff;

typedef struct	s_channel
{
	char		name[MAX_SIZE_CHANNEL_NAME + 1];
	char		upper_name[MAX_SIZE_CHANNEL_NAME + 1];
	t_list		*client_lst;
}				t_channel;

typedef struct	s_client
{
	t_bool			nick_set;
	t_bool			username_set;
	t_bool			logged_in;
	char			nickname[NICK_MAXSIZE + 1];
	char			upper_nickname[NICK_MAXSIZE + 1];
	char			curr_cmd[MAX_CMD_SIZE + 1];
	char			hostname[MAX_SIZE_HOSTNAME + 1];
	char			username[MAX_SIZE_USERNAME + 1];
	char			upper_username[MAX_SIZE_USERNAME + 1];
	char			realname[MAX_SIZE_REALNAME + 1];
	char			usermode[MAX_SIZE_USERMODE + 1];
	int				sockfd;
	int				size_current_msg;
	t_data_server	*st_data;
	t_cmd_queue		cmd_queue;
	t_send_buff		send_buff;

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
