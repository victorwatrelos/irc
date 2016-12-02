# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 12:04:58 by vwatrelo          #+#    #+#              #
#    Updated: 2014/06/26 15:37:51 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Werror -O3
NAME=libft_printf.a
INCLUDES=-I ../includes
SRC=ft_printf.c

OBJ=$(SRC:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	ar -q $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
