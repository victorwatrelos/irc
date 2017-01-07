# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 12:04:58 by vwatrelo          #+#    #+#              #
#    Updated: 2014/06/26 15:37:06 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Werror
NAME=libft.a
INCLUDES=-I includes/
LIB=ft_printf/libft_printf.a \
	libft_core/libft_core.a \
	list/libft_list.a \

.PHONY: clean fclean all re
.SILENT:

all: $(NAME)

$(NAME): libft

libft: $(LIB)
	$(foreach var, $(LIB), cp $(var) $(notdir $(var)) ;)

ft_printf/libft_printf.a:
	(cd ft_printf && $(MAKE))

list/libft_list.a:
	(cd list && $(MAKE))

libft_core/libft_core.a:
	(cd libft_core && $(MAKE))

clean:
	(cd libft_core && $(MAKE) clean)
	(cd ft_printf && $(MAKE) clean)
	(cd list && $(MAKE) clean)

fclean: clean
	(cd libft_core && $(MAKE) fclean)
	(cd ft_printf && $(MAKE) fclean)
	(cd list && $(MAKE) fclean)
	rm -f $(notdir $(LIB))

re: fclean all
