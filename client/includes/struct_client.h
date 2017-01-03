#ifndef STRUCT_CLIENT_H
# define STRUCT_CLIENT_H

# include <stdint.h>
# include <circular_buffer.h>
# include <global.h>

typedef struct		s_param
{
	const char		*host;
	uint32_t		port;
}					t_param;

typedef struct		s_select
{
	fd_set			read;
	fd_set			write;
}					t_select;

typedef struct		s_client
{
	int				size_current_msg;
	char			curr_cmd[MAX_CMD_SIZE + 1];
}					t_client;

typedef struct		s_data
{
	t_client		client;
	t_circ_buff		*buff_out;	
}					t_data;

#endif
