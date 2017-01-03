#ifndef STRUCT_CLIENT_H
# define STRUCT_CLIENT_H

# include <stdint.h>
# include <circular_buffer.h>
# include <global.h>
# include <struct_global.h>

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

typedef struct		s_data
{
	t_circ_buff		*buff_out;	
	const char		*host;
	int32_t			port;
	int				sockfd;
	t_cat_cmd		st_cat_cmd;
}					t_data;

#endif
