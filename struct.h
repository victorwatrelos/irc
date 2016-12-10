#ifndef STRUCT_H
# define STRUCT_H

# include "global.h"
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include "list.h"
# include "circular_buffer.h"

enum eCmd { NICK, JOIN };

typedef struct	s_cmd_map
{
	const char	cmd_str[MAX_SIZE_CMD_STR];
	enum eCmd	cmd_id;
}				t_cmd_map;

typedef struct	s_cmd
{
	enum eCmd	cmd_type;	
	//TODO param cmd
	//TODO fn pointer
}				t_cmd;

typedef struct	s_cmd_queue
{
	t_circ_buff	*buff_in;
	t_circ_buff	*buff_out;
}				t_cmd_queue;

typedef struct	s_client
{
	int			sockfd;
	char		nickname[NICK_MAXSIZE + 1];
	char		curr_cmd[MAX_CMD_SIZE + 1];
	int			size_current_msg;
	t_cmd_queue	cmd_queue;

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
	int				nb_client;
	t_list			*client_list;
}				t_data_server;



#endif
