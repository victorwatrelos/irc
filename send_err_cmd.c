#include "send_err_cmd.h"

const t_err_map		g_err_map[] = 
{
	{NICK_NO_PARAM, "Erroneous nickname", "432"},
	{NICK_TOO_LONG, "Erroneous nickname", "432"}
};

void		send_err_cmd(int err, t_client *client)
{
	int		i;

	i = 0;
	printf("sizeof: %lu\n", sizeof(g_err_map));
	while (i < 2)
	{
		i++;
	}
}
