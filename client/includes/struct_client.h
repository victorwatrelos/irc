#ifndef STRUCT_CLIENT_H
# define STRUCT_CLIENT_H

# include <stdint.h>
# include <circular_buffer.h>
# include <global.h>
# include <struct_global.h>
# include <bool.h>

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

typedef struct		s_logged
{
	t_bool			get_num_resp[4];
}					t_logged;

typedef struct	s_num_resp_param
{
	const char	*host;
	int			size_host;
	const char	*num;
	int			size_num;
	const char	*nick;
	int			size_nick;
	const char	*msg;
}				t_num_resp_param;

typedef struct		s_data
{
	t_circ_buff		*buff_out;	
	t_circ_buff		*display_out;	
	const char		*host;
	int32_t			port;
	int				sockfd;
	t_cat_cmd		st_cat_cmd;
	t_cat_cmd		stdin_cat_cmd;
	t_send_buff		send_buff;
	t_bool			is_connected;
	t_bool			is_logged;
	t_logged		logged;
}					t_data;

#endif
