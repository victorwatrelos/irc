/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:09:59 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:10:02 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "bool.h"
# include <libft.h>
# define LIST_SPACE_CHAR " \t\r\n"

int			jump_end_of_space(const char *str, int pos);
int			jump_to_space(const char *str, int pos);
void		to_upper_rfc(char *str);
const char	*next_param(const char *str, int *size, const char **next);
char		*ft_strndup(const char *str, size_t size);

#endif
