#include "send_to_sockfd.h"

static void	write_on_circular_buffer(t_send_buff *buff, const char *str)
{
	size_t		size_str;
	size_t		disp_size;

	size_str = ft_strlen(str);
	disp_size = SIZE_SEND_BUFF - buff->end;
	if (disp_size >= size_str)
	{
		ft_strncpy(buff->buff, str, size_str);
		buff->end += size_str;
		return ;
	}
	ft_strncpy(buff->buff, str, disp_size);
	buff->end = 0;
	write_on_circular_buffer(buff, str + disp_size);
}

int			send_to_sockfd(int sockfd, t_send_buff *buff,
		t_circ_buff *circ_buff_out)
{
	char		*cmd;
	int			ret;

	if (buff->start == buff->end)
	{
		cmd = pop_front_circular_buffer(circ_buff_out);
		if (cmd == NULL)
			return (0);
		write_on_circular_buffer(buff, cmd);
		free(cmd);
	}
	if (buff->start > buff->end)
	{
		ret = write(sockfd, buff->buff, SIZE_SEND_BUFF - buff->start);
		if (ret <= 0)
			return (-1);
		buff->start = (buff->start + ret) % SIZE_SEND_BUFF;
		return (1);
	}
	if ((ret = write(sockfd, buff->buff, buff->end - buff->start)) <= 0)
		return (-1);
	buff->start = buff->start + ret;
	return (1);
}
