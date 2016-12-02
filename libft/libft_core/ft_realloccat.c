/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloccat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:42:09 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/06/25 14:42:10 by vwatrelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_realloccat(char *s1, char *s2)
{
	int		size;

	size = ft_strlen(s1);
	size += ft_strlen(s2);
	s1 = realloc(s1, size + 4);
	if (s1 == NULL)
		return (NULL);
	ft_strcat(s1, s2);
	free(s2);
	return (s1);
}
