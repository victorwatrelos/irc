/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_circular_buffer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:08:39 by vwatrelo          #+#    #+#             */
/*   Updated: 2017/01/08 19:08:44 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_CIRCULAR_BUFFER_H
# define P_CIRCULAR_BUFFER_H

# include "circular_buffer.h"
# include <stddef.h>
# include <stdlib.h>

typedef struct		s_circular_buffer
{
	size_t			size;
	size_t			pos_end;
	size_t			pos_start;
	size_t			max_size;
	void			**data;
}					t_circular_buffer;

#endif
