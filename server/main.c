#include "network/init_server.h"
# include "network/server.h"
#include "libft.h"

int main(int argc, char **argv)
{
	int		sockfd;
	int		port;
	t_data_server	d_server;

	port = 4241;
	ft_bzero(&d_server, sizeof(d_server));
	if (argc > 1)
	{
		port = ft_atoi(argv[1]);
	}
	if (!init_serv(&sockfd, 4241))
	{
		ft_putstr("Unable to open server on port 4241\n");
		return (1);
	}
	launch_select(sockfd, &d_server);
	return (0);
}
