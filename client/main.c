/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:10:18 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:20 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "network/launch_connection.h"

int		main(int argc, char **argv)
{
	if (argc >= 2 && ft_strcmp(argv[1], "--help") == 0)
	{
		ft_printf("%r./client [hostname [port]]\n");
		return (0);
	}
	if (argc < 2)
		launch_connection(NULL, 6667);
	if (argc < 3)
		launch_connection(argv[1], 6667);
	else
		launch_connection(argv[1], ft_atoi(argv[2]));
	return (0);
}
