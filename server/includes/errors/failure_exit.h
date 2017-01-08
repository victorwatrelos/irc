/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure_exit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:11:08 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:11:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAILURE_EXIT_H
# define FAILURE_EXIT_H

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <list.h>
# include "struct.h"
# include "channel.h"

void	failure_exit(char const *msg);
void	failure_exit_client(t_list *client, t_list **lst_client);

#endif
