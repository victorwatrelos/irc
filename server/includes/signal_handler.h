#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <list.h>
# include <struct.h>
# include <signal.h>

void		signal_handler(int signal);
void	exit_clean(t_data_server *p_data);

#endif
