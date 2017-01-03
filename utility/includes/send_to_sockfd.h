#ifndef SEND_TO_SOCKFD_H
# define SEND_TO_SOCKFD_H

# include <circular_buffer.h>
# include <struct_global.h>

int			send_to_sockfd(int sockfd, t_send_buff *buff, t_circ_buff *circ_buff_out);

#endif
