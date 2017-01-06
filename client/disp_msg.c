#include "disp_msg.h"

void	disp_msg(t_data *data)
{
	char	*msg;

	while (get_size_circular_buffer(data->display_out) > 0)
	{
		msg = pop_front_circular_buffer(data->display_out);
		printf("User msg: %s\n", msg);
	}
}
