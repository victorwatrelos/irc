#ifndef CIRCULAR_BUFFER_H
# define CIRCULAR_BUFFER_H

# define C_BUFF_SUCCESS (1)
# define C_BUFF_NOT_ENOUGH_PLACE (-1)

# include <stddef.h>
# include <libft.h>

typedef void	t_circ_buff;

t_circ_buff		*new_circular_buffer(size_t size);
void			*pop_front_circular_buffer(t_circ_buff *p_buff);
int				push_back_circular_buffer(t_circ_buff *p_buff, void *elem);

#endif
