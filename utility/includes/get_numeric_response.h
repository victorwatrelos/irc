/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numeric_response.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:09:58 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:02 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NUMERIC_RESPONSE_H
# define GET_NUMERIC_RESPONSE_H

# include <libft.h>
# include "bool.h"
# define HOSTNAME 0
# define CODE 1
# define NICKNAME 2
# define MSG 3

char	*get_numeric_response(const char *hostname, const char *code,
		const char *nickname, const char *msg);
char	*get_numeric_response_custom(const char *data[], t_bool add_point);

#endif
