#include "p_circular_buffer.h"

t_circ_buff	*new_circular_buffer(size_t size)
{
	void				**data;
	t_circular_buffer	*buff;
	
	if ((data = malloc(sizeof(void *) * size)) == NULL)
		return (NULL);
	if ((buff = malloc(sizeof(t_circular_buffer))) == NULL)
		return (NULL);
	buff->data = data;
	ft_bzero(buff, sizeof(t_circular_buffer));
	return (buff);
}

int		push_back_circular_buffer(t_circ_buff *p_buff, void *elem)
{
	t_circular_buffer	*buff;

	buff = p_buff;
	if (buff->size + 1 >= buff->max_size)
		return (C_BUFF_NOT_ENOUGH_PLACE);
	buff->data[buff->pos_end] = elem;
	buff->pos_end = (buff->pos_end + 1) % buff->max_size;
	buff->size++;
	return (C_BUFF_SUCCESS);
}

void	*pop_front_circular_buffer(t_circ_buff *p_buff)
{
	t_circular_buffer	*buff;
	void				*ret;

	buff = p_buff;
	if (buff->size == 0)
		return (NULL);
	ret = buff->data[buff->pos_start];
	if (buff->pos_start == 0)
		buff->pos_start = buff->max_size - 1;
	else
		buff->pos_start = (buff->pos_start - 1);
	buff->size--;
	return (ret);
}
