/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:08:39 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:08:44 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_BUFFER_H
# define CIRCULAR_BUFFER_H

# define C_BUFF_SUCCESS (1)
# define C_BUFF_NOT_ENOUGH_PLACE (-1)

# include <stddef.h>
# include <libft.h>

typedef void	t_circ_buff;

t_circ_buff		*new_circular_buffer(size_t size);
void			delete_circular_buffer(t_circ_buff *p_buff);
void			*pop_front_circular_buffer(t_circ_buff *p_buff);
int				push_back_circular_buffer(t_circ_buff *p_buff, void *elem);
int				push_front_circular_buffer(t_circ_buff *p_buff, void *elem);
size_t			get_size_circular_buffer(t_circ_buff *p_buff);

#endif
