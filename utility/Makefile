# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 12:04:58 by vwatrelo          #+#    #+#              #
#    Updated: 2014/06/26 15:38:16 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
LIBFT_PATH=../libft
FLAGS=-Wall -Wextra -Werror -O3
NAME=libutils.a
INCLUDES=-I includes -I $(LIBFT_PATH)/includes -I ../includes -I ../circular_buffer/includes
LIB=-L./$(LIBFT_PATH) -lft_core

SRC=client_utils.c \
	params.c \
	get_numeric_response.c \
	str_utils.c

OBJ=$(SRC:.c=.o)

.SILENT:
all: $(NAME)
$(NAME): $(OBJ)
	ar -q $(NAME) $^ 
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

.PHONY: clean fclean all re

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
