#include <ft_printf.h>
#include "network/launch_connection.h"

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("%r./client <ip> [port]\n");
		return (1);
	}
	if (argc < 3)
		launch_connection(argv[1], 6667);
	else
		launch_connection(argv[1], ft_atoi(argv[2]));
	return (0);
}
