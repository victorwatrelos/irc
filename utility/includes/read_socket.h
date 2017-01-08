/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_socket.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:09:59 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:02 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_SOCKET_H
# define READ_SOCKET_H

# include <stdlib.h>
# include <libft.h>
# include <ft_printf.h>
# include <bool.h>
# include <struct_global.h>

t_bool			read_socket(int sockfd, t_cat_cmd *st_cat_cmd);

#endif
