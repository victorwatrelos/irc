#include "network/init_server.h"
# include "network/server.h"
#include "libft.h"

int		test_valid(const char *av)
{
	int		i;
	int		port;

	i = ft_strlen(av) - 1;
	while (i >= 0)
	{
		if (!ft_isdigit(av[i]))
		{
			return (-1);
		}
		--i;
	}
	port = ft_atoi(av);
	if (port > 0xFFFF || port < 0)
		return (-1);
	return (port);
}

int		parse_arg(int ac, const char **av)
{
	int		port;
	int		tmp;

	port = 6667;
	if (ac > 1)
	{
		tmp = test_valid(av[1]);
		if (tmp >= 0)
			return (tmp);
		else
			ft_printf("%rPort must be between 0 - %d and composed of digit\n", 0xFFFF);
	}
	ft_printf("%rServer starting on default port %d\n", port);
	return (port);
}

int main(int argc, const char **argv)
{
	int		sockfd;
	int		port;
	t_data_server	d_server;

	port = parse_arg(argc, argv);
	ft_bzero(&d_server, sizeof(d_server));
	if (!init_serv(&sockfd, port))
	{
		ft_printf("%rUnable to open server on port %d\n", port);
		return (1);
	}
	launch_select(sockfd, &d_server);
	return (0);
}
